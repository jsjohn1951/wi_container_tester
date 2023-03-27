/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:23:42 by wismith           #+#    #+#             */
/*   Updated: 2023/03/27 20:43:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	elem_push(NAMESPACE::vector<int> vec);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "<int> Default / Copy Constructor and Assignment Operator test :\n";
		NAMESPACE::vector<int>	vec;
		NAMESPACE::vector<int>	vec2(vec);

		{
			print_size(vec);
			print_size(vec2);
			elem_push(vec);
			print_size(vec);
			print_size(vec2);
		}

		NAMESPACE::vector<int>	vec3(vec);
		{
			print_size(vec);
			print_size(vec2);
			print_size(vec3);
		}

		vec2 = vec;
		print_size(vec2);

		vec.clear();
		print_size(vec);
		print_size(vec2);

		vec2 = vec;
		print_size(vec);
		print_size(vec2);
		std::cout << "<int> end test\n";
	}

	{
		std::cout << "<int> range constructor test :\n";
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(9);
		lst.push_back(12);
		lst.push_back(42);
		
		NAMESPACE::vector<int>	vec(lst.begin(), lst.begin());
		print_size(vec);
		NAMESPACE::vector<int>	vec1(++(++lst.begin()), --lst.end());
		print_size(vec1);
		NAMESPACE::vector<int>	vec2(lst.begin(), lst.end());
		print_size(vec2);
		std::cout << "<int> end test\n";
	}
	
	{
		std::cout << "different types test :\n";
		NAMESPACE::vector<int> vec;
		NAMESPACE::vector<char> vec1;
		NAMESPACE::vector<int *> vec2;
		NAMESPACE::vector<char *> vec3;
		NAMESPACE::vector<std::string> vec4;
		std::cout << "End different types test" <<  std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	elem_push(NAMESPACE::vector<int> vec)
{
	for (int i = 0; i < 25; i++)
		vec.push_back((i * 5) / 2);
}
