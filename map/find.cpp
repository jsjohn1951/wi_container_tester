/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:33:15 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 22:05:43 by wismith          ###   ########.fr       */
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
		std::cout << "map.find(-42) = map.end()? " << (map.find(-42) == map.end()) << std::endl;
		map_elem_insert_int(map);
		for (int i = 0; i < 20; i++)
			std::cout << "first: " << map.find(i)->first
				<< " second: " << map.find(i)->second << std::endl;
		std::cout << "map.find(-42) = map.end()? " << (map.find(-42) == map.end()) << std::endl;
		std::cout << "map.find(-42) = map.end()? " << (map.find(4) == map.end()) << std::endl;
		for (int i = 0; i < 20; i++)
			map.erase(map.find(i));
		print_map(map);
		map_elem_insert_int(map);
		map.clear();
		for (int i = 0; i < 20; i++)
			if (map.find(i) != map.end())
				std::cout << "first: " << map.find(i)->first
				<< " second: " << map.find(i)->second << std::endl;
			else
				std::cout << "find returned end()\n";

		NAMESPACE::map<int, int>::const_iterator	it = map.find(-42);
		std::cout << "it = map.end()? " << (it == map.end()) << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}