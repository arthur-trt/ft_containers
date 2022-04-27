/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:36:20 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 15:58:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester/tester.hpp"
# include "tester/tester_out.hpp"
# include "tester/vector_test.hpp"
# include "vector.hpp"
# include <vector>
# include <fstream>
# include <list>
# include <sys/time.h>
# include <cstdlib>

#define TESTED_TYPE int

using namespace NS;

void	is_empty(NS::vector<TESTED_TYPE> const &vct, my_out output)
{
	output << "is_empty: " << vct.empty() << std::endl;
}

void	prepost_incdec(NS::vector<TESTED_TYPE> &vct, my_out output)
{
	NS::vector<TESTED_TYPE>::iterator it = vct.begin();
	NS::vector<TESTED_TYPE>::iterator it_tmp;

	output << "Pre inc" << std::endl;
	it_tmp = ++it;
	output << *it_tmp << " | " << *it << std::endl;

	output << "Pre dec" << std::endl;
	it_tmp = --it;
	output << *it_tmp << " | " << *it << std::endl;

	output << "Post inc" << std::endl;
	it_tmp = it++;
	output << *it_tmp << " | " << *it << std::endl;

	output << "Post dec" << std::endl;
	it_tmp = it--;
	output << *it_tmp << " | " << *it << std::endl;
	output << "###############################################" << std::endl;
}


void	checkErase(	NS::vector<std::string> const &vct,
					NS::vector<std::string>::const_iterator const &it,
					my_out output)
{
	static int i = 0;
	output << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	display_vec(vct, output);
}

void	assign ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(7);
	NS::vector<TESTED_TYPE> vct_two(4);
	NS::vector<TESTED_TYPE> vct_three;
	NS::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	display_vec(vct, output);
	display_vec(vct_two, output);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	output << "\t### After assign(): ###" << std::endl;

	display_vec(vct, output);
	display_vec(vct_two, output);
	display_vec(vct_three, output);
	display_vec(vct_four, output);

	vct_four.assign(6, 84);
	display_vec(vct_four, output);

	output << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	display_vec(vct, output);
	display_vec(vct_two, output);
}

void	at ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		output << "vct.at(): " << vct.at(i) << " | ";
		output << "vct[]: " << vct[i] << std::endl;
	}
	display_vec(vct, output);

	NS::vector<TESTED_TYPE> const vct_c(vct);

	output << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	output << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		output << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		output << "Catch exception: " << e.what() << std::endl;
	}
}

void	at_const ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		output << "vct[]: " << vct[i] << std::endl;
	}
	display_vec(vct, output);

	NS::vector<TESTED_TYPE> const vct_c(vct);

	output << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	output << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	for (unsigned long int i = 0; i < vct_c.size(); ++i)
		output << "vct_c.at(): " << vct_c.at(i) << std::endl;
	try {
		output << vct_c.at(10) << std::endl;
	}
	catch (std::out_of_range &e) {
		output << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		output << "Catch exception: " << e.what() << std::endl;
	}
	display_vec(vct_c, output);
}

void	bidir_it ( my_out output )
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	NS::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	display_vec(vct, output);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	display_vec(vct, output);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	display_vec(vct, output);
}

void	copy_construct ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(5);
	NS::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

	output << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	NS::vector<TESTED_TYPE> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	NS::vector<TESTED_TYPE> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	output << "\t-- PART ONE --" << std::endl;
	display_vec(vct, output);
	display_vec(vct_range, output);
	display_vec(vct_copy, output);

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	output << "\t-- PART TWO --" << std::endl;
	display_vec(vct, output);
	display_vec(vct_range, output);
	display_vec(vct_copy, output);
}

void	erase ( my_out output )
{
	NS::vector<std::string> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	display_vec(vct, output);

	checkErase(vct, vct.erase(vct.begin() + 2), output);

	checkErase(vct, vct.erase(vct.begin()), output);
	checkErase(vct, vct.erase(vct.end() - 1), output);

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3), output);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1), output);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	display_vec(vct, output);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()), output);

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	display_vec(vct, output);
	checkErase(vct, vct.erase(vct.begin(), vct.end()), output);
}

