/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:40:12 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 15:50:14 by wismith          ###   ########.fr       */
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
		for (int i = 0; i < 20; i++)
			map[i] = (i * 5) + 2;

		print_map(map);
			
		std::cout << "Contents:\n";
		for (int i = 0; i < 20; i++)
			std::cout << map[i] << " ";
		std::cout << std::endl;
	}

	{
		NAMESPACE::map<std::string, std::string>	map;
		map["hello"] = "World";
		map["this is key"] = "life";
		map["42 is the life"] = "and the key";
		map["figure it out"] = "is how";
			
		print_map(map);

		std::cout << "Contents:\n";
		std::cout << map["bob"] << " ";
		std::cout << map["figure it out"] << " ";
		std::cout << map["hello"] << " ";
		std::cout << map["this is key"] << " ";
		std::cout << map["figure it out"] << " ";
		std::cout << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}