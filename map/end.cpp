/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:47:18 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 16:55:38 by wismith          ###   ########.fr       */
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
		std::cout << (map.end() == map.begin()) << std::endl;

		NAMESPACE::map<int, int>::iterator it(map.end());
		map_elem_insert_int(map);
		std::cout << (map.end() == map.begin()) << std::endl;

		for (; it != map.begin(); it--)
			if (it != map.end())
				std::cout << "first: " << it->first << " second: " << it->second << std::endl;
	
		std::cout << (map.end() == map.begin()) << std::endl;

		it = map.end();
		std::cout << (map.end() == map.begin()) << std::endl;
		for (; it != map.begin(); it--)
			if (it != map.end())
				std::cout << "first: " << it->first << " second: " << it->second << std::endl;

		std::cout << (map.end() == map.begin()) << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}