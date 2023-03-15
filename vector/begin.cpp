/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:52:02 by wismith           #+#    #+#             */
/*   Updated: 2023/03/15 17:03:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	begin_test(NAMESPACE::vector<int> test);
void	begin_string_test(NAMESPACE::vector<std::string> test);
void	end_test_int(NAMESPACE::vector<int> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "<int> begin test ->\n\n";
		NAMESPACE::vector<int> vec;
		begin_test(vec);
		std::cout << "<- End <int> begin test\n";
	}
	
	{
		std::cout << "<std::string> begin test ->\n\n";
		NAMESPACE::vector<std::string> vec;
		begin_string_test(vec);
		std::cout << "<- End <std::string> begin test\n";
	}

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

void	begin_test(NAMESPACE::vector<int> test)
{
	test.push_back(6);
	std::cout << *test.begin() << std::endl;
	test.clear();

	test.push_back(9);
	test.push_back(42);
	std::cout << *test.begin() << std::endl;
	test.clear();
	
	test.push_back(-42);
	test.push_back(42);
	test.push_back(92);
	test.push_back(43);
	std::cout << *test.begin() << std::endl;
	test.clear();

	test.push_back(-42);
	test.push_back(42);
	test.push_back(92);
	test.push_back(43);
	std::cout << *(++test.begin()) << std::endl;
	test.clear();

	test.push_back(-42);
	test.push_back(42);
	test.push_back(92);
	test.push_back(43);
	std::cout << *(test.begin() + 2) << std::endl;
	test.clear();

	std::cout << *test.begin() << std::endl;
}

void	begin_string_test(NAMESPACE::vector<std::string> test)
{
	test.push_back("Hello world!");
	std::cout << *test.begin() << std::endl;
	test.clear();

	test.push_back("Is it just me?");
	test.push_back("42");
	std::cout << *test.begin() << std::endl;
	test.clear();
	
	test.push_back("-42");
	test.push_back("I'm totally just venting");
	test.push_back("on all my test cases lol");
	test.push_back("Imagine a world were everything was perfect");
	std::cout << *test.begin() << std::endl;
	test.clear();

	test.push_back("I strive to be part of a world");
	test.push_back("\tThat works towards perfection");
	test.push_back("Imagine life as a squirrel");
	test.push_back("Just looking for your nuts");
	std::cout << *(++test.begin()) << std::endl;
	test.clear();

	test.push_back("But you can't find them");
	test.push_back("You've grown to fat");
	test.push_back("On pizza");
	test.push_back("I've said too much...");
	std::cout << *(test.begin() + 2) << std::endl;
	test.clear();

	std::cout << *test.begin() << std::endl;
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
