/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:04:47 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 16:05:26 by wismith          ###   ########.fr       */
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
		std::cout << (map.rbegin() == map.rend()) << std::endl;
		map_elem_insert_int(map);
		std::cout << (map.rbegin() == map.rend()) << std::endl;
		std::cout << "first: " << map.rbegin()->first << " second: " << map.rbegin()->second << std::endl;
		map.clear();
		std::cout << (map.rbegin() == map.rend()) << std::endl;
		map.insert(NAMESPACE::make_pair<int, int>(4, 9));
		std::cout << (map.rbegin() == map.rend()) << std::endl;
		std::cout << "first: " << map.rbegin()->first << " second: " << map.rbegin()->second << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}