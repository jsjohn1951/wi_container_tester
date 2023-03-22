/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:59:38 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 19:48:31 by wismith          ###   ########.fr       */
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
		NAMESPACE::map<int, int>	map;
		test_equal_range<int, int>(0, map);
		test_equal_range<int, int>(42, map);
		test_equal_range<int, int>(1, map);

		map_elem_insert_int(map);
		test_equal_range<int, int>(5, map);
		test_equal_range<int, int>(9, map);
		test_equal_range<int, int>(2, map);
		test_equal_range<int, int>(515, map);
		test_equal_range<int, int>(42, map);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}
