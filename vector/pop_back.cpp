/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:09:28 by wismith           #+#    #+#             */
/*   Updated: 2023/03/14 21:36:19 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

template <class T>
void	comprehensive_pop(NAMESPACE::vector<T>	&test);
void	populate_vector_int(int num, NAMESPACE::vector<int> &test);
void	populate_vector_string(int num, NAMESPACE::vector<std::string> &test);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		populate_vector_int(10, vec);
		comprehensive_pop(vec);
		populate_vector_int(5, vec);
		comprehensive_pop(vec);
		populate_vector_int(20, vec);
		comprehensive_pop(vec);
	}

	{
		NAMESPACE::vector<std::string>	vec;
		populate_vector_string(10, vec);
		comprehensive_pop(vec);
		populate_vector_string(5, vec);
		comprehensive_pop(vec);
		populate_vector_string(20, vec);
		comprehensive_pop(vec);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
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

void	populate_vector_int(int num, NAMESPACE::vector<int> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back(i - 5);
}

void	populate_vector_string(int num, NAMESPACE::vector<std::string> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back("42 is hard... but Awesome!");
}
