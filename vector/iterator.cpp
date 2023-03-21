/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:44:42 by wismith           #+#    #+#             */
/*   Updated: 2023/03/16 13:14:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorTest.hpp"

// # define randomize (void)vec

template <class T>
void	iterator_test(NAMESPACE::vector<T> &test);
void	populate_vector(int num, NAMESPACE::vector<int> &test);
template <class InputIterator>
void	print_with_iterator(InputIterator first, InputIterator last);

int	main(void)
{
	PRINTNAMESPACE

	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::cout << "int check\n";
		NAMESPACE::vector<int>	vec;
		iterator_test(vec);
		
		populate_vector(1, vec);
		iterator_test(vec);
		
		populate_vector(5, vec);
		iterator_test(vec);

		iterator_test(vec);
		vec.clear();

		std::cout << "test vector erase range return iter:\n";
		populate_vector(10, vec);
		print_with_iterator(vec.begin(), vec.end() - 2);
		print_with_iterator(vec.begin(), vec.end());
	}
	{
		std::cout << "int check\n";
		NAMESPACE::vector<std::string>	vec;
		vec.push_back("Hello world");
		print_with_iterator(vec.begin(), vec.end());
		iterator_test(vec);
		iterator_test(vec);
		vec.clear();
		std::cout << "begin = end? " << (vec.begin() == vec.end() ? "true" : "false") << std::endl;
		print_with_iterator(vec.begin(), vec.end());
		vec.push_back("42 is awesome ");
		vec.push_back("Have you seen my squirrel? ");
		print_with_iterator(vec.begin(), vec.end());
		NAMESPACE::vector<std::string>::iterator it = vec.insert(vec.begin(), "I have python, it is like c, except c++");
		print_with_iterator(it, vec.end());
		print_with_iterator(++it, vec.end());
		print_with_iterator(it + 2, vec.end());
		print_with_iterator(it, --vec.end());
		print_with_iterator(--it, vec.end() - 2);
		print_with_iterator(vec.rbegin(), vec.rbegin());
		print_with_iterator(vec.rend(), vec.rend());
		print_with_iterator(--vec.rend(), vec.rend());
		print_with_iterator(vec.rend() - 2, vec.rend());
		print_with_iterator(vec.rbegin(), vec.rend());
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << "\n\ntime : ";
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return (0);
}

void	populate_vector(int num, NAMESPACE::vector<int> &test)
{
	std::cout << "Populating...\n";
	for (int i = 0; i < num; i++)
		test.push_back(i - 5);
}

template <class T>
void	print_forward(NAMESPACE::vector<T> &test)
{
	int	i = 0;
	for (typename NAMESPACE::vector<T>::iterator it = test.begin(); it != test.end(); it++, i++)
		std::cout << (*it == test[i] ? "true" : "false") << " ";
	std::cout << "\n";
}

template <class T>
void	print_reverse(NAMESPACE::vector<T> &test)
{
	if (!test.size())
		return ;
	size_t	i = test.size() - 1;
	for (typename NAMESPACE::vector<T>::reverse_iterator it = test.rbegin(); it != test.rend(); it++, i--)
		std::cout << (*it == test[i] ? "true" : "false") << " ";
	std::cout << "\n";
}

template <class InputIterator>
void	print_with_iterator(InputIterator first, InputIterator last)
{
	std::cout << "contents: \n";
	for (;first != last; first++)
		std::cout << *first << " ";
	std::cout << std::endl;
}

template <class T>
void	iterator_test(NAMESPACE::vector<T> &test)
{
	typename NAMESPACE::vector<T>::iterator it = test.begin();
	std::cout << "it == begin? " << (it == test.begin() ? "true" : "false") << std::endl;
	std::cout << "it == end? " << (it == test.end() ? "true" : "false") << std::endl;
	std::cout << "forward iterators :\n";
	print_forward(test);


	typename NAMESPACE::vector<T>::reverse_iterator rit = test.rbegin();
	std::cout << "rit test\n";
	std::cout << "rit == rbegin? " << (rit == test.rbegin() ? "true" : "false") << std::endl;
	std::cout << "rit == rend? " << (rit == test.rend() ? "true" : "false") << std::endl;
	std::cout << "reverse iterators :\n";
	print_reverse(test);
}