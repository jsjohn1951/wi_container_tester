#! /bin/bash

# Map
printf "\n\x1B[31m"
printf	"/---------------------------------------------------------------\ \n"
printf  "|  exit      _______ *        _______   ________  ________      |\n"
printf  "|  |^|  *  / ------  |       ╱       ╲╲╱        ╲╱        ╲     |\n"
printf  "|  < > *  / / ~ * |  |      ╱        ╱╱         ╱         ╱     |\n"
printf  "|  | | * | | ^*  [   |     ╱         ╱         ╱       __╱      |\n"
printf  "|  | |___/ || |___|U |     ╲__╱__╱__╱╲___╱____╱╲______╱         |\n"
printf  "|   \_______/\_______/                                          |\n"
printf	"\---------------------------------------------------------------/ \n"
printf "\n  wi_container_tester by wismith (by 42 student for 42 students)\n\x1B[0m"
printf "\n\tInfo : Compilation Errors can be found in MError.txt\n"

printf "\n\x1B[32mCompiling map tests "

rm -rf MError.txt

c++ ./timediff.cpp -o timediff

array=(map/construct.cpp map/begin.cpp map/clear.cpp map/count.cpp map/empty.cpp map/end.cpp \
	map/equal_range.cpp map/erase.cpp map/find.cpp map/get_allocator.cpp map/insert.cpp \
	map/key_comp.cpp map/lower_bound.cpp map/elem_.cpp map/rbegin.cpp map/rend.cpp map/size.cpp \
	map/swap.cpp)
for str in ${array[@]}; do
	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c5-)
	std=$executable"_std"
	ft=$executable"_ft"
	c++ -Wall -Werror -Wextra -std=c++98 $str -o $std
	c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft $str -o $ft 2>>MError.txt
	printf " . "
done

printf " . done"
printf "\x1B[0m\n"

for str in ${array[@]}; do

	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c5-)
	std=$executable"_std"
	ft=$executable"_ft"
	if [ -f ./$ft ]; then
		./$std > stdcmp.txt
		./$ft > ftcmp.txt
		stdcat=$(cat stdcmp.txt | grep -v "time" | grep -v "NAMESPACE")
		ftcat=$(cat ftcmp.txt | grep -v "time" | grep -v "NAMESPACE")
		sleep 1
		stdtimediff=$(cat stdcmp.txt | grep -a "time" | awk '{printf $3}')
		sleep 1
		fttimediff=$(cat ftcmp.txt | grep -a "time" | awk '{printf $3}')
		sleep 1
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

if [ ! -s ./MError.txt ]; then
	rm -rf ./MError.txt
fi

rm -rf leakrep.txt

rm -rf timediff
