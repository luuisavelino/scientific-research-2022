while : ; do
    date +%s%N
    mosquitto_pub -h 34.172.56.210 -t "sensor/horario" -m "$(date +%s%N)";   

    sleep 0.01;
done