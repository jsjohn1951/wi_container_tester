/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:19:50 by wismith           #+#    #+#             */
/*   Updated: 2023/03/15 02:54:19 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	fill_insert_int(NAMESPACE::vector<int> test);
void	value_insert_int(NAMESPACE::vector<int> test);
void	range_insert_int(NAMESPACE::vector<int> test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		value_insert_int(vec);
	}
	std::cout << "\n";
	{
		NAMESPACE::vector<int>	vec;
		fill_insert_int(vec);
	}
	std::cout << "\n";
	{
		NAMESPACE::vector<int>	vec;
		range_insert_int(vec);
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

void	value_insert_int(NAMESPACE::vector<int> test)
{
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
	test.insert(test.end(), 42);
	print_vec(test);
	test.insert(test.begin(), 42);
	print_vec(test);
	test.insert(test.begin() + (test.size() / 2), -9);
	print_size(test);
	test.insert(test.end(), 67);
	test.insert(test.end(), -42);
	test.insert(test.end(), 0);
	test.insert(test.end(), 9);
	print_size(test);
	test.insert(test.begin() + (test.size() / 3), -900);
	print_size(test);
}

void	fill_insert_int(NAMESPACE::vector<int> test)
{
	std::cout << "is empty? " << (test.empty() ? "true" : "false") << std::endl;
	test.insert(test.end(), 2, 2);
	print_vec(test);
	test.insert(test.begin(), 2, 42);
	print_vec(test);
	test.insert(test.begin() + (test.size() / 2), 9, -42);
	print_size(test);
	test.insert(test.end(), 7, 0);
	test.insert(test.end(), 2, 1);
	test.insert(test.end(), 0, 9);
	test.insert(test.end(), 9, 1);
	print_size(test);
	test.insert(test.begin() + (test.size() / 3), 9, 4);
	print_size(test);
	test.insert(test.end() - 1, 2, 444222);
	print_size(test);
}

void	range_insert_int(NAMESPACE::vector<int> test)
{
	NAMESPACE::vector<int>	sample;
	for (int i = 0; i < 15; i++)
		sample.push_back(i);
	print_vec(sample);
	test.insert(test.end(), sample.begin(), sample.end());
	print_size(test);
	test.insert(test.end() - (test.size() / 2), sample.begin() + (sample.size() / 2), sample.end());
	test.insert(test.end() - (test.size() / 3), sample.begin() + (sample.size() / 4), sample.end());
	print_size(test);
	test.clear();
	test.insert(test.begin(), sample.begin() + 1, sample.begin() + 3);
	print_size(test);
	test.insert(test.begin(), sample.begin() + 10, sample.begin() + 12);
	print_size(test);
	test.insert(test.begin(), sample.begin() + 10, sample.begin() + 10);
	print_size(test);

	std::list<int>	list;
	list.assign(4, 5);
	std::list<int>::iterator	it;

	test.insert(test.end(), list.begin(), list.end());
	print_size(test);
}
