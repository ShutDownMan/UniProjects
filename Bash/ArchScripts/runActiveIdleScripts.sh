#!/bin/bash

export IDLE=false
idleAfter=10000     # consider idle after 10000 ms

idleScripts="/home/jarvis/.local/bin/statusbar/active_idle_scripts/idle"

procs=()


while true; do
	idleTimeMillis=$(getTimeIdle)
	# echo $idleTimeMillis  # just for debug purposes.

	if [[ $IDLE = false && $idleTimeMillis -gt $idleAfter ]] ; then
		echo "I"
		export IDLE=true

		# for each script in idle
		for f in $idleScripts/*.sh; do
			# run in backgroud and save PUID
			source "$f" &
			procs+=("$!")
			sleep 3
		done
	fi

	if [[ $IDLE = true && $idleTimeMillis -lt $idleAfter ]] ; then
		echo "A"
		export IDLE=false

		# for each process UID
		echo $procs
		for proc in ${procs[*]}; do
			# kill it
			kill -15 $proc
			echo "$proc has been killed"
		done
		procs=()

	fi
	sleep 1      # polling interval

done

