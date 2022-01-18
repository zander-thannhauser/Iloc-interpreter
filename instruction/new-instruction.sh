#!/bin/sh
set -ev
if [ ! -z "$1" ] && [ ! -z "$2" ]
then
	cp -rv "$1" "$2"
	sed "s/$1/$2/g" -i "$2"/*
else
	echo missing parameter!
	exit 1
fi

