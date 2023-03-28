/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:53:41 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 16:39:19 by wismith          ###   ########.fr       */
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
		std::cout << "Stack <int> constructor test:\n";

		NAMESPACE::stack<int>	stack;
		NAMESPACE::stack<int>	stack2(stack);

		display_pop_stack(stack);
		display_pop_stack(stack2);

		stack_push_(stack, 5);

		display_pop_stack(stack);

		stack_push_(stack, 15);

		stack2 = stack;

		display_pop_stack(stack);
		display_pop_stack(stack2);

		stack_push_(stack, 15);

		NAMESPACE::stack<int>	stack3(stack);

		display_pop_stack(stack3);
		
		std::cout << "End Stack <int> constructor test:\n";
	}

	{
		std::cout << "Stack <std::string> constructor test:\n";

		NAMESPACE::stack<std::string>	stack;
		NAMESPACE::stack<std::string>	stack2(stack);

		display_pop_stack(stack);
		display_pop_stack(stack2);

		for (int i = 0; i < 5; i++)
			stack.push("42 is awesome!\n");

		display_pop_stack(stack);

		for (int i = 0; i < 15; i++)
			stack.push("I'm in big crap now ...\n");

		stack2 = stack;

		display_pop_stack(stack);
		display_pop_stack(stack2);

		for (int i = 0; i < 25; i++)
			stack.push("Should fix this now ... maybe?\n");

		NAMESPACE::stack<std::string>	stack3(stack);

		display_pop_stack(stack3);
		
		std::cout << "End Stack <std::string> constructor test:\n";
	}

	{
		std::cout << "Stack <int> constructor with alternative container test:\n";

		NAMESPACE::stack<int, std::deque<int> >	stack;
		NAMESPACE::stack<int, std::deque<int> >	stack2(stack);

		display_pop_stack(stack);
		display_pop_stack(stack2);

		stack_push_(stack, 5);

		display_pop_stack(stack);

		stack_push_(stack, 15);

		stack2 = stack;

		display_pop_stack(stack);
		display_pop_stack(stack2);

		stack_push_(stack, 15);

		NAMESPACE::stack<int, std::deque<int> >	stack3(stack);

		display_pop_stack(stack3);
		
		std::cout << "End Stack <int> constructor with alternative container test\n";
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}
