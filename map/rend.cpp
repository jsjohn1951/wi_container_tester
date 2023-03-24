/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:18 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 19:02:21 by wismith          ###   ########.fr       */
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
		std::cout << (map.rend() == map.rbegin()) << std::endl;

		NAMESPACE::map<int, int>::reverse_iterator it(map.rend());

		map_elem_insert_int(map);
		std::cout << (map.rend() == map.rbegin()) << std::endl;
		it = map.rend();

		for (; it != map.rbegin(); it--)
			if (it != map.rend())
				std::cout << "first: " << it->first << " second: " << it->second << std::endl;

		std::cout << (map.rend() == map.rbegin()) << std::endl;

		it = map.rend();
		std::cout << (map.rend() == map.rbegin()) << std::endl;
		for (; it != map.rbegin(); it--)
			if (it != map.rend())
				std::cout << "first: " << it->first << " second: " << it->second << std::endl;

		std::cout << (map.rend() == map.rbegin()) << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}