/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:50:03 by wismith           #+#    #+#             */
/*   Updated: 2023/03/28 16:38:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef STACKTEST_HPP
# define STACKTEST_HPP

# include "../config.hpp"

#	ifndef STACKHEAD
# define STACKHEAD STACKHPP
#endif

#include STACKHEAD
#include <list>
#include <stack>
#include <deque>
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

template <class T, class C>
void	display_pop_stack(NAMESPACE::stack<T, C>	&stack)
{
	for (; !stack.empty(); stack.pop())
		std::cout << stack.top() << std::endl;
}

template <class C>
void	stack_push_(NAMESPACE::stack<int, C> &stack, int num)
{
	for (int i = 0; i < num; i++)
		stack.push((i * 5) / 2);
}

#endif