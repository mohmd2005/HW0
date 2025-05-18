#!/bin/bash

readarray -t urls < <(
  wget -q -O - "https://www.ynetnews.com/category/3082" |  grep -oE 'https://www\.ynetnews\.com/article/[A-Za-z0-9]+' | uniq
)

declare -A seen
unique_urls=()

for url in "${urls[@]}"; do
	if [[ -z "${seen[$url]}" ]]; then
		unique_urls+=("$url")
		seen[$url]=1
	fi
done

echo "${#unique_urls[@]}"

for url in "${unique_urls[@]}"; do
	page=$(wget -q -O - "$url")
	N=$(printf "%s\n" "$page"|grep -o Netanyahu |wc -l)
	G=$(printf "%s\n" "$page"|grep -o Gantz |wc -l)
	B=$(printf "%s\n" "$page"|grep -o Bennett |wc -l)
	P=$(printf "%s\n" "$page"|grep -o Peretz |wc -l)	
	if [[ $N -eq 0 && $G -eq 0 && $B -eq 0 && $P -eq 0 ]]; then
 		echo "$url, -"
	else
  		echo "$url, Netanyahu, $N, Gantz, $G, Bennett, $B, Peretz, $P"
	fi
done


