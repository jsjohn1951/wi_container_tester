/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:54:41 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 21:30:59 by wismith          ###   ########.fr       */
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
		NAMESPACE::map<int, int>::iterator	it;
		print_map(map);
		map_elem_insert_int(map);
		print_map(map);
		map.erase(map.begin());
		print_map(map);
		it = map.begin();
		for (size_t i = 0; i < (map.size() / 2); i++, it++)
			;
		map.erase(it);
		print_map(map);
		for (; !map.empty();)
			map.erase(--map.end());
		print_map(map);
		map_elem_insert_int(map);
		for (; ++map.begin() != map.end();)
			map.erase(map.begin());
	}

	{
		NAMESPACE::map<int, int>	map;
		map_elem_insert_int(map);
		print_map(map);
		map.erase(map.begin(), map.end());
		print_map(map);
		map_elem_insert_int(map);
		for (; map.size() > 1;)
			map.erase(--(--map.end()), --map.end());
		print_map(map);
		map_elem_insert_int(map);
		map.erase(map.end(), map.end());
		print_map(map);
		map.erase(--map.end(), --map.end());
		map.erase(map.begin(), map.begin());
		map.erase(map.begin(), ++(++(++map.begin())));
	}

	{
		NAMESPACE::map<int, int>	map;
		std::cout << map.erase(42) << std::endl;
		std::cout << map.erase(5) << std::endl;
		std::cout << map.erase(9) << std::endl;
		std::cout << map.erase(14) << std::endl;
		map_elem_insert_int(map);
		std::cout << map.erase(5) << std::endl;
		std::cout << map.erase(9) << std::endl;
		std::cout << map.erase(14) << std::endl;
		std::cout << map.erase(19) << std::endl;
		std::cout << map.erase(3) << std::endl;
		std::cout << map.erase(5) << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}