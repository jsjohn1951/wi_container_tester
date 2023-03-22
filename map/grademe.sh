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
printf "\n\tInfo : Compilation Errors can be found in VError.txt\n"

printf "\n\x1B[32mCompiling map tests "

rm -rf MError.txt
c++ -Wall -Werror -Wextra -std=c++98 map/construct.cpp -o std_construct
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/construct.cpp -o ft_construct 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/begin.cpp -o std_begin
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/begin.cpp -o ft_begin 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/clear.cpp -o std_clear
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/clear.cpp -o ft_clear 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/count.cpp -o std_count
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/count.cpp -o ft_count 2>> MError.txt

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

if [ -f ./ft_begin ]; then
	std=$(./std_begin | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_begin | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_begin | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_begin | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_begin -a "$std" = "$ft" ]; then
	printf "begin :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_begin ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "begin :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_begin
rm -rf std_begin

if [ -f ./ft_clear ]; then
	std=$(./std_clear | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_clear | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_clear | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_clear | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_clear -a "$std" = "$ft" ]; then
	printf "clear :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_clear ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "clear :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_clear
rm -rf std_clear

if [ -f ./ft_count ]; then
	std=$(./std_count | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_count | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_count | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_count | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_count -a "$std" = "$ft" ]; then
	printf "count :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_count ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "count :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_count
rm -rf std_count

if [ ! -s ./MError.txt ]; then
	rm -rf ./MError.txt
fi
