#! /bin/bash

num=$(printf "$#")
args=$(echo "$@")
vec=$(echo "vector")
map=$(echo "map")

if [ "$num" = "0" -o "$args" = "$vec" ]
	then
	./vector/grademe.sh
fi

if [ "$num" = "0" -o "$args" = "$map" ]
	then
		./map/grademe.sh
fi