void	insert ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(10);
	NS::vector<TESTED_TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	display_vec(vct, output);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	display_vec(vct2, output);

	vct2.insert(vct2.end() - 2, 42);
	display_vec(vct2, output);

	vct2.insert(vct2.end(), 2, 84);
	display_vec(vct2, output);

	vct2.resize(4);
	display_vec(vct2, output);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	display_vec(vct2, output);

	display_vec(vct, output);
}

void	insert2 ( my_out output )
{
	NS::vector<TESTED_TYPE> vct(5);
	NS::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	display_vec(vct, output);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	display_vec(vct2, output);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	display_vec(vct2, output);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	display_vec(vct2, output);

	output << "insert return:" << std::endl;

	output << *vct2.insert(vct2.end(), 42) << std::endl;
	output << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	output << "----------------------------------------" << std::endl;

	display_vec(vct2, output);
}

void	ite ( my_out output )
{
	const int size = 5;
	NS::vector<TESTED_TYPE> vct(size);
	NS::vector<TESTED_TYPE>::iterator it = vct.begin();
	NS::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	prepost_incdec(vct, output);

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	output << *(it += 2) << std::endl;
	output << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	output << "const_ite +=: " << *(ite += 2) << std::endl;
	output << "const_ite -=: " << *(ite -= 2) << std::endl;

	output << "(it == const_it): " << (ite == it) << std::endl;
	output << "(const_ite - it): " << (ite - it) << std::endl;
	output << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	display_vec(vct, output);
}

void	ite_arrow ( my_out output )
{
	const int size = 5;
	NS::vector<foo<int> > vct(size);
	NS::vector<foo<int> >::iterator it(vct.begin());
	NS::vector<foo<int> >::const_iterator ite(vct.end());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	display_vec(vct, output);

	it = vct.begin();
	ite = vct.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;
}

void	ite_relationnal_op ( my_out output )
{
	const int size = 5;
	NS::vector<foo<int> > vct(size);
	NS::vector<foo<int> >::iterator it_0(vct.begin());
	NS::vector<foo<int> >::iterator it_1(vct.end());
	NS::vector<foo<int> >::iterator it_mid;

	NS::vector<foo<int> >::const_iterator cit_0 = vct.begin();
	NS::vector<foo<int> >::const_iterator cit_1;
	NS::vector<foo<int> >::const_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	display_vec(vct, output);
	it_0 = vct.begin();
	cit_1 = vct.end();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	output << std::boolalpha;
	output << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	output << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid, output);
	ft_eq_ope(it_0, it_1, output);
	ft_eq_ope(it_1 - 3, it_mid, output);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid, output);
	ft_eq_ope(cit_0, cit_1, output);
	ft_eq_ope(cit_1 - 3, cit_mid, output);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid, output);
	ft_eq_ope(it_mid, cit_0 + 3, output);
	ft_eq_ope(it_0, cit_1, output);
	ft_eq_ope(it_1, cit_0, output);
	ft_eq_ope(it_1 - 3, cit_mid, output);
	ft_eq_ope(it_mid, cit_1 - 3, output);

}

void	rite ( my_out output )
{
	const int size = 5;
	NS::vector<TESTED_TYPE> vct(size);
	NS::vector<TESTED_TYPE>::iterator it_ = vct.begin();
	NS::vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	display_vec(vct, output);

	output << (it_ == it.base()) << std::endl;
	output << (it_ == (it + 3).base()) << std::endl;

	output << *(it.base() + 1) << std::endl;
	output << *(it - 3) << std::endl;
	output << *(it - 3).base() << std::endl;
	it -= 3;
	output << *it.base() << std::endl;

	output << "TEST OFFSET" << std::endl;
	output << *(it) << std::endl;
	output << *(it).base() << std::endl;
	output << *(it - 0) << std::endl;
	output << *(it - 0).base() << std::endl;
	output << *(it - 1).base() << std::endl;
}

