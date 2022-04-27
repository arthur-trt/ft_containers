/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:18 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 13:55:09 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP


#	define T_SIZE_TYPE typename NS::vector<T>::size_type

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, my_out output)
{
	output << (first < second) << std::endl;
	output << (first <= second) << std::endl;
	output << (first > second) << std::endl;
	output << (first >= second) << std::endl;
	//if (redo)
		//ft_eq_ope(second, first, 0);
}

template <typename T>
void	printSize(NS::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename NS::vector<T>::const_iterator it = vct.begin();
		typename NS::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	display_vec(vector<T> const &vec, my_out output)
{
	output << BOLD("-> output : ") << std::endl;

	output << FG1("Content :") << std::endl;
	typename vector<T>::const_iterator it1;
	for (it1 = vec.begin(); it1 != vec.end(); it1++)
		output << *it1 << " ";
	output << std::endl;

	output << DIM("size : ") << vec.size() << DIM("\tcapacity : ") << vec.capacity() << std::endl;
	output << std::endl;
}

template <typename T>
void comp_vec(ft::vector<T> const &my_vec, std::vector<T> const &r_vec)
{
	std::cout << BOLD("-> output : ") << std::endl;

	std::cout << FG1("Mine :") << std::endl;
	typename ft::vector<T>::const_iterator it1;
	for (it1 = my_vec.begin(); it1 != my_vec.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;

	std::cout << FG2("Real :") << std::endl;
	typename std::vector<T>::const_iterator it;
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
void comp_vec(std::vector<T> &r_vec, ft::vector<T> &my_vec)
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


#endif
