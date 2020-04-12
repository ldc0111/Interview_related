#!/bin/bash
#
#	* File      : test.sh
#	* Author    : sunowsir
#	* Mail      : sunowsir@163.com
#	* Creation  : Mon 30 Mar 2020 08:03:26 PM CST

url="http://192.168.2.82:8888/sum.html";
Time=0.01

for ((i=0;;));
do
	if curl "${url}" ; 
	then
		echo -en "\033[1;32m访问成功\033[0m | \033[1;32m访问次数\033[0m: "
		echo -e "\033[1;34m${i}\033[0m"
		((i++))
	else 
		echo -e "\033[1;31m访问失败\033[0m"
	fi

	sleep "${Time}"

done
