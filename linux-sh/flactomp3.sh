#!/bin/bash

for file in *.flac; do ffmpeg -i "$file" -aq:v 1 -map_metadata 0 -id3v2_version 3 "${file%.flac}.mp3"; done