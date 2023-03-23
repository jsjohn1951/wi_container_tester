/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:31:26 by wismith           #+#    #+#             */
/*   Updated: 2023/03/23 17:38:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapTest.hpp"

void	val_insert_test();
void	val_insert_second();
void	range_insert();

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "\nvalue insert test:\n\n";
		val_insert_test();
		val_insert_second();
		std::cout << "end test\n";
	}

	{
		std::cout << "\nvalue insert test:\n\n";

		NAMESPACE::map<int, int>			map;
		NAMESPACE::map<int, int>::iterator	iter;
		iter = map.insert(map.begin(), NAMESPACE::make_pair(5, 9));
		test_insert_pair<int, int>(iter);
		iter = map.insert(map.begin(), NAMESPACE::make_pair(42, 9));
		test_insert_pair<int, int>(iter);
		iter = map.insert(map.begin(), NAMESPACE::make_pair(-42, 9));
		test_insert_pair<int, int>(iter);
		iter = map.insert(map.begin(), NAMESPACE::make_pair(5, 9));
		test_insert_pair<int, int>(iter);
		iter = map.insert(map.begin(), NAMESPACE::make_pair(-42, 9));
		test_insert_pair<int, int>(iter);

		std::cout << "end test\n";
	}
	{
		std::cout << "\nrange insert test:\n\n";
		NAMESPACE::map<std::string, std::string>	map;
		range_insert();

		std::list<NAMESPACE::pair<std::string, std::string> >	lst;
		lst.push_back(NAMESPACE::make_pair("hi 42", "We can do it!"));
		lst.push_back(NAMESPACE::make_pair("hello", "We can do it?"));
		lst.push_back(NAMESPACE::make_pair("Oh crap", "I'm not so sure anymore..."));
		lst.push_back(NAMESPACE::make_pair("hi 42", "We can do it!"));
		lst.push_back(NAMESPACE::make_pair("I need to check", "A peer can help"));
		lst.push_back(NAMESPACE::make_pair("Shoot", "No one to help"));
		lst.push_back(NAMESPACE::make_pair("42 is alien", "I failed"));
		lst.push_back(NAMESPACE::make_pair("We are awesome", "go 42"));

		print_map(map);
		map.insert(lst.begin(), lst.end());
		print_map(map);
		std::cout << "end test\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	range_insert()
{
		std::string									str = "Hello 42 Abu Dhabi! This crazy test ;)";
		std::string									str2 = "... My life is a mess ...";
		std::string									str3 = "Squirrels for life";
		NAMESPACE::map<int, int>					sample;
		NAMESPACE::map<std::string, std::string>	strs;
		NAMESPACE::map<int, int>					test_int;
		NAMESPACE::map<std::string, std::string>	test_str;
		map_elem_insert_int(sample);

		strs.insert(NAMESPACE::make_pair("hi", str));
		strs.insert(NAMESPACE::make_pair("bob", str2));
		strs.insert(NAMESPACE::make_pair("howdy", str3));

		test_int.insert(sample.begin(), sample.begin());
		print_map(test_int);
		test_int.insert(sample.end(), sample.end());
		print_map(test_int);
		test_int.insert(sample.begin(), sample.end());
		print_map(test_int);
		test_int.insert(++sample.begin(), --(--(--sample.end())));
		print_map(test_int);
		test_int.insert(++test_int.begin(), --(--(--test_int.end())));
		print_map(test_int);
		test_int.insert(++test_int.begin(), ++test_int.begin());
		print_map(test_int);
		test_int.insert(--test_int.end(), --test_int.end());
		print_map(test_int);
		
		test_str.insert(strs.begin(), strs.end());
		print_map(test_str);
		test_str.insert(test_str.begin(), ++test_str.begin());
		print_map(test_str);
		test_str.insert(test_str.end(), test_str.end());
		print_map(test_str);
		test_str.insert(--test_str.end(), test_str.end());
		print_map(test_str);
}

void	val_insert_test()
{
		NAMESPACE::map<int, int>			map;
		NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool>	ptr;
	
		ptr = map.insert(NAMESPACE::make_pair(-42, 9));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;

		ptr = map.insert(NAMESPACE::make_pair(42, 21));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;

		ptr = map.insert(NAMESPACE::make_pair(-41, 10));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;

		ptr = map.insert(NAMESPACE::make_pair(15, 12));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;

		ptr = map.insert(NAMESPACE::make_pair(10, 12));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;
		
		ptr = map.insert(NAMESPACE::make_pair(-42, 9));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;
}

void	val_insert_second()
{
	NAMESPACE::map<int, int>			map;
	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool>	ptr;

	map_elem_insert_int(map);

	for (int i = 0; i < 20; i++)
	{
		ptr = map.insert(NAMESPACE::make_pair(i, 9));
		test_insert_pair<int, int>(ptr.first);
		std::cout << "did I allocate? " << (ptr.second ? "true" : "false") << std::endl;
	}

	NAMESPACE::map<std::string, int>			strmap;
	NAMESPACE::pair<NAMESPACE::map<std::string, int>::iterator, bool>	strptr;

	for (int i = 0; i < 20; i++)
	{
		if ((i % 2))
			strptr = strmap.insert(NAMESPACE::make_pair("hi there", 9));
		else if ((! i % 5))
			strptr = strmap.insert(NAMESPACE::make_pair("42 is awesome", 9));
		else
			strptr = strmap.insert(NAMESPACE::make_pair("bob's your uncle", 9));
		std::cout << "first: " << strptr.first->first << " second: " << strptr.first->second << std::endl;
		std::cout << "did I allocate? " << (strptr.second ? "true" : "false") << std::endl;
	}

	for (int i = 0; i < 20; i++)
	{
		strptr = strmap.insert(NAMESPACE::make_pair("42 is aweosome", 9));
		std::cout << "first: " << strptr.first->first << " second: " << strptr.first->second << std::endl;
		std::cout << "did I allocate? " << (strptr.second ? "true" : "false") << std::endl;
	}
}
