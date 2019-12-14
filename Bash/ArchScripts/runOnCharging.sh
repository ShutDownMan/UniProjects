#!/bin/bash

chargingTestDelay=5

chargingScripts="/home/jarvis/.local/bin/statusbar/charging_scripts"


procs=()
export CHARGING="false"

while true; do
	status=$(cat /sys/class/power_supply/BAT1/status)

	# test if charging
	if [[ "$status" == "Charging" || "$status" == "Full" ]] ; then
		if [[ $CHARGING == "false" ]]; then
			echo "C"

			# sleep for a bit
			sleep $chargingTestDelay
			status=$(cat /sys/class/power_supply/BAT1/status)

			# test if charging again
			if [[ "$status" == "Charging" || "$status" == "Full" ]]; then
				espeak "Notebook status: charging"
				export CHARGING="true"
				# for each script in chargingScripts
				for f in $chargingScripts/*.sh; do
					# run in backgroud and save PUID
					"$f" &
					procs+=("$!")
					sleep 3
				done
			fi
		fi
	else
		if [[ $CHARGING == "true" ]]; then
			echo "D"

			# sleep for a bit
			sleep $chargingTestDelay
			status=$(cat /sys/class/power_supply/BAT1/status)

			if [[ "$status" == "Discharging" ]]; then
				espeak "Notebook status: discharging"
				export CHARGING="false"
				# for each process UID
				for proc in ${procs[*]}; do
					echo $procs
					# kill it
					kill "$proc"
					echo "$proc has been terminated"
				done
				procs=()

			fi		
		fi
	fi

	sleep 1      # polling interval
done