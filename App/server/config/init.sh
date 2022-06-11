#!/bin/bash

docker container exec influxdb influx -execute "CREATE USER "admin" WITH PASSWORD 'admin' WITH ALL PRIVILEGES;"
docker container exec influxdb influx -execute "CREATE USER "telegraf" WITH PASSWORD 'telegraf@' WITH ALL PRIVILEGES;"
docker container exec influxdb influx -execute "CREATE USER "grafana" WITH PASSWORD 'grafana@' WITH ALL PRIVILEGES;"
docker container exec influxdb influx -execute "CREATE DATABASE "sensor";"
