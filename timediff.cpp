/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timediff.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:20:28 by wismith           #+#    #+#             */
/*   Updated: 2023/03/27 19:12:28 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "timediff: err: Incorrect num Args!\n";
		return (1);
	}
	char	*num2;
	double	d1 = strtod(argv[1], &num2);
	double	d2 = strtod(num2, NULL) * 20;
	std::cout << (d1 > d2 ? "1" : "0");
	return (0);
}
