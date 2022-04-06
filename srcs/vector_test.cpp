/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:36:20 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/06 11:41:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester/tester.hpp"
# include "tester/tester_out.hpp"
# include "vector.hpp"
# include <vector>
# include <fstream>
# include <list>


using namespace NS;

template <typename T>
void	vec_constructor_test(T val, my_out output)
{
	output << TEST("Empty constructor");
	vector<T>		ft_empty;
	display_vec(ft_empty, output);

	output << TEST("Fill constructor");
	vector<T>		ft_fill(50, val);
	display_vec(ft_fill, output);
}


template <typename T>
void	vec_constructor_test(std::vector<T>	vec, my_out output)
{
	output << TEST("Range constructor");
	vector<T>		ft_range(vec.begin(), vec.end());
	display_vec(ft_range, output);

	output << TEST("Copy constructor");
	vector<T>		ft_vcopy(ft_range);
	display_vec(ft_vcopy, output);
}

template <typename T>
void	vec_operatorequal_test(std::vector<T>	vec, my_out output)
{
	output << TEST("Operator =");
	vector<T>		ft_first(vec.begin(), vec.end());
	display_vec(ft_first, output);

	vector<T>		ft_second;
	display_vec(ft_second, output);
	output << L_TEST("same after =");
	ft_second = ft_first;
	display_vec(ft_first, output);
	display_vec(ft_second, output);
}

template <typename T>
void	vec_iterator_test(std::vector<T> vec, my_out output)
{
	output << TEST("Iterators");
	vector<T>		ft_vec(vec.begin(), vec.end());
	display_vec(ft_vec, output);
	output << L_TEST("begin");
	output		<< *(ft_vec.begin())		<< " "
				<< *(ft_vec.begin() + 1)	<< " "
				<< *(ft_vec.begin() + 4)	<< std::endl;
	output << L_TEST("end");
	output		<< *(ft_vec.end() - 1)		<< " "
				<< *(ft_vec.end() - 2)		<< " "
				<< *(ft_vec.end() - 4)		<< std::endl;
	output << L_TEST("rbegin");
	output		<< *(ft_vec.rbegin())		<< " "
				<< *(ft_vec.rbegin() + 1)	<< " "
				<< *(ft_vec.rbegin() + 4)	<< std::endl;
	output << L_TEST("rend");
	output		<< *(ft_vec.rend() - 1)		<< " "
				<< *(ft_vec.rend() - 2)		<< " "
				<< *(ft_vec.rend() - 4)		<< std::endl;
}

template <typename T>
void	vec_capacity_test(T val, std::vector<T> vec, my_out output)
{
	(void)vec;
	output << TEST("size");
	vector<T>	empty;
	display_vec(empty, output);
	empty.assign(8, val);
	display_vec(empty, output);
	output << TEST("max_size");
	output << "max_size : " << empty.max_size() << std::endl;
	output << TEST("resize");
	empty.resize(5);
	display_vec(empty, output);
	empty.resize(17, 25);
	display_vec(empty, output);
	empty.resize(34);
	display_vec(empty, output);
	output << TEST("empty");
	display_vec(empty, output);
	output << "Empty : " << std::boolalpha << empty.empty() << std::endl;
	empty.resize(0);
	display_vec(empty, output);
	output << "Empty : " << std::boolalpha << empty.empty() << std::endl;
	output << TEST("reserve");
	empty.reserve(15);
	display_vec(empty, output);
	empty.reserve(270);
	display_vec(empty, output);
	try
	{
		empty.reserve(empty.max_size() + 10);
	}
	catch(const std::exception& e)
	{
		output << "EXCEPTION : " << e.what() << '\n';
		display_vec(empty, output);
	}
}

//template <typename T>
//void	element_access_test(T val, vector<T> vec)
//{

//}

int	main(void)
{
	std::ofstream	vec_out;
	vec_out.open(STRINGIFY(VECFILE), std::ofstream::out);
	my_out	output(vec_out, std::cout);

	std::vector<std::string> test_str;
	test_str.push_back("Bonjour");
	test_str.push_back("comment");
	test_str.push_back("ca");
	test_str.push_back("va");
	test_str.push_back("?");

	std::vector<int>	test_int;
	for (int i = 0; i < 30; i++)
		test_int.push_back(i);

	output << CONTAINER_TEST("VECTOR");
	output << CATEGORY_TEST("Simple");
	vec_constructor_test(15, output);
	vec_constructor_test(test_int, output);
	vec_operatorequal_test<int>(test_int, output);
	vec_iterator_test<int>(test_int, output);
	vec_capacity_test<int>(42, test_int, output);
	output << CATEGORY_TEST("Complex");
	vec_constructor_test(std::string("test"), output);
	vec_constructor_test(test_str, output);
	vec_operatorequal_test<std::string>(test_str, output);
	vec_iterator_test<std::string>(test_str, output);

	return 0;
}
