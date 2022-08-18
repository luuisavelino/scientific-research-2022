FROM influxdb:1.8.3

EXPOSE 8086

RUN /etc/init.d/influxdb start && \
    influx -execute "CREATE DATABASE sensor" && \
    influx -execute "CREATE USER telegraf WITH PASSWORD 'telegraf@' WITH ALL PRIVILEGES;"
