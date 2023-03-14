/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:35:50 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 17:51:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	empty_test_simple(NAMESPACE::vector<int> &test);
void	empty_test_complex(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> vec;
		empty_test_simple(vec);
	}

	{
		NAMESPACE::vector<int> vec;
		empty_test_complex(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	populate_vector(int num, NAMESPACE::vector<int> &test)
{
	for (int i = 0; i < num; i++)
		test.push_back(std::rand());
}

void	empty_test_simple(NAMESPACE::vector<int> &test)
{
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
	populate_vector(32, test);

	for (; !test.empty(); test.pop_back())
		std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	for (int i = 0; i < 42; i++)
	{
		std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
		test.push_back(std::rand());
	}
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
}

void	empty_test_complex(NAMESPACE::vector<int> &test)
{
	NAMESPACE::vector<int> vec;
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	populate_vector(4, vec);
	test.insert(test.begin(), vec.begin(), vec.end());
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	test.assign(5, 42);
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	test.assign(9, 42);
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	test.assign(0, 3);
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	test.clear();
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;

	test.insert(test.begin(), vec.begin(), vec.end());
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
	test.clear();
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
}
