/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:43:37 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/04 17:33:54 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "utils.hpp"

namespace ft {

	/**
	 * @brief std::iterator_traits is the type trait class that provides uniform
	 * interface to the properties of LegacyIterator types.
	 * This makes it possible to implement algorithms only in terms of iterators.
	 * The template can be specialized for user-defined iterators so that the information
	 * about the iterator can be retrieved even if the type does not provide the usual typedefs.
	 */

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template< class T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef const T									pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <typename Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	distance (Iterator first, Iterator last)
	{
		return (distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category()));
	}

	template <typename RandomAccessIterator>
	typename ft::iterator_traits<RandomAccessIterator>::difference_type
	distance (RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	diff;
		for (diff = 0; first != last; ++first, ++diff) {
			;
		}
		return (diff);
	}

}
#endif
