FROM eclipse-mosquitto

EXPOSE 1883

COPY ./config/mosquitto.conf /mosquitto/config/mosquitto.conf