/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:25:32 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 14:36:02 by wismith          ###   ########.fr       */
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
		map_elem_insert_int(map);

		for (size_t i = 0; i < map.size() + 10; i++)
			std::cout << "Count: " << map.count(i) << std::endl;
	}
	{
		NAMESPACE::map<std::vector<int>, int>	map;

		map.insert(map.begin(), NAMESPACE::make_pair<std::vector<int>, int>(std::vector<int>(5, 6), 7));
		std::cout << "Count: " << map.count(std::vector<int>(5, 6)) << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}