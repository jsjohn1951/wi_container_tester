/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:09:06 by wismith           #+#    #+#             */
/*   Updated: 2023/03/23 15:22:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapTest.hpp"

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::map<int, int>::allocator_type				int_pair_alloc;
		NAMESPACE::map<std::string, int>::allocator_type		str_pair_alloc;
		NAMESPACE::map<std::vector<int>, int>::allocator_type	vec_pair_alloc;

		test_allocator<int, int>(int_pair_alloc);
		test_allocator<std::string, int>(str_pair_alloc);
		test_allocator<std::vector<int>, int>(vec_pair_alloc);
		std::cout << "OK\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}