/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:35:37 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 18:03:29 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	at_int(NAMESPACE::vector<int> &test);
void	at_string(NAMESPACE::vector<std::string> &test);
void	exception_at_test(NAMESPACE::vector<int> test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "<int> at test ->\n\n";
		NAMESPACE::vector<int> vec;
		at_int(vec);
		std::cout << "<- End <int> at test\n";
	}
	{
		std::cout << "<std::string> at test ->\n\n";
		NAMESPACE::vector<std::string> vec;
		at_string(vec);
		std::cout << "<- End <std::string> at test\n";
	}
	{
		std::cout << "exception at test ->\n\n";
		NAMESPACE::vector<int> vec;
		exception_at_test(vec);
		std::cout << "<- End exception at test\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

template <class T>
void	print_size_capacity(NAMESPACE::vector<T> &test)
{
	std::cout << "Size:     " << test.size() << std::endl;
	std::cout << "Capacity: " << test.capacity() << std::endl;
}

template <class T>
void	print_pos(long long pos, NAMESPACE::vector<T> &test)
{
	print_size_capacity(test);
	std::cout << test.at(pos) << std::endl;
}

/*
*	@brief : Tests at() function with <int>
*/
void	at_int(NAMESPACE::vector<int> &test)
{
	std::cout << KRED << "Test 1:\n" << KNRM;
	test.assign(2, 42);
	print_pos(0, test);
	test.clear();

	std::cout << KGRN << "Test 2:\n" << KNRM;
	test.assign(9, 42);
	print_pos(0, test);
	test.clear();

	std::cout << KMAG << "Test 3:\n" << KNRM;
	test.assign(3, 42);
	test.assign(6, -42);
	print_pos(1, test);
	test.clear();

	std::cout << KCYN << "Test 4:\n" << KNRM;
	test.push_back(5);
	test.push_back(-42);
	test.push_back(23);
	test.push_back(99);
	test.push_back(-50);
	test.push_back(7);
	for (int i = 0; i < 6; i++)
		print_pos(i, test);
}

/*
*	@brief : Tests at() function with <std::string>
*/
void	at_string(NAMESPACE::vector<std::string> &test)
{
	std::cout << KRED << "Test 1:\n" << KNRM;
	test.assign(2, "Hello world");
	print_pos(0, test);
	test.clear();

	std::cout << KGRN << "Test 2:\n" << KNRM;
	test.assign(9, "Some random string");
	print_pos(0, test);
	test.clear();

	std::cout << KMAG << "Test 3:\n" << KNRM;
	test.assign(3, "42");
	test.assign(6, "Think about your career!");
	print_pos(1, test);
	test.clear();

	std::cout << KCYN << "Test 4:\n" << KNRM;
	test.push_back("Your life");
	test.push_back("\tHanges in the balance!\t");
	test.push_back("The squirrels are after my nuts!");
	test.push_back("Alright hand it over");
	test.push_back("No! Don't fight me!");
	test.push_back("That is my nut!");
	for (int i = 0; i < 6; i++)
		print_pos(i, test);
}

void	exception_at_test(NAMESPACE::vector<int> test)
{
	for (int i = 0; i < 10; i++)
		test.push_back(6);

	try{print_pos(-1, test);}
	catch(std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}
	
	try{print_pos(-42, test);}
	catch(std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}
	
	try{print_pos(11, test);}
	catch(std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	try{print_pos(42, test);}
	catch(std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}
	
	try{print_pos(LLONG_MAX, test);}
	catch(std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}
}
