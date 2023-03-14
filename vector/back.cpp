/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:23:57 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 14:45:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	back_int_test(NAMESPACE::vector<int> test);
void	back_string_test(NAMESPACE::vector<std::string> test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	
	{
		std::cout << "<int> back test ->\n\n";
		NAMESPACE::vector<int>	vec;
		back_int_test(vec);
		std::cout << "<- End <int> back test\n";
	}

	{
		std::cout << "<std::string> back test ->\n\n";
		NAMESPACE::vector<std::string>	vec;
		back_string_test(vec);
		std::cout << "<- End <std::string> back test\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	back_int_test(NAMESPACE::vector<int> test)
{
	test.push_back(42);
	std::cout << test.back() << std::endl;
	test.push_back(9);
	std::cout << test.back() << std::endl;
	test.push_back(10);
	std::cout << test.back() << std::endl;
	test.push_back(-42);
	std::cout << test.back() << std::endl;
	test.push_back(93);
	std::cout << test.back() << std::endl;
	test.push_back(66);
	std::cout << test.back() << std::endl;
	test.push_back(-3);
	std::cout << test.back() << std::endl;

	for (; !test.empty(); test.pop_back())
		std::cout << test.back() << std::endl;

	test.assign(9, 42);
	for (; !test.empty(); test.pop_back())
		std::cout << test.back() << " ";
	std::cout << std::endl;
}

void	back_string_test(NAMESPACE::vector<std::string> test)
{
	test.push_back("42");
	std::cout << test.back() << std::endl;
	test.push_back("Hello World");
	std::cout << test.back() << std::endl;
	test.push_back("Who came up with these tests?");
	std::cout << test.back() << std::endl;
	test.push_back("What a jerk!");
	std::cout << test.back() << std::endl;

	for (; !test.empty(); test.pop_back())
		std::cout << test.back() << std::endl;

	test.assign(12, "He is crazy!");
	int i = 0;
	for (; !test.empty(); test.pop_back(), i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test.back() << " ";
	}
	std::cout << std::endl;
}
