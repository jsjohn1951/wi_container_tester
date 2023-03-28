/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:21:24 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 13:27:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

void	vector_fill(NAMESPACE::vector<int>	&vec, int num);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int>	vec;
		NAMESPACE::vector<int>	vec2;

		relational_test(vec, vec2);
		
		vector_fill(vec, 5);
		vector_fill(vec2, 5);

		relational_test(vec, vec2);

		vector_fill(vec2, 5);
		relational_test(vec, vec2);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	vector_fill(NAMESPACE::vector<int>	&vec, int num)
{
	for (int i = 0; i < num; i++)
		vec.push_back((i * 5) / 2);
}
