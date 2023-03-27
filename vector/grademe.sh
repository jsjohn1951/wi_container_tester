#! /bin/bash

# Vector

printf "\x1B[31m                                         _       .  '  *   .  . ' \n"
printf "       .-.      _______                 | |           .  * * -+-     \n"
printf "      {}''; |==|_______D __   _____  ___| |_ ___  _ __ .    * .    '  *   \n"
printf "      / ('        /|\    \ \ / / _ \/ __| __/ _ \| '__|  * .  ' .  .    \n"
printf "  (  /  | []     / | \    \ V /  __/ (__| || (_) | |  *   *  .   .      \n"
printf "   \(_)_]       /  |  \    \_/ \___|\___|\__\___/|_| '   *                   \n"
printf "\n  wi_container_tester by wismith (by 42 student for 42 students)\n\x1B[0m"
printf "\n\tInfo : Compilation Errors can be found in VError.txt\n"
printf "\n\x1B[32mCompiling vector tests "

# exit 0

rm -rf VError.txt

c++ ./timediff.cpp -o timediff

array=(vector/construct.cpp vector/assign.cpp vector/at.cpp vector/back.cpp vector/begin.cpp vector/clear.cpp vector/empty.cpp \
	vector/erase.cpp vector/front.cpp vector/insert.cpp vector/max_size.cpp vector/elem_.cpp vector/push_back.cpp vector/reserve.cpp \
	vector/iterator.cpp vector/rbegin.cpp)
for str in ${array[@]}; do
	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c8-)
	std=$executable"_std"
	ft=$executable"_ft"
	c++ -Wall -Werror -Wextra -std=c++98 $str -o $std
	c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft $str -o $ft 2>> VError.txt
	printf " . "
done

printf " . done"
printf "\x1B[0m\n"

for str in ${array[@]}; do

	executable=$(printf "$str" | rev | cut -c5- | rev | cut -c8-)
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
				printf "[\x1B[31m KO \x1B[0m]\n"
			else
				printf "[\x1B[32m ✔️ \x1B[0m]\n"
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

if [ ! -s ./VError.txt ]; then
	rm -rf ./VError.txt
fi

rm -rf leakrep.txt

rm -rf timediff

# (vector)
# 		more insert tests
# 		resize()
# 		swap()
# 		Non members
