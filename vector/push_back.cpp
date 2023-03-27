/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:57:57 by wismith           #+#    #+#             */
/*   Updated: 2023/03/27 11:46:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

template <class T>
void	comprehensive_push(NAMESPACE::vector<T>	&test);
template <class T>
void	comprehensive_pop(NAMESPACE::vector<T>	&test);
void	populate_vector_int(int num, NAMESPACE::vector<int> &test);
void	populate_vector_string(int num, NAMESPACE::vector<std::string> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		populate_vector_int(10, vec);
		comprehensive_push(vec);
		populate_vector_int(5, vec);
		comprehensive_push(vec);
		populate_vector_int(20, vec);
		comprehensive_push(vec);
	}

	{
		NAMESPACE::vector<std::string>	vec;
		populate_vector_string(10, vec);
		comprehensive_push(vec);
		populate_vector_string(5, vec);
		comprehensive_push(vec);
		populate_vector_string(20, vec);
		comprehensive_push(vec);
	}

	{
		NAMESPACE::vector<int>	vec;
		populate_vector_int(10, vec);
		comprehensive_pop(vec);
		populate_vector_int(5, vec);
		comprehensive_pop(vec);
		populate_vector_int(20, vec);
		comprehensive_pop(vec);
	}

	{
		NAMESPACE::vector<std::string>	vec;
		populate_vector_string(10, vec);
		comprehensive_pop(vec);
		populate_vector_string(5, vec);
		comprehensive_pop(vec);
		populate_vector_string(20, vec);
		comprehensive_pop(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	populate_vector_int(int num, NAMESPACE::vector<int> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back(i - 5);
}

void	populate_vector_string(int num, NAMESPACE::vector<std::string> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back("When you push hard...  ");
}
