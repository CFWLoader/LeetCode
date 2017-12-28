# A cleaner for cleaning non-sourcecodes file in the project.
#!/bin/sh

function check_dir()
{
	local cur_dir=$1/$2

	for sub_dir in `ls $cur_dir -a`; do

		if [[ "." == $sub_dir || ".." == $sub_dir ]]; then
			continue
		fi

		if [ ".idea" == $sub_dir ]; then

			rm -rf $cur_dir/$sub_dir

			continue

		fi

		# echo $cur_dir/$sub_dir

		if [ -d $cur_dir/$sub_dir ]; then

			# echo found a sub_dir

			#if [ ".idea" == $sub_dir ]; then

			#	echo captured .idea dir.

			#fi

			check_dir $cur_dir $sub_dir

		fi

	done
}

for sub_dir in `ls . -a`; do

	if [[ "." == $sub_dir || ".." == $sub_dir ]]; then
		# echo captured \".\" or \"..\"
		continue
	fi

	if [ -d $sub_dir ]; then

		# echo $sub_dir is a dir.
		check_dir `pwd` $sub_dir

	fi

done
