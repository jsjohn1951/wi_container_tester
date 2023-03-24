/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:03 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 15:06:41 by wismith          ###   ########.fr       */
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
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=10;
		mymap['b']=-20;
		mymap['c']=-42;
		mymap['p']=42;
		mymap['A']=39;
		std::cout << "mymap contains:\n";
		char highest = mymap.rbegin()->first;
		NAMESPACE::map<char,int>::iterator it = mymap.begin();
		while ( mycomp((*it++).first, highest) )
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << '\n';
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}