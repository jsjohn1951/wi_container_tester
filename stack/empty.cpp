/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:14:46 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 16:39:29 by wismith          ###   ########.fr       */
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
		std::cout << "Stack <int> empty test:\n";

		NAMESPACE::stack<int>	stack;

		std::cout << "stack empty ? " << stack.empty() << std::endl;
		stack_push_(stack, 15);
		std::cout << "stack empty ? " << stack.empty() << std::endl;
		stack_push_(stack, 2);
		std::cout << "stack empty ? " << stack.empty() << std::endl;

		display_pop_stack(stack);
		std::cout << "stack empty ? " << stack.empty() << std::endl;

		stack_push_(stack, 25);
		std::cout << "stack empty ? " << stack.empty() << std::endl;
		for (; !stack.empty(); stack.pop())
			std::cout << stack.top() << std::endl;
		
		std::cout << "End Stack <int> empty test:\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}
