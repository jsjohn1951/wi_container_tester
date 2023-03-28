/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:04:03 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 13:09:18 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	vector_fill(NAMESPACE::vector<int>	&vec, int num);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "<int> resize test ->\n\n";
		NAMESPACE::vector<int> vec;
		print_size(vec);

		vector_fill(vec, 10);
		print_size(vec);

		vec.resize(5);
		print_size(vec);

		vec.resize(10);
		print_size(vec);

		vec.resize(15);
		print_size(vec);
		
		std::cout << "<- End <int> resize test\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	vector_fill(NAMESPACE::vector<int>	&vec, int num)
{
	for (int i = 0; i < num; i++)
		vec.push_back((i * 5) / 2);
}