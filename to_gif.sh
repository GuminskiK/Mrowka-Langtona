#!/bin/bash
# Wymagane imagemagick
dir=$1
delay=$2
prefix=$3
height=$4
width=$5
start=$6
end=$7
tmp=$(mktemp --directory)
files=$(seq ${start} ${end})
images=()
for i in $files
do
  images+=("$tmp/$i.png")
  convert -background white -fill black -font FreeMono -pointsize 12 -size ${height}x${width} -gravity center label:"$(cat "${dir}/${prefix}_${i}")" "$tmp/$i.png"
done
convert -delay $delay -loop 0 "${images[@]}" "gif.gif"