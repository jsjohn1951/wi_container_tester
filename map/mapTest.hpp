/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:37:24 by wismith           #+#    #+#             */
/*   Updated: 2023/03/22 00:49:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAPTEST_HPP
# define MAPTEST_HPP

#	ifndef MAPHEAD
# define MAPHEAD "../../map/map.hpp"
#endif

#include MAPHEAD
#include <map>
#include <list>
#include <iostream>
#include <limits>
#include <climits>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>


#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


#	ifdef NAMESPACE
# define PRINTNAMESPACE std::cout << KGRN <<"NAMESPACE = ft\n\n" << KNRM;
#endif

#	ifndef NAMESPACE
# define PRINTNAMESPACE std::cout << KRED <<"NAMESPACE = std\n\n" << KNRM;
# define NAMESPACE std
#endif

void	map_elem_insert_int(NAMESPACE::map<int, int> &map)
{
	for (int i = 0; i < 20; i++)
		map[i] = (i * 5) / 2;
}

template <class T1, class T2>
void	print_map(NAMESPACE::map<T1, T2> &map)
{
	std::cout << "Map Size: " << map.size() << std::endl;
	std::cout << "\nContents:\n";
	typename NAMESPACE::map<T1, T2>::iterator	it = map.begin();
	for (; it != map.end(); it++)
		std::cout << "first: " << it->first << "\tsecond: " << it->second << std::endl;
}

#endif