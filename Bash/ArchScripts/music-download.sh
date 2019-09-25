#!/bin/bash

pgrep -x dunst >/dev/null && notify-send "Começando Download de " $1 ;
youtube-dl -x --audio-format mp3 -o "~/Musics/%(title)s.%(ext)s" $1 --exec ' notify-send "Download completo" "{}" && readlink -f {}'
