/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:45:42 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 23:07:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	easy_test(NAMESPACE::vector<int> &test);
void	easy_test_string(NAMESPACE::vector<std::string> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		easy_test(vec);
	}
	std::cout << "\n";
	{
		NAMESPACE::vector<std::string> vec;
		easy_test_string(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	easy_test(NAMESPACE::vector<int> &test)
{
	test.push_back(9);
	std::cout << test.front() << std::endl;

	test.clear();
	for (int i = 0; i < 10; i++)
	{
		test.push_back(i + 1);
		std::cout << test.front() << " ";
	}
	std::cout << std::endl;

	test.insert(test.begin(), 4, 42);
	std::cout << test.front() << std::endl;

	for (; !test.empty(); test.erase(test.begin()))
		std::cout << test.front() << " ";
	std::cout << std::endl;

	test.assign(3, -42);
	std::cout << test.front() << std::endl;
	test.assign(42, -42);
	std::cout << test.front() << std::endl;

	int i = 1;
	for (; !test.empty(); test.erase(test.begin()), i++)
	{
		if (!(i % 5))
			std::cout << std::endl;
		std::cout << test.front() << " ";
	}
	std::cout << std::endl;
}

void	easy_test_string(NAMESPACE::vector<std::string> &test)
{
	test.push_back("Hi There Beautiful :)");
	std::cout << test.front() << std::endl;

	test.clear();
	for (int i = 0; i < 10; i++)
	{
		test.push_back("What is your name?");
		std::cout << test.front() << " ";
	}
	std::cout << std::endl;

	test.insert(test.begin(), 4, "I know, random question");
	std::cout << test.front() << std::endl;

	for (; !test.empty(); test.erase(test.begin()))
		std::cout << test.front() << " ";
	std::cout << std::endl;

	test.assign(3, "Welcome to 42!");
	std::cout << test.front() << std::endl;
	test.assign(42, "Don't get a -42!");
	std::cout << test.front() << std::endl;

	int i = 1;
	for (; !test.empty(); test.erase(test.begin()), i++)
	{
		if (!(i % 5))
			std::cout << std::endl;
		std::cout << test.front() << " ";
	}
	std::cout << std::endl;
}
