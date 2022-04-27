/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:53:51 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 16:14:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include "../stack.hpp"
# include <stack>

template <class T>
void	cmp(const stack<T> &lhs, const stack<T> &rhs, my_out output)
{
	static int i = 0;

	output << "############### [" << i++ << "] ###############"  << std::endl;
	output << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	output << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	output << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <class T, class U>
void	cmp(const stack<T, U> &lhs, const stack<T, U> &rhs, my_out output)
{
	static int i = 0;

	output << "############### [" << i++ << "] ###############"  << std::endl;
	output << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	output << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	output << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename T>
void	display_stack(stack<T> &s, my_out output)
{
	output << BOLD("-> output : ") << std::endl;

	output << FG1("Content was :") << std::endl;
	while (s.size() != 0) {
			output << "- " << s.top() << std::endl;
			s.pop();
		}
	output << DIM("size : ") << s.size() << std::endl;
	output << std::endl;
}

template <typename T, typename U>
void	display_stack(stack<T, U> &s, my_out output)
{
	output << BOLD("-> output : ") << std::endl;

	output << FG1("Content was :") << std::endl;
	while (s.size() != 0) {
			output << "- " << s.top() << std::endl;
			s.pop();
		}
	output << DIM("size : ") << s.size() << std::endl;
	output << std::endl;
}

#endif
