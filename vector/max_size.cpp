/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:15:19 by wismith           #+#    #+#             */
/*   Updated: 2023/03/14 15:48:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	{
		std::cout << "int\n";
		NAMESPACE::vector<int>	vec;
		std::cout << "max_size : " << vec.max_size() << " int" << std::endl;
	}
	{
		std::cout << "char\n";
		NAMESPACE::vector<char>	vec;
		std::cout << "max_size : " << vec.max_size()  << " char" << std::endl;
	}
	{
		NAMESPACE::vector<unsigned int>	vec;
		std::cout << "max_size : " << vec.max_size() << " unsigned int" << std::endl;
	}
	{
		NAMESPACE::vector<long long>	vec;
		std::cout << "max_size : " << vec.max_size() << " long long" << std::endl;
	}
	{
		NAMESPACE::vector<int *>	vec;
		std::cout << "max_size : " << vec.max_size() << " int *" << std::endl;
	}
	{
		NAMESPACE::vector<char *>	vec;
		std::cout << "max_size : " << vec.max_size() << " char *" << std::endl;
	}
	{
		NAMESPACE::vector<std::string>	vec;
		std::cout << "max_size : " << vec.max_size() << " std::string" <<std::endl;
	}
	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}