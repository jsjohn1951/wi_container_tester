#! /bin/bash

# Map
printf "\n\x1B[31m"
printf  "  exit      _______ *        _______   ________  ________ \n"
printf  "  |^|  *  / ------  |       ╱       ╲╲╱        ╲╱        ╲ \n"
printf  "  < > *  / / ~ * |  |      ╱        ╱╱         ╱         ╱  \n"
printf  "  | | * | | ^*  [   |     ╱         ╱         ╱       __╱    \n"
printf  "  | |___/ || |___|U |     ╲__╱__╱__╱╲___╱____╱╲______╱       \n"
printf  "   \_______/\_______/                                         \n"
printf "\n  wi_container_tester by wismith (by 42 student for 42 students)\n\x1B[0m"
printf "\n\tInfo : Compilation Errors can be found in VError.txt\n"

printf "\n\x1B[32mCompiling map tests "

rm -rf MError.txt
c++ -Wall -Werror -Wextra -std=c++98 map/construct.cpp -o std_construct
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/construct.cpp -o ft_construct 2>> MError.txt

printf " . done"

printf "\x1B[0m\n"

if [ -f ./ft_construct ]; then
	std=$(./std_construct | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_construct | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_construct | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_construct | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_construct -a "$std" = "$ft" ]; then
	printf "construct :   [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_construct ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "construct :   [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_construct
rm -rf std_construct

if [ ! -s ./MError.txt ]; then
	rm -rf ./MError.txt
fi
