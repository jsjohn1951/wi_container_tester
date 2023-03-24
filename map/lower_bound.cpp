/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:04:22 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 15:34:43 by wismith          ###   ########.fr       */
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
		/*
		*	@brief : similar test cases found on cplusplus
		*/
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		
		// print content:
		print_map(mymap);
	}
	{
		NAMESPACE::map<std::string,int> mymap;
		NAMESPACE::map<std::string,int>::iterator itlow,itup;

		mymap["hello "]=20;
		mymap["Member 42"]=40;
		mymap["Weapons ready!"]=60;
		mymap["Who knows?"]=80;
		mymap["Random thoughts"]=100;
		itlow=mymap.lower_bound ("M");
		itup=mymap.upper_bound ("Random");
		mymap.erase(itlow,itup);
		
		print_map(mymap);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}