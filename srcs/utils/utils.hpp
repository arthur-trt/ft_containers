/** ************************************************************************** */
/**                                                                            */
/**                                                        :::      ::::::::   */
/**   utils.hpp                                          :+:      :+:    :+:   */
/**                                                    +:+ +:+         +:+     */
/**   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/**                                                +#+#+#+#+#+   +#+           */
/**   Created: 2022/03/02 15:09:18 by atrouill          #+#    #+#             */
/**   Updated: 2022/03/02 15:31:47 by atrouill         ###   ########.fr       */
/**                                                                            */
/** ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <string>
# include <sstream>
# include <typeinfo>
# include <iostream>

namespace ft {

	template <typename T>
	std::string	to_string(T n)
	{
		std::ostringstream ss;
		ss << n;
		return (ss.str());
	}


	//class random_access_iterator_tag { };
	//class bidirectional_iterator_tag { };
	//class forward_iterator_tag { };
	//class input_iterator_tag { };
	//class output_iterator_tag { };

	///  Marking input iterators.
	struct input_iterator_tag {};
	///  Marking output iterators.
	struct output_iterator_tag {};
	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag {};
	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	/// Random-access iterators support a superset of bidirectional iterator
	/// operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef	T			value_type;
			typedef	Distance	difference_type;
			typedef	Pointer		pointer;
			typedef	Reference	reference;
			typedef Category	iterator_category;
		};

}

#endif
