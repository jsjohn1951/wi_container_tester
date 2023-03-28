/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:59:08 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 21:04:27 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackTest.hpp"

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "Stack <int> push test:\n";

		NAMESPACE::stack<int>	stack;

		std::cout << "Size : " << stack.size() << std::endl;

		for (int i = 0; i < 10; i++)
		{
			if (!(i % 2))
				stack.push((i * 42) / 2);
			else
				stack.push((i * -42) / 2);
			std::cout << stack.top() << std::endl;
			std::cout << "Size : " << stack.size() << std::endl;
		}

		for (; !stack.empty(); stack.pop())
		{
			std::cout << "Size : " << stack.size() << std::endl;
			std::cout << stack.top() << std::endl;
		}
		
		std::cout << "End Stack <int> push test:\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}
