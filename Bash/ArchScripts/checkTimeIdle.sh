#!/bin/bash

export IDLE=false
idleAfter=3000     # consider idle after 3000 ms

while true; do
  idleTimeMillis=$(getTimeIdle)
  echo $idleTimeMillis  # just for debug purposes.
  if [[ $IDLE = false && $idleTimeMillis -gt $idleAfter ]] ; then
    echo "start idle"   # or whatever command(s) you want to run...
    export IDLE=true
  fi

  if [[ $IDLE = true && $idleTimeMillis -lt $idleAfter ]] ; then
    echo "end idle"     # same here.
    export IDLE=false
  fi
  sleep 1      # polling interval

done
