/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:36:31 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/25 15:32:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include "vector.hpp"
# include "test_define.hpp"
# include <vector>
# include <string>



template <typename T>
void display_vec(ft::vector<T> &my_vec, std::vector<T> &r_vec)
{
	std::cout << BOLD("-> output : ") << std::endl;

	std::cout << FG1("Mine :") << std::endl;
	typename ft::vector<T>::iterator it1;
	for (it1 = my_vec.begin(); it1 != my_vec.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;

	std::cout << FG2("Real :") << std::endl;
	typename std::vector<T>::iterator it;
	for (it = r_vec.begin(); it != r_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << DIM("STD\tsize : ") << r_vec.size() << DIM("\tcapacity : ") << r_vec.capacity() << std::endl;
	std::cout << DIM("FT\tsize : ") << my_vec.size() << DIM("\tcapacity : ") << my_vec.capacity() << std::endl;
	std::cout << std::endl;

	if (r_vec.size() != my_vec.size() || r_vec.capacity() != my_vec.capacity())
		getwchar();
}

template <typename T>
void display_vec(std::vector<T> &r_vec, ft::vector<T> &my_vec)
{
	std::cout << BOLD("-> output : ") << std::endl;

	std::cout << FG1("Mine :") << std::endl;
	typename ft::vector<T>::iterator it1;
	for (it1 = my_vec.begin(); it1 != my_vec.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;

	std::cout << FG2("Real :") << std::endl;
	typename std::vector<T>::iterator it;
	for (it = r_vec.begin(); it != r_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << DIM("STD\tsize : ") << r_vec.size() << DIM("\tcapacity : ") << r_vec.capacity() << std::endl;
	std::cout << DIM("FT\tsize : ") << my_vec.size() << DIM("\tcapacity : ") << my_vec.capacity() << std::endl;
	std::cout << std::endl;

	if (r_vec.size() != my_vec.size() || r_vec.capacity() != my_vec.capacity())
		getwchar();
}

std::string str_center(int width, const std::string& str);

/*
**	VECTOR_TESTS
*/
int	main_vector(void);

#endif
