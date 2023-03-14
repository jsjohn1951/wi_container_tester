/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:09:32 by wismith           #+#    #+#             */
/*   Updated: 2023/03/14 21:03:27 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	access_simple(NAMESPACE::vector<int> &test);
void	access_change_vec(NAMESPACE::vector<std::string> &test);
void	random_with_assign(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "simple access test:\n";
		NAMESPACE::vector<int> test;
		access_simple(test);
	}
	{
		std::cout << "simple access change test:\n";
		NAMESPACE::vector<std::string> test;
		access_change_vec(test);
	}
	{
		std::cout << "random with assign / insert test:\n";
		NAMESPACE::vector<int> test;
		random_with_assign(test);
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

void access_simple(NAMESPACE::vector<int> &test)
{
	populate_vector(4, test);
	std::cout << test[0] << std::endl;
	std::cout << test[1] << std::endl;

	for (unsigned long i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << "\n";

	populate_vector(10, test);
	for (unsigned long i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << "\n";

	std::cout << "clearing...\n";
	test.clear();
	populate_vector(1, test);
	for (unsigned long  i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << "\n";
}

void	access_change_vec(NAMESPACE::vector<std::string> &test)
{
	for (int i = 0; i < 10; i++)
		test.push_back("42 is Awesome");

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}
	for (unsigned long i = 0; i < test.size(); i++)
		test[i] = "The bob is a real squirrel";

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}

	test.clear();
	for (int i = 0; i < 1; i++)
		test.push_back("42 is THE SCHOOL TO BE IN");

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}

	for (unsigned long i = 0; i < test.size(); i++)
		test[i] = "The bob is looking for his nuts";

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}
}

void	random_with_assign(NAMESPACE::vector<int> &test)
{
	test.assign(1, 5);
	test.assign(5, -42);

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		test[i] = 42;
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}

	test.insert(test.begin(), 3, 5);

	for (unsigned long  i = 0; i < test.size(); i++)
	{
		test[i] = 42;
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}
}

