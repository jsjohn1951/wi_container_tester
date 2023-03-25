/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:53:02 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 22:59:04 by wismith          ###   ########.fr       */
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
		NAMESPACE::map<int, int>	nmap;
		print_map(map);

		map_elem_insert_int(nmap);
		map = nmap;
		print_map(map);
		map.erase(--map.end());
		print_map(map);
		map.erase(--(--(--map.end())));
		map.erase(++(++map.begin()));
		print_map(map);
		NAMESPACE::map<int, int>::iterator	it = map.begin();
		for (size_t i = 0; i < map.size() / 2; i++)
			it++;
		map.erase(it, ++(++it));
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