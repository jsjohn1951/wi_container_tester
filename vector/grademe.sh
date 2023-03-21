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
c++ -Wall -Werror -Wextra -std=c++98 vector/assign.cpp -o std_assign
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/assign.cpp -o ft_assign 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/at.cpp -o std_at
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/at.cpp -o ft_at 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/back.cpp -o std_back
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/back.cpp -o ft_back 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/begin.cpp -o std_begin
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/begin.cpp -o ft_begin 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/clear.cpp -o std_clear
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/clear.cpp -o ft_clear 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/empty.cpp -o std_empty
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/empty.cpp -o ft_empty 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/erase.cpp -o std_erase
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/erase.cpp -o ft_erase 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/front.cpp -o std_front
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/front.cpp -o ft_front 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/insert.cpp -o std_insert
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/insert.cpp -o ft_insert 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/max_size.cpp -o std_max_size
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/max_size.cpp -o ft_max_size 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/elem_.cpp -o std_elem_
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/elem_.cpp -o ft_elem_ 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/push_back.cpp -o std_push_back
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/push_back.cpp -o ft_push_back 2>> VError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 vector/iterator.cpp -o std_iterator
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft vector/iterator.cpp -o ft_iterator 2>> VError.txt
printf " . done"

printf "\x1B[0m\n"

if [ -f ./ft_assign ]; then
	std=$(./std_assign | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_assign | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_assign | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_assign | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_assign -a "$std" = "$ft" ]; then
	printf "assign :   [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_assign ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "assign :   [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_assign
rm -rf std_assign

if [ -f ./ft_at ]; then
	std=$(./std_at | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_at | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_at | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_at | grep "time" | awk '{printf $3}')
fi


if [ -f ./ft_at -a "$std" = "$ft" ]; then
	printf "at :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_at ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "at :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_at
rm -rf std_at

if [ -f ./ft_back ]; then
	std=$(./std_back | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_back | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_back | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_back | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_back -a "$std" = "$ft" ]; then
	printf "back :     [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_back ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "back :     [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_back
rm -rf std_back

if [ -f ./ft_begin ]; then
	std=$(./std_begin | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_begin | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_begin | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_begin | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_begin -a "$std" = "$ft" ]; then
	printf "beg/end :  [\x1B[32m ✔️ \x1B[0m] "
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
	printf "beg/end :  [\x1B[31m KO \x1B[0m]\n"
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
	printf "clear :    [\x1B[32m ✔️ \x1B[0m] "
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
	printf "clear :    [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_clear
rm -rf std_clear

if [ -f ./ft_empty ]; then
	std=$(./std_empty | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_empty | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_empty | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_empty | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_empty -a "$std" = "$ft" ]; then
	printf "empty :    [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_empty ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "empty :    [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_empty
rm -rf std_empty

if [ -f ./ft_erase ]; then
	std=$(./std_erase | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_erase | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_erase | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_erase | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_erase -a "$std" = "$ft" ]; then
	printf "erase :    [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_erase ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "erase :    [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_erase
rm -rf std_erase

if [ -f ./ft_front ]; then
	std=$(./std_front | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_front | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_front | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_front | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_front -a "$std" = "$ft" ]; then
	printf "front :    [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_front ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "front :    [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_front
rm -rf std_front

if [ -f ./ft_insert ]; then
	std=$(./std_insert | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_insert | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_insert | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_insert | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_insert -a "$std" = "$ft" ]; then
	printf "insert :   [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_insert ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "insert :   [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_insert
rm -rf std_insert

if [ -f ./ft_max_size ]; then
	std=$(./std_max_size | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_max_size | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_max_size | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_max_size | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_max_size -a "$std" = "$ft" ]; then
	printf "max_size : [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_max_size ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "max_size : [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_max_size
rm -rf std_max_size

if [ -f ./ft_elem_ ]; then
	std=$(./std_elem_ | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_elem_ | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_elem_ | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_elem_ | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_elem_ -a "$std" = "$ft" ]; then
	printf "oper[] :   [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_elem_ ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "oper[] :   [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_elem_
rm -rf std_elem_

if [ -f ./ft_push_back ]; then
	std=$(./std_push_back | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_push_back | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_push_back | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_push_back | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_push_back -a "$std" = "$ft" ]; then
	printf "push/pop : [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_push_back ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "push/pop : [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_push_back
rm -rf std_push_back

if [ -f ./ft_iterator ]; then
	std=$(./std_iterator | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_iterator | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_iterator | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_iterator | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_iterator -a "$std" = "$ft" ]; then
	printf "iterator : [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_iterator ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check VError.txt\n"
	fi
	printf "iterator : [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_iterator
rm -rf std_iterator

if [ ! -s ./VError.txt ]; then
	rm -rf ./VError.txt
fi

# (vector)
# 		more insert tests
# 		operator=
# 		rbegin()
# 		rend()
# 		reserve()
# 		resize()
# 		swap()
# 		Non members
