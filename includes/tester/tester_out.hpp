/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_out.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:10 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 17:40:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_OUT_HPP
# define TESTER_OUT_HPP

#include <iostream>
#include "../utils/pair.hpp"

using namespace NS;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p)
{
	os << p.first << ": \"" << p.second << "\"";
	return os;
}

//template <typename T1, typename T2>
//std::ostream& operator<<(std::ostream& os, const ft::pair<T1, T2>& p)
//{
//	os << p.first << ": \"" << p.second << "\"";
//	return os;
//}

struct my_out
{
	my_out(std::ostream& out1, std::ostream& out2) : out1_(out1), out2_(out2) {}

	std::ostream& out1_;
	std::ostream& out2_;

};

// operator<<() function for most data types.
template <typename T>
my_out& operator<<(my_out& mo, T const& t)
{
	mo.out1_ << t;
	mo.out2_ << t;
	return mo;
}

my_out& operator<<(my_out& mo, std::ostream&(*f)(std::ostream&));

#endif
