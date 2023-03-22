/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:02:59 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 14:10:31 by wismith          ###   ########.fr       */
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
		print_map(map);
		map.clear();
		print_map(map);
		map.insert(map.begin(), NAMESPACE::make_pair(6, 9));
		print_map(map);
		map.insert(++map.begin(), NAMESPACE::make_pair(6, 12));
		print_map(map);
		map.clear();
		print_map(map);
		map.insert(map.end(), NAMESPACE::make_pair(6, 9));
		print_map(map);

		NAMESPACE::map<int, int>	nmap(map.begin(), map.end());
		map = nmap;
		map.clear();
		print_map(map);
		nmap.clear();
		map = nmap;
		print_map(map);
		map.clear();
		print_map(map);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}