/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:27:46 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 21:35:10 by wismith          ###   ########.fr       */
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
		NAMESPACE::stack<int>	stack2;

		relational_test(stack, stack2);
		
		stack_push_(stack, 5);
		relational_test(stack, stack2);

		stack_push_(stack2, 15);
		relational_test(stack, stack2);

		stack_push_(stack, 10);
		relational_test(stack, stack2);

		
		std::cout << "End Stack <int> push test:\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}