#! /bin/bash

# Vector

printf "\x1B[35m"
printf "            __________      ___                                      \n"
printf "           -\\         \-_  /  /\ Stack like books ;)                 \n"
printf "            \___________\\ /__/  \       _____ _             _        \n"
printf "            \/***********\\   \   \     / ____| |           | |       \n"
printf "           _-\***********/-\  \   \   | (___ | |_ __ _  ___| | __    \n"
printf "          /***********\//   \  \  /    \___ \| __/ _  |/ __| |/ /    \n"
printf "          \**********/-      \__\/     ____) | || (_| | (__|   <     \n"
printf "                                      |_____/ \__\__,_|\___|_|\_\    \n"
printf "\n  wi_container_tester by wismith (by 42 student for 42 students)\n\x1B[0m"
printf "\n\tInfo : Compilation Errors can be found in SError.txt\n"
printf "\n\x1B[32mCompiling stack tests "

rm -rf SError.txt

c++ ./timediff.cpp -o timediff

array=(stack/construct.cpp stack/empty.cpp stack/pop.cpp stack/push.cpp)
for str in ${array[@]}; do
	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c7-)
	std=$executable"_std"
	ft=$executable"_ft"
	c++ -Wall -Werror -Wextra -std=c++98 $str -o $std
	c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft $str -o $ft 2>> SError.txt
	printf " . "
done

printf " . done"
printf "\x1B[0m\n"

for str in ${array[@]}; do

	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c7-)
	std=$executable"_std"
	ft=$executable"_ft"
	if [ -f ./$ft ]; then
		./$std > stdcmp.txt
		./$ft > ftcmp.txt
		stdcat=$(cat stdcmp.txt | grep -v "time" | grep -v "NAMESPACE")
		ftcat=$(cat ftcmp.txt | grep -v "time" | grep -v "NAMESPACE")
	
		stdtimediff=$(cat stdcmp.txt | grep -a "time" | awk '{printf $3}')
	
		fttimediff=$(cat ftcmp.txt | grep -a "time" | awk '{printf $3}')
	
		type=$(uname)
		if [ "$type" = "Linux" ]; then
			valgrind --leak-check=full ./$ft &> leakrep.txt
			err=$(cat leakrep.txt | grep -a "ERROR SUMMARY:" | awk '{printf $4}')
			val=$(cat leakrep.txt | grep -a "LEAK SUMMARY" \
				| awk '{printf $2}' && printf " " && cat leakrep.txt | grep -a "LEAK SUMMARY" | awk '{printf $3}')
		fi
	fi

	if [ -f ./$ft -a "$stdcat" = "$ftcat" ]; then
		printf "%-16s" ${ft:0:16}
		printf " : [\x1B[32m ✔️ \x1B[0m] "
		printf " |  time diff : "
		printf " ft \x1B[32m%-5s\x1B[0m /" ${fttimediff:0:5}
		printf " std \x1B[35m%-5s\x1B[0m " ${stdtimediff:0:5}
		res=$(./timediff "$fttimediff $stdtimediff")
		printf " time : "
		if [ "$res" = "0" ]; then
			printf "[\x1B[32m ✔️ \x1B[0m]"
		else
			printf "[\x1B[31m KO \x1B[0m]"
		fi

		if [ "$type" = "Linux" ]; then
			printf "  |  leaks : "
			if [ "$val" = "LEAK SUMMARY:" ]; then
				printf "[\x1B[31m KO \x1B[0m]"
			else
				printf "[\x1B[32m ✔️ \x1B[0m]"
			fi
			printf "  |  Error Summary : "
			if [ "$err" = "0" ]; then
				printf "[\x1B[32m ✔️ \x1B[0m]\n"
			else
				printf "[\x1B[31m KO \x1B[0m]\n"
			fi
		else
			printf "\n"
		fi
	else
		if [ -f ./$ft ]; then
			diff <(echo "$stdcat") <(echo "$ftcat")
		else
			printf "Compilation Error! Check MError.txt\n"
		fi
		printf "%-16s" ${ft:0:16}
		printf " : [\x1B[31m KO \x1B[0m]\n"
	fi

	rm -rf $ft
	rm -rf $std
	rm -rf ftcmp.txt
	rm -rf stdcmp.txt
done

if [ ! -s ./SError.txt ]; then
	rm -rf ./SError.txt
fi

rm -rf leakrep.txt

rm -rf timediff