FROM grafana/grafana:latest

EXPOSE 3000:3000

COPY ./config/grafana.ini /etc/grafana/grafana.ini