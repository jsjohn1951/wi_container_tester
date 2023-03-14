/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:58:34 by wismith           #+#    #+#             */
/*   Updated: 2023/03/15 00:57:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VECTORTEST_HPP
# define VECTORTEST_HPP

#	ifndef VECHEAD
# define VECHEAD "../../vector/vector.hpp"
#endif

#include VECHEAD
#include <vector>
#include <list>
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

#endif