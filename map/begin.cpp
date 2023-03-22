/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:15:41 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 13:28:55 by wismith          ###   ########.fr       */
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
		std::cout << (map.begin() == map.end()) << std::endl;
		map_elem_insert_int(map);
		std::cout << (map.begin() == map.end()) << std::endl;
		std::cout << "first: " << map.begin()->first << " second: " << map.begin()->second << std::endl;
		map.clear();
		std::cout << (map.begin() == map.end()) << std::endl;
		map.insert(NAMESPACE::make_pair<int, int>(4, 9));
		std::cout << (map.begin() == map.end()) << std::endl;
		std::cout << "first: " << map.begin()->first << " second: " << map.begin()->second << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}