void	rite2 ( my_out output )
{
	const int size = 5;
	NS::vector<TESTED_TYPE> vct(size);
	NS::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	NS::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	output << *(it += 2) << std::endl;
	output << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	output << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	output << "(it == const_it): " << (ite == it) << std::endl;
	output << "(const_ite - it): " << (ite - it) << std::endl;
	output << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	display_vec(vct, output);
}

void	size ( my_out output )
{
	const int start_size = 7;
	NS::vector<TESTED_TYPE> vct(start_size, 20);
	NS::vector<TESTED_TYPE> vct2;
	NS::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	display_vec(vct, output);

	vct.resize(10, 42);
	display_vec(vct, output);

	vct.resize(18, 43);
	display_vec(vct, output);
	vct.resize(10);
	display_vec(vct, output);
	vct.resize(23, 44);
	display_vec(vct, output);
	vct.resize(5);
	display_vec(vct, output);
	vct.reserve(5);
	vct.reserve(3);
	display_vec(vct, output);
	vct.resize(87);
	vct.resize(5);
	display_vec(vct, output);

	is_empty(vct2, output);
	vct2 = vct;
	is_empty(vct2, output);
	vct.reserve(vct.capacity() + 1);
	display_vec(vct, output);
	display_vec(vct2, output);

	vct2.resize(0);
	is_empty(vct2, output);
	display_vec(vct2, output);
}

void	swap ( my_out output )
{
	NS::vector<TESTED_TYPE> foo(3, 15);
	NS::vector<TESTED_TYPE> bar(5, 42);

	NS::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
	NS::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

	output << "BEFORE SWAP" << std::endl;

	output << "foo contains:" << std::endl;
	display_vec(foo, output);
	output << "bar contains:" << std::endl;
	display_vec(bar, output);

	foo.swap(bar);

	output << "AFTER SWAP" << std::endl;

	output << "foo contains:" << std::endl;
	display_vec(foo, output);
	output << "bar contains:" << std::endl;
	display_vec(bar, output);

	output << "Iterator validity:" << std::endl;
	output << (it_foo == bar.begin()) << std::endl;
	output << (it_bar == foo.begin()) << std::endl;
}

void	big_insert_del ( void )
{
	NS::vector<int>	vec;

	srand(42);

	for	(size_t i = 0; i < 1000; i++)
	{
		vec.insert(vec.begin(), i);
	}

	for (size_t i = 0; i < 900; i++)
	{
		vec.erase(vec.begin() + (rand() % (vec.size() - 1)));
	}
}

int	main(void)
{
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	std::ofstream	vec_out;
	vec_out.open(STRINGIFY(VECFILE), std::ofstream::out);
	my_out	output(vec_out, std::cout);

	output << CONTAINER_TEST("VECTOR");
	output << CATEGORY_TEST("Assign");
	assign(output);
	output << CATEGORY_TEST("At");
	at(output);
	output << CATEGORY_TEST("At const");
	at_const(output);
	output << CATEGORY_TEST("Iterator bidirectionnal");
	bidir_it(output);
	output << CATEGORY_TEST("Copy constructor");
	copy_construct(output);
	output << CATEGORY_TEST("Erase");
	erase(output);
	output << CATEGORY_TEST("Insert");
	insert(output);
	insert2(output);
	output << CATEGORY_TEST("Iterator");
	ite(output);
	ite_arrow(output);
	ite_relationnal_op(output);
	output << CATEGORY_TEST("Reverse iterator");
	rite(output);
	rite2(output);
	output << CATEGORY_TEST("Size");
	size(output);
	output << CATEGORY_TEST("Swap");
	swap(output);

	big_insert_del();

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds*1e-6;

	output << "Time elapsed : " << elapsed << std::endl;

	return 0;
}
