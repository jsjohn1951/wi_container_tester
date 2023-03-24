/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:37:24 by wismith           #+#    #+#             */
/*   Updated: 2023/03/24 17:06:59 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAPTEST_HPP
# define MAPTEST_HPP

# include "../config.hpp"

#	ifndef NAMESPACE
# define MAPHEAD <map>
# else
# define MAPHEAD MAPHPP
#endif

# include MAPHEAD
#include <vector>
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

void	map_elem_insert_string(NAMESPACE::map<int, std::string> &map)
{
	for (int i = 0; i < 20; i++)
		map[i] = "42 is awesome!";
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

template <class V1, class V2>
void	test_equal_range(const V1 &key, NAMESPACE::map<V1, V2> &map)
{
	NAMESPACE::pair<typename NAMESPACE::map<V1, V2>::iterator,
			typename NAMESPACE::map<V1, V2>::iterator>	p = map.equal_range(key);
		std::cout << "first = end? " << (p.first == map.end()) << std::endl;
		std::cout << "second = end? " << (p.second == map.end()) << std::endl;

		if (!((p.first == map.end()) || (p.second == map.end())))
			for (typename NAMESPACE::map<V1, V2>::iterator it = p.first; it != p.second; it++)
				std::cout << "first : " << it->first << " second: " << it->second << std::endl;
}

template <class T1, class T2>
void	test_allocator(typename NAMESPACE::map<T1, T2>::allocator_type	&alloc)
{
	NAMESPACE::pair<const T1, T2>	*ptr = alloc.allocate(1);
	alloc.construct(ptr, NAMESPACE::pair<T1, T2>());
	
	alloc.destroy(ptr);
	alloc.deallocate(ptr, 1);
}

template <class T1, class T2>
void	test_insert_pair(typename NAMESPACE::map<T1, T2>::iterator &iter)
{
	std::cout << "Iterator contents:\n";
	std::cout << "first: " << iter->first << " second: " << iter->second << std::endl;
}

#endif