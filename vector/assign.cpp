/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:24:57 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 18:02:20 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	fill_assign_int(NAMESPACE::vector<int> &test);
void	fill_assign_string(NAMESPACE::vector<std::string> &test);
void	range_assign_int(NAMESPACE::vector<int> test);
void	range_assign_string(NAMESPACE::vector<std::string> test);
void	exception_test(NAMESPACE::vector<int> test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	try {
		std::cout << "<int> fill test ->\n\n";
		NAMESPACE::vector<int>	vec;
		fill_assign_int(vec);
		std::cout << "<- End <int> fill test\n";
	} catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	try {
		std::cout << "\n<std::string> fill test ->\n\n";
		NAMESPACE::vector<std::string>	vec;
		fill_assign_string(vec);
		std::cout << "<- End <std::string> fill test\n";
	} catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	try {
		std::cout << "<int> range test ->\n\n";
		NAMESPACE::vector<int>	vec;
		range_assign_int(vec);
		std::cout << "<- End <int> range test\n";
	} catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	try {
		std::cout << "<std::string> range test ->\n\n";
		NAMESPACE::vector<std::string>	vec;
		range_assign_string(vec);
		std::cout << "<- End <std::string> range test\n";
	} catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	try {
		std::cout << "Exception test ->\n\n";
		NAMESPACE::vector<int>	vec;
		exception_test(vec);
		std::cout << "<- End Exception test\n";
	} catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

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

/*
*	@brief : print the result using primitive method of determining the element
*	@note :
*		by primitive I mean using the 'back' function and popping elements.
*		Using the empty function as a condition for the for () loop.
*/
template <class T>
void	primitive_print_(NAMESPACE::vector<T> &test)
{
	int	i = 0;
	std::cout << "\n\tContents\n";
	std::cout << "------------------------\n";
	print_size_capacity(test);
	for (;!test.empty(); test.pop_back(), i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test.back() << " ";
	}
	std::cout << "\n\n------------------------";
	std::cout << "\n\n";
}

/*
*	@brief : Tests fill Assign with <int>
*/
void	fill_assign_int(NAMESPACE::vector<int> &test)
{
	std::cout << KRED << "Test 1:\n" << KNRM;
	test.assign(2, 42);
	primitive_print_(test);

	std::cout << KGRN << "Test 2:\n" << KNRM;
	test.assign(9, 42);
	primitive_print_(test);

	std::cout << KMAG << "Test 3:\n" << KNRM;
	test.assign(3, 42);
	test.assign(6, -42);
	primitive_print_(test);

	std::cout << KCYN << "Test 4:\n" << KNRM;
	test.assign(5, 4);
	test.assign(12, -42);
	test.assign(32, 42);
	test.assign(9, -4);
	test.assign(13, 42);
	test.assign(4, -2);
	primitive_print_(test);
}

/*
*	@brief : Tests fill Assign with <std::string>
*/
void	fill_assign_string(NAMESPACE::vector<std::string> &test)
{
	std::cout << KRED << "Test 1:\n" << KNRM;
	test.assign(10, "hello");
	primitive_print_(test);

	std::cout << KGRN << "Test 2:\n" << KNRM;
	test.assign(15, "World");
	primitive_print_(test);

	std::cout << KMAG << "Test 3:\n" << KNRM;
	test.assign(3, "Squirrel had come");
	test.assign(12, "To Collect his nuts");
	primitive_print_(test);

	std::cout << KCYN << "Test 4:\n" << KNRM;
	test.assign(5, "This is the world");
	test.assign(12, "0");
	test.assign(20, "Non shall pass");
	test.assign(9, "The Hobbit's journey");
	test.assign(8, "Tester forever");
	test.assign(30, "The answer is... 42");
	primitive_print_(test);
}

/*
*	@brief : tests the range assign function
*/
void	range_assign_int(NAMESPACE::vector<int> test)
{
	NAMESPACE::vector<int>	sample;
	
	std::cout << KRED << "Test 1:\n" << KNRM;
	sample.assign(12, 42);
	test.assign(sample.begin(), sample.end());
	primitive_print_(test);

	std::cout << KGRN << "Test 2:\n" << KNRM;
	sample.assign(5, 4);
	test.assign(sample.begin(), sample.end());
	sample.assign(12, -42);
	test.assign(sample.begin(), sample.end());
	sample.assign(32, 42);
	test.assign(sample.begin(), sample.end());
	sample.assign(10, -4);
	test.assign(sample.begin(), sample.end());
	primitive_print_(test);
}

/*
*	@brief : tests the range assign function with std::strings
*/
void	range_assign_string(NAMESPACE::vector<std::string> test)
{
	NAMESPACE::vector<std::string>	sample;
	
	std::cout << KRED << "Test 1:\n" << KNRM;
	sample.assign(12, "42");
	test.assign(sample.begin(), sample.end());
	primitive_print_(test);

	std::cout << KGRN << "Test 2:\n" << KNRM;
	sample.assign(5, "Here to Cook Code!");
	test.assign(sample.begin(), sample.end());
	sample.assign(12, "I know my tests are creative");
	test.assign(sample.begin(), sample.end());
	sample.assign(32, "What do you think about my quotes???");
	test.assign(sample.begin(), sample.end());
	sample.assign(10, "Give feedback :)");
	test.assign(sample.begin(), sample.end());
	primitive_print_(test);
}

void	exception_test(NAMESPACE::vector<int> test)
{
	std::cout << KRED << "Test 1:\n" << KNRM;
	try 
	{
		test.assign(0, 42);
		primitive_print_(test);
	}
	catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	std::cout << KGRN << "Test 2:\n" << KNRM;
	try 
	{
		test.assign(-1, 42);
		primitive_print_(test);
	}
	catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	std::cout << KMAG << "Test 3:\n" << KNRM;
	try 
	{
		test.assign(-9, 42);
		primitive_print_(test);
	}
	catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}

	std::cout << KCYN << "Test 4:\n" << KNRM;
	try 
	{
		test.assign(LLONG_MAX, 42);
		primitive_print_(test);
	}
	catch (std::exception &e)
	{(void)e; std::cout << "exception thrown" << std::endl;}
}
