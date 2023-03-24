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
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/empty.cpp -o std_empty
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/empty.cpp -o ft_empty 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/end.cpp -o std_end
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/end.cpp -o ft_end 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/equal_range.cpp -o std_equal_range
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/equal_range.cpp -o ft_equal_range 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/erase.cpp -o std_erase
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/erase.cpp -o ft_erase 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/find.cpp -o std_find
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/find.cpp -o ft_find 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/get_allocator.cpp -o std_get_allocator
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/get_allocator.cpp -o ft_get_allocator 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/insert.cpp -o std_insert
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/insert.cpp -o ft_insert 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/key_comp.cpp -o std_key_comp
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/key_comp.cpp -o ft_key_comp 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/lower_bound.cpp -o std_lower_bound
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/lower_bound.cpp -o ft_lower_bound 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/elem_.cpp -o std_elem_
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/elem_.cpp -o ft_elem_ 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/rbegin.cpp -o std_rbegin
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/rbegin.cpp -o ft_rbegin 2>> MError.txt
printf " . "
c++ -Wall -Werror -Wextra -std=c++98 map/rend.cpp -o std_rend
c++ -Wall -Werror -Wextra -std=c++98 -D NAMESPACE=ft map/rend.cpp -o ft_rend 2>> MError.txt

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
		printf "Compilation Error! Check MError.txt\n"
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
		printf "Compilation Error! Check MError.txt\n"
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
		printf "Compilation Error! Check MError.txt\n"
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
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "count :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_count
rm -rf std_count

if [ -f ./ft_empty ]; then
	std=$(./std_empty | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_empty | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_empty | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_empty | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_empty -a "$std" = "$ft" ]; then
	printf "empty :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_empty ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "empty :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_empty
rm -rf std_empty

if [ -f ./ft_end ]; then
	std=$(./std_end | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_end | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_end | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_end | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_end -a "$std" = "$ft" ]; then
	printf "end :         [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_end ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "end :         [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_end
rm -rf std_end

if [ -f ./ft_equal_range ]; then
	std=$(./std_equal_range | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_equal_range | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_equal_range | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_equal_range | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_equal_range -a "$std" = "$ft" ]; then
	printf "equal_range : [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_equal_range ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "equal_range : [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_equal_range
rm -rf std_equal_range

if [ -f ./ft_erase ]; then
	std=$(./std_erase | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_erase | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_erase | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_erase | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_erase -a "$std" = "$ft" ]; then
	printf "erase :       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_erase ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "erase :       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_erase
rm -rf std_erase

if [ -f ./ft_find ]; then
	std=$(./std_find | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_find | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_find | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_find | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_find -a "$std" = "$ft" ]; then
	printf "find :        [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_find ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "find :        [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_find
rm -rf std_find

if [ -f ./ft_get_allocator ]; then
	std=$(./std_get_allocator | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_get_allocator | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_get_allocator | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_get_allocator | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_get_allocator -a "$std" = "$ft" ]; then
	printf "get_allocator:[\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_get_allocator ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "get_allocator:[\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_get_allocator
rm -rf std_get_allocator

if [ -f ./ft_insert ]; then
	std=$(./std_insert | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_insert | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_insert | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_insert | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_insert -a "$std" = "$ft" ]; then
	printf "insert:       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_insert ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "insert:       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_insert
rm -rf std_insert

if [ -f ./ft_key_comp ]; then
	std=$(./std_key_comp | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_key_comp | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_key_comp | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_key_comp | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_key_comp -a "$std" = "$ft" ]; then
	printf "key_comp:     [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_key_comp ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "key_comp:     [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_key_comp
rm -rf std_key_comp

if [ -f ./ft_lower_bound ]; then
	std=$(./std_lower_bound | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_lower_bound | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_lower_bound | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_lower_bound | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_lower_bound -a "$std" = "$ft" ]; then
	printf "lo/up_bound:  [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_lower_bound ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "lo/up_bound:  [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_lower_bound
rm -rf std_lower_bound

if [ -f ./ft_elem_ ]; then
	std=$(./std_elem_ | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_elem_ | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_elem_ | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_elem_ | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_elem_ -a "$std" = "$ft" ]; then
	printf "operator[]:   [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_elem_ ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "operator[]:   [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_elem_
rm -rf std_elem_

if [ -f ./ft_rbegin ]; then
	std=$(./std_rbegin | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_rbegin | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_rbegin | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_rbegin | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_rbegin -a "$std" = "$ft" ]; then
	printf "rbegin:       [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_rbegin ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "rbegin:       [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_rbegin
rm -rf std_rbegin

if [ -f ./ft_rend ]; then
	std=$(./std_rend | grep -v "time" | grep -v "NAMESPACE")
	ft=$(./ft_rend | grep -v "time" | grep -v "NAMESPACE")
	sleep 1
	stdtimediff=$(./std_rend | grep "time" | awk '{printf $3}')
	sleep 1
	fttimediff=$(./ft_rend | grep "time" | awk '{printf $3}')
fi

if [ -f ./ft_rend -a "$std" = "$ft" ]; then
	printf "rend:         [\x1B[32m ✔️ \x1B[0m] "
	printf "\t|  time diff : "
	printf " ft "
	printf "\x1B[32m$fttimediff\x1B[0m "
	printf " std "
	printf "\x1B[35m$stdtimediff\x1B[0m\n"
else
	if [ -f ./ft_rend ]; then
		diff <(echo "$std") <(echo "$ft")
	else
		printf "Compilation Error! Check MError.txt\n"
	fi
	printf "rend:         [\x1B[31m KO \x1B[0m]\n"
fi

rm -rf ft_rend
rm -rf std_rend

if [ ! -s ./MError.txt ]; then
	rm -rf ./MError.txt
fi
