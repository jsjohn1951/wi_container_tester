/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:37:09 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 16:41:10 by wismith          ###   ########.fr       */
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
		std::cout << "is empty: " << map.empty() << std::endl;
		map_elem_insert_int(map);
		std::cout << "is empty: " << map.empty() << std::endl;
		map.clear();
		std::cout << "is empty: " << map.empty() << std::endl;
		map_elem_insert_int(map);
		std::cout << "is empty: " << map.empty() << std::endl;
		map.erase((map.begin()++)++, --(--map.end()));
		std::cout << "is empty: " << map.empty() << std::endl;
		map.erase(map.begin(), map.end());
		std::cout << "is empty: " << map.empty() << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}