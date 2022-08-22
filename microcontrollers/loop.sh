#!/bin/bash

i=0
while [ $i -ne 1000 ]
do
        i=$(($i+1))
	mosquitto_pub -h 34.171.228.78 -t "sensor/contador" -m "$i";

	date +%s%N
done
