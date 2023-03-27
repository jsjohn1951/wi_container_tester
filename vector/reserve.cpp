/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:45:51 by wismith           #+#    #+#             */
/*   Updated: 2023/03/27 16:12:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	push_vec_int(NAMESPACE::vector<int> &vec, int num);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		
		std::cout << "\nTest 1:\n";
		std::cout << "capacity: " << vec.capacity() << std::endl;

		std::cout << "\nTest 2:\n";
		vec.reserve(15);
		std::cout << "capacity: " << vec.capacity() << std::endl;
		vec.reserve(25);
		std::cout << "capacity: " << vec.capacity() << std::endl;
		vec.reserve(35);
		std::cout << "capacity: " << vec.capacity() << std::endl;


		std::cout << "\nTest 3:\n";
		std::cout << "capacity: " << vec.capacity() << std::endl;
		push_vec_int(vec, 5);
		std::cout << "capacity: " << vec.capacity() << std::endl;

		std::cout << "\nTest 4:\n";
		vec.clear();
		push_vec_int(vec, 14);
		std::cout << "capacity: " << vec.capacity() << std::endl;

		std::cout << "\nTest 5:\n";
		vec.clear();
		push_vec_int(vec, 15);
		std::cout << "capacity: " << vec.capacity() << std::endl;


		std::cout << "\nTest 6:\n";
		vec.clear();
		push_vec_int(vec, 20);
		std::cout << "capacity: " << vec.capacity() << std::endl;

		std::cout << "\nTest 7:\n";
		vec.reserve(15);
		std::cout << "capacity: " << vec.capacity() << std::endl;


		std::cout << "\nTest 8:\n";
		vec.reserve(19);
		std::cout << "capacity: " << vec.capacity() << std::endl;


		std::cout << "\nTest 9:\n";
		vec.reserve(25);
		std::cout << "capacity: " << vec.capacity() << std::endl;

	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	push_vec_int(NAMESPACE::vector<int> &vec, int num)
{
	for (int i = 0; i < num; i++)
		vec.push_back((i * 5) / 2);
	randomize(vec);
}
