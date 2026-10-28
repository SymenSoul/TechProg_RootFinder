# Docker-образ сервера MathServer (MathEquationSolver).
# Клиент MathClient — это GUI-приложение (Qt Widgets), его запускают на своём компьютере
# и подключают к серверу в контейнере по порту 33333.
#
# Сборка:  docker build -t mathserver .
# Запуск:  docker run -d -p 33333:33333 -v mathserver-data:/data --name mathserver mathserver

# ---------- Этап 1: сборка и юнит-тесты ----------
FROM ubuntu:24.04 AS build

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
        build-essential qtbase5-dev qtbase5-dev-tools libqt5sql5-sqlite \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY MathServer       ./MathServer
COPY MathServerTests  ./MathServerTests
COPY MathClient       ./MathClient
COPY MathClientTests  ./MathClientTests

# Сборка сервера (out-of-source, чтобы не мешать исходникам)
RUN mkdir -p /build/server && cd /build/server \
 && qmake /src/MathServer/MathServer.pro && make -j"$(nproc)"

# Юнит-тесты: если хоть один тест упадёт, образ не соберётся
RUN mkdir -p /build/server-tests && cd /build/server-tests \
 && qmake /src/MathServerTests/MathServerTests.pro && make -j"$(nproc)" && ./MathServerTests \
 && mkdir -p /build/client-tests && cd /build/client-tests \
 && qmake /src/MathClientTests/MathClientTests.pro && make -j"$(nproc)" && ./MathClientTests

# ---------- Этап 2: лёгкий образ только для запуска ----------
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -y --no-install-recommends libqt5network5t64 libqt5sql5t64 libqt5sql5-sqlite \
 && rm -rf /var/lib/apt/lists/*

COPY --from=build /build/server/MathServer /usr/local/bin/MathServer

# Сервер создаёт mathserver.db в текущем каталоге — храним его в томе /data,
# чтобы пользователи и история не пропадали при пересоздании контейнера.
WORKDIR /data
VOLUME ["/data"]

EXPOSE 33333
CMD ["MathServer"]
