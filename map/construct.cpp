/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:51:24 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 14:21:16 by wismith          ###   ########.fr       */
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
		NAMESPACE::map<int, int>	nmap(map);
		print_map(nmap);
		print_map(nmap);
	}
	{
		NAMESPACE::map<int, int>	map;
		print_map(map);
		map_elem_insert_int(map);
		print_map(map);
		NAMESPACE::map<int, int>	nmap(map);
		print_map(nmap);
	}
	{
		NAMESPACE::map<int, int>	map;
		map_elem_insert_int(map);
		NAMESPACE::map<int, int>	nmap = map;
		print_map(nmap);
		NAMESPACE::map<int, int>	nnmap;
		map_elem_insert_int(nnmap);
		print_map(nnmap);
		nnmap = map;
		print_map(nnmap);
	}
	{
		NAMESPACE::map<int, std::string>	map;
		map_elem_insert_string(map);
		NAMESPACE::map<int, std::string>	nmap(map.begin(), map.end());
		print_map(nmap);
		NAMESPACE::map<int, std::string>	nnmap(++map.begin(), --map.end());
		print_map(nnmap);

		nnmap.insert(nnmap.begin(), nnmap.end());
		print_map(nnmap);
	}
	{
		NAMESPACE::map<int, std::string>::pointer	ptr;
		NAMESPACE::map<int, std::string>::allocator_type	alloc;

		ptr = alloc.allocate(1);
		alloc.construct(ptr, NAMESPACE::make_pair<const int, std::string>(5, "hi 42 student! :) "));

		NAMESPACE::map<int, std::string>::reference	ref = *ptr;
		NAMESPACE::map<int, std::string>::mapped_type	m = "are we awesome or not?";
		
		std::cout << "first: " << ptr->first << " second: " << ptr->second << std::endl;
		std::cout << "first: " << ref.first << " second: " << ref.second << std::endl;
		std::cout << "Mapped type: " << m << std::endl;
		
		alloc.destroy(ptr);
		alloc.deallocate(ptr, 1);
	}
	{
		NAMESPACE::map<int, std::string>	map;
		map_elem_insert_string(map);

		NAMESPACE::map<int, std::string>::iterator			it(map.begin());
		NAMESPACE::map<int, std::string>::const_iterator	cit(map.end());
		for (; it != cit; it++)
			std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		it = map.begin();
		cit = --map.end();
		for (; it != cit; cit--)
			std::cout << "first: " << cit->first << " second: " << cit->second << std::endl;
		NAMESPACE::map<int, std::string>::reverse_iterator			rit(map.rbegin());
		NAMESPACE::map<int, std::string>::const_reverse_iterator	rcit(map.rend());
		for (; rit != rcit; rit++)
			std::cout << "first: " << rit->first << " second: " << rit->second << std::endl;
		rit = map.rbegin();
		rcit = --map.rend();
		for (; rit != rcit; rcit--)
			std::cout << "first: " << rcit->first << " second: " << rcit->second << std::endl;
		
		NAMESPACE::map<int, std::string>::iterator	nit(rit.base());
		for (; nit != map.end(); nit++)
			std::cout << "first: " << nit->first << " second: " << nit->second << std::endl;
		nit = rit.base();
		for (; nit != map.end(); nit++)
			std::cout << "first: " << nit->first << " second: " << nit->second << std::endl;
	}
	{
		std::vector<NAMESPACE::pair<int, int> >	vec(5, NAMESPACE::make_pair(9, 10));

		NAMESPACE::map<int, int>	map(vec.begin(), vec.end());
		print_map(map);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}