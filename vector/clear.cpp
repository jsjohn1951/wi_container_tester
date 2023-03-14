/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:06:54 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 17:29:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	clear_test(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> vec;
		clear_test(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	print_size(NAMESPACE::vector<int> &test)
{
	std::cout << "is empty?\t" << (test.empty() ? "true" : "false") << std::endl;
	std::cout << "Capacity > 0 ?\t" << (test.capacity() ? "true" : "false") << std::endl;
	std::cout << "size : " << test.size() << std::endl;
}

void	populate_vector(int num, NAMESPACE::vector<int> &test)
{
	for (int i = 0; i < num; i++)
		test.push_back(std::rand());
}

void	clear_test(NAMESPACE::vector<int> &test)
{
	print_size(test);
	test.clear();
	print_size(test);

	populate_vector(4, test);
	print_size(test);
	test.clear();
	print_size(test);

	populate_vector(10, test);
	populate_vector(5, test);
	print_size(test);
	test.clear();
	print_size(test);

	populate_vector(50, test);
	print_size(test);
	test.clear();
	print_size(test);

	populate_vector(50, test);
	test.insert((test.begin() + 10), 32, -42);
	print_size(test);
	test.clear();
	print_size(test);
}