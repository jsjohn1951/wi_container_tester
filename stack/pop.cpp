/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:18 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 16:53:00 by wismith          ###   ########.fr       */
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
		std::cout << "Stack <int> pop test:\n";

		NAMESPACE::stack<int>	stack;

		display_pop_stack(stack);

		stack_push_(stack, 10);
		display_pop_stack(stack);
		stack_push_(stack, 10);
		stack.pop();
		display_pop_stack(stack);
		stack_push_(stack, 10);
		for (int i = 0; i < 5; i++)
			stack.pop();
		display_pop_stack(stack);
		
		std::cout << "End Stack <int> pop test:\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}