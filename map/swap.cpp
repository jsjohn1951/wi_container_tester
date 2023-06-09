/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:14:53 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 23:21:04 by wismith          ###   ########.fr       */
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

		map_elem_insert_int(nmap);

		print_map(map);
		print_map(nmap);

		map.swap(nmap);

		print_map(map);
		print_map(nmap);
		
		nmap.swap(map);

		print_map(map);
		print_map(nmap);

		map.clear();
		nmap.clear();

		print_map(map);
		print_map(nmap);
		
		nmap.swap(map);
		map.swap(nmap);

		print_map(map);
		print_map(nmap);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}