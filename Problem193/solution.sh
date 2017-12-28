#cat ./file.txt | while read single_line; do

#	echo $single_line

#done

awk '/^[0-9]{3}-[0-9]{3}-[0-9]{4}$/ || /^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$/' ./file.txt
