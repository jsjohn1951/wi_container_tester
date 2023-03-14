/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:07:59 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 19:54:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	erase_test_simple(NAMESPACE::vector<int> &test);
void	erase_test_complex(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		erase_test_simple(vec);
	}

	{
		NAMESPACE::vector<int>	vec;
		erase_test_complex(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

template <class T>
void	print_vec(NAMESPACE::vector<T> &test)
{
	std::cout << "Content :\n";
	for (long unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << std::endl;
}

template <class T>
void	print_size(NAMESPACE::vector<T> &test)
{
	std::cout << "is empty?\t" << (test.empty() ? "true" : "false") << std::endl;
	std::cout << "Capacity > 0 ?\t" << (test.capacity() ? "true" : "false") << std::endl;
	std::cout << "size : " << test.size() << std::endl;
	print_vec(test);
}

void	populate_vector(int num, NAMESPACE::vector<int> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back(i - 5);
}

bool	iter_cmp(NAMESPACE::vector<int>::iterator first,
	NAMESPACE::vector<int>::iterator second)
{
	return (first == second);
}

void	erase_test_simple(NAMESPACE::vector<int> &test)
{
	test.push_back(1);
	std::cout << "erase() = end()? ";
	std::cout << (iter_cmp(test.erase(test.begin()), test.end()) ? "true" : "false") << std::endl;
	print_size(test);
	
	populate_vector(4, test);
	while (!test.empty())
		std::cout << *test.erase(test.begin()) << " ";
	std::cout << std::endl;
	print_size(test);

	populate_vector(10, test);
	while (!test.empty())
		std::cout << *test.erase(test.begin()) << " ";
	std::cout << std::endl;
	print_size(test);

	populate_vector(10, test);
	std::cout << *test.erase(--test.end()) << "\n";

	while (test.size() > 1)
	{
		std::cout << *test.erase(test.end() - (test.size() / 2) ) << "\n";
		print_size(test);
	}
}

void	erase_test_complex(NAMESPACE::vector<int> &test)
{
	populate_vector(10, test);
	print_size(test);
	std::cout << *test.erase(test.begin(), test.end() - (test.size() / 2)) << std::endl;
	print_size(test);
	std::cout << *test.erase(test.begin(), test.begin()) << std::endl;
	print_size(test);
	std::cout << *test.erase(test.begin() + 2, test.begin() + 2) << std::endl;
	print_size(test);

	std::cout << *test.erase(test.begin() + 2, test.begin() + 3) << std::endl;
	print_size(test);

	while (test.size() > 1)
	{
		print_size(test);
		std::cout << *test.erase(test.begin(), test.begin() + 1) << std::endl;
	}
}
