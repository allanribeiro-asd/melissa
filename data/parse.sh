#BMX=(0 1)
SHT=(0 1)

help()
{
	echo "Nohing to see here"
}

export_dht()
{
	# cat 0.txt  | grep "DHT22(1)" | sed s/"\[\|\]"/" "/g | sed s/"\(\t\| \)\+"/" "/g | cut -d ' ' -f 5-6
	#
	#
	
	file="$1"
	export_dir="$2"
	for dev_id in ${BMX[@]}; do
		cat "$file" | grep "BMX($dev_id)" | sed s/"\[\|\]"/" "/g | sed s/"\(\t\| \)\+"/" "/g | cut -d ' ' -f 6,8 >> "$export_dir/$dev_id.txt"
	done

	for dev_id in ${SHT[@]}; do
		cat "$file" | grep "SHT($dev_id)" | sed s/"\[\|\]"/" "/g | sed s/"\(\t\| \)\+"/" "/g | cut -d ' ' -f 5,6 >> "$export_dir/$dev_id.txt"
	done
}

main()
{
	log_file=$1;

	if ! [[ -a "$log_file" ]]; then
		echo "File not found: $log_file" 1>&2;
		return FILE_NOT_FOUND
	fi

	export_dir="$(echo $log_file | cut -d '.' -f 1)";
	
	if ! [[ -d "$export_dir" ]]; then
		mkdir -p "$export_dir";
	fi

	export_dht "$log_file" "$export_dir";
}


# ./parse.sh log_file
# will crete a directory _log_file_ 

# Check if any arguments are received
if [ $# -eq 0 ]; then
    # No arguments received, execute the help function
    help
else
    # Arguments received, do something else
    main "$@"
fi
# for i in 05*; do for j in "$i"/*; do ./parse.sh "$j"; done; done
