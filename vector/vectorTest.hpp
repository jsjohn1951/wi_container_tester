/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:58:34 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 13:26:42 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VECTORTEST_HPP
# define VECTORTEST_HPP

# include "../config.hpp"

#	ifndef VECHEAD
# define VECHEAD VECTORHPP
#endif

#include VECHEAD
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

template <class T>
void	print_vec(NAMESPACE::vector<T> &vec)
{
	std::cout << "Contents :\n";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

template <class T>
void	print_size(NAMESPACE::vector<T> &test)
{
	std::cout << "is empty?\t" << (test.empty() ? "true" : "false") << std::endl;
	std::cout << "Capacity > 0 ?\t" << (test.capacity() ? "true" : "false") << std::endl;
	std::cout << "size : " << test.size() << std::endl;
	print_vec(test);
}


template <class T>
void	print_elem(NAMESPACE::vector<T>	&test)
{
	for (unsigned long i = 0; i < test.size(); i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;
}

template <class T>
void	randomize(NAMESPACE::vector<T>	&test)
{
	NAMESPACE::vector<T>	Double;
	for (unsigned long i = 0; i < test.size(); i++)
	{
		unsigned long j = (unsigned long) std::rand() % test.size();
		if (j < test.size() )
			Double.push_back(test[j]);
	}
	test = Double;
}

template <class T>
void	comprehensive_push(NAMESPACE::vector<T>	&test)
{
	NAMESPACE::vector<T>	ran;

	ran.push_back(T());
	ran.push_back(T());
	ran.push_back(T());
	ran.push_back(T());
	print_elem(ran);
	print_elem(test);
	randomize(test);
	randomize(test);
	print_size(test);
	print_elem(test);
	test.push_back(T());
	test.push_back(T());
	print_size(test);
	print_elem(test);
	test.clear();
	test.push_back(T());
	print_size(test);
	print_elem(test);
}

template <class T>
void	poper(NAMESPACE::vector<T>	&test)
{
	int i = 0;
	for (; !test.empty(); test.pop_back(), i++)
	{
		if (!(i % 5))
			std::cout << "\n";
		std::cout << test.back() << " ";
	}
	std::cout << std::endl;
}

template <class T>
void	comprehensive_pop(NAMESPACE::vector<T>	&test)
{
	NAMESPACE::vector<T>	Double(test);

	poper(test);

	test = Double;

	randomize(test);
	randomize(test);
	randomize(test);

	poper(test);

	test = Double;
	randomize(test);
	randomize(test);
	randomize(test);
	randomize(test);
	randomize(test);
	randomize(test);

	poper(test);

	test.assign(5, T());
	poper(test);
}

template <class T>
void	relational_test(NAMESPACE::vector<T> &vec, NAMESPACE::vector<T> &vec2)
{
	std::cout << "Relational check :\n";
	std::cout << "vec1 == vec2 ? " << (vec == vec2 ? "true" : "false") << std::endl;
	std::cout << "vec1 != vec2 ? " << (vec != vec2 ? "true" : "false") << std::endl;
	std::cout << "vec1 > vec2 ? " << (vec > vec2 ? "true" : "false") << std::endl;
	std::cout << "vec1 < vec2 ? " << (vec < vec2 ? "true" : "false") << std::endl;
	std::cout << "vec1 >= vec2 ? " << (vec >= vec2 ? "true" : "false") << std::endl;
	std::cout << "vec1 <= vec2 ? " << (vec <= vec2 ? "true" : "false") << std::endl;
}

#endif