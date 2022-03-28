/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:52:42 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/28 11:05:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.hpp"
#include "tester/tester.hpp"
#include <vector>

std::string str_center(int width, const std::string& str) {
	int len = str.length();
	if(width < len)
	{
		return str;
	}

	int diff = width - len;
	int pad1 = diff/2;
	int pad2 = diff - pad1;

	return std::string(pad1, ' ') + str + std::string(pad2, ' ');
}


// Allow for std::endl to be used with a my_out
my_out& operator<<(my_out& mo, std::ostream&(*f)(std::ostream&))
{
	mo.out1_ << f;
	mo.out2_ << f;
	return mo;
}
