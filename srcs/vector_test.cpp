/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:36:20 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/25 15:56:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester/tester.hpp"
# include "vector.hpp"
# include <vector>
# include <list>

template <typename T>
void	vec_constructor_test(T val)
{
	TEST("Empty constructor");
	std::vector<T>		std_empty;
	ft::vector<T>		ft_empty;
	display_vec(std_empty, ft_empty);

	TEST("Fill constructor");
	std::vector<T>		std_fill(50, val);
	ft::vector<T>		ft_fill(50, val);
	display_vec(std_fill, ft_fill);
}


template <typename T>
void	vec_constructor_test(std::vector<T>	vec)
{
	TEST("Range constructor");
	std::vector<T>		std_range(vec.begin(), vec.end());
	ft::vector<T>		ft_range(vec.begin(), vec.end());
	display_vec(std_range, ft_range);

	TEST("Copy constructor");
	std::vector<T>		std_copy(std_range);
	ft::vector<T>		ft_vcopy(ft_range);
	display_vec(std_range, ft_range);
}

template <typename T>
void	vec_operatorequal_test(std::vector<T>	vec)
{
	TEST("Operator =");
	std::vector<T>		std_first(vec.begin(), vec.end());
	ft::vector<T>		ft_first(vec.begin(), vec.end());
	display_vec(std_first, ft_first);


	std::vector<T>		std_second;
	ft::vector<T>		ft_second;
	display_vec(std_second, ft_second);

	L_TEST("same after =");
	std_second = std_first;
	ft_second = ft_first;
	display_vec(std_first, ft_first);
	display_vec(std_second, ft_second);

}

template <typename T>
void	vec_iterator_test(std::vector<T> vec)
{
	TEST("Iterators");
	std::vector<T>		std_vec(vec.begin(), vec.end());
	ft::vector<T>		ft_vec(vec.begin(), vec.end());
	display_vec(std_vec, ft_vec);
	L_TEST("begin");
	std::cout	<< *(std_vec.begin())		<< " "
				<< *(std_vec.begin() + 1)	<< " "
				<< *(std_vec.begin() + 4)	<< std::endl;
	std::cout	<< *(ft_vec.begin())		<< " "
				<< *(ft_vec.begin() + 1)	<< " "
				<< *(ft_vec.begin() + 4)	<< std::endl;
	L_TEST("end");
	std::cout	<< *(std_vec.end() - 1)		<< " "
				<< *(std_vec.end() - 2)		<< " "
				<< *(std_vec.end() - 4)		<< std::endl;
	std::cout	<< *(ft_vec.end() - 1)		<< " "
				<< *(ft_vec.end() - 2)		<< " "
				<< *(ft_vec.end() - 4)		<< std::endl;
	L_TEST("rbegin");
	std::cout	<< *(std_vec.rbegin())		<< " "
				<< *(std_vec.rbegin() + 1)	<< " "
				<< *(std_vec.rbegin() + 4)	<< std::endl;
	std::cout	<< *(ft_vec.rbegin())		<< " "
				<< *(ft_vec.rbegin() + 1)	<< " "
				<< *(ft_vec.rbegin() + 4)	<< std::endl;
	L_TEST("rend");
	std::cout	<< *(std_vec.rend() - 1)	<< " "
				<< *(std_vec.rend() - 2)	<< " "
				<< *(std_vec.rend() - 4)	<< std::endl;
	std::cout	<< *(ft_vec.rend() - 1)		<< " "
				<< *(ft_vec.rend() - 2)		<< " "
				<< *(ft_vec.rend() - 4)		<< std::endl;
}

void	vec_capacity_test(void)
{
	TEST("size");

}

int	main_vector(void)
{
	std::vector<std::string> test_str;
	test_str.push_back("Bonjour");
	test_str.push_back("comment");
	test_str.push_back("ca");
	test_str.push_back("va");
	test_str.push_back("?");

	std::vector<int>	test_int;
	for (int i = 0; i < 30; i++)
		test_int.push_back(i);

	CONTAINER_TEST("VECTOR");
	CATEGORY_TEST("Simple");
	vec_constructor_test(15);
	vec_constructor_test(test_int);
	WAIT_USER;
	vec_operatorequal_test<int>(test_int);
	WAIT_USER;
	vec_iterator_test<int>(test_int);
	WAIT_USER;

	CATEGORY_TEST("Complex");
	vec_constructor_test(std::string("test"));
	vec_constructor_test(test_str);
	WAIT_USER;
	vec_operatorequal_test<std::string>(test_str);
	WAIT_USER;
	vec_iterator_test<std::string>(test_str);

	return 0;
}
