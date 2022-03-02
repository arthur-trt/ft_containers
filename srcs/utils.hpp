/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:09:18 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/02 15:31:47 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {


	class random_access_iterator_tag { };
	class bidirectional_iterator_tag { };
	class forward_iterator_tag { };
	class input_iterator_tag { };
	class output_iterator_tag { };

	template <	class Category, class T, class Distance = std::ptrdiff_t,
				class Pointer = T*, class Reference = T&	>
		struct iterator {
			typedef	T			value_type;
			typedef	Distance	difference_type;
			typedef	Pointer		pointer;
			typedef	Reference	reference;
			typedef Category	iterator_category;
		};

}

#endif
