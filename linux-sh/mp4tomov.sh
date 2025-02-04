#!/bin/bash

for file in *.mp4; do ffmpeg -i "$file" -c:v dnxhd -profile:v dnxhr_hq -pix_fmt yuv422p -c:a alac "${file%.mp4}.mov"; done