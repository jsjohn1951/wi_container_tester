/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:45 by wismith           #+#    #+#             */
/*   Updated: 2023/03/13 18:32:46 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	end_test_int(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> vec;
		end_test_int(vec);
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
	std::cout << "Populating vector\n";
	for (int i = 0; i < num; i++)
		test.push_back(std::rand());
}

void	end_test_int(NAMESPACE::vector<int> &test)
{
	std::cout << "begin = end? " << (test.begin() == test.end() ? "true" : "false") << std::endl;
	NAMESPACE::vector<int>	vec;
	populate_vector(5, test);
	populate_vector(32, vec);
	std::cout << "is end? " << (*(--test.end()) == test.back() ? "true" : "false") << std::endl;
	
	NAMESPACE::vector<int>::iterator	it = test.end();
	int	i = 0;
	for (; it >= test.begin(); it--)
		std::cout << i++ << " ";
	std::cout << "\n";

	for (; it < test.end(); it++)
		std::cout << --i << " ";
	std::cout << "\n";

	if (it == test.end())
		std::cout << "Has Reached the end!\n";
	else
		std::cout << "Has not reached end!\n";

	int tmp = test.back();
	test.insert(test.begin(), vec.begin(), vec.end());
	std::cout << "end - 1 = back()? " << (*(--test.end()) == tmp ? "true" : "false") << std::endl;
	test.insert(test.begin(), vec.end(), vec.end());
	std::cout << "end - 1 = back()? " << (*(--test.end()) == tmp ? "true" : "false") << std::endl;

	std::cout << "Clearing...\n";
	test.clear();
	std::cout << "begin = end? " << (test.begin() == test.end() ? "true" : "false") << std::endl;
}