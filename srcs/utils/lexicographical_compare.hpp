/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:02:53 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/07 11:10:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

	/**
	 * @brief Returns true if the range [first1,last1) compares lexicographically
	 * less than the range [first2,last2).
	 *
	 * @param first1 Input iterators to the initial positions of the first sequence.
	 * @param last1 Input iterators to the final positions of the first sequence.
	 * @param first2 Input iterators to the initial positions of the second sequence.
	 * @param last2 Input iterators to the final positions of the second sequence.
	 * @return true if the first range compares lexicographically less than the second.
	 * false otherwise
	 */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (	InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
 		}
		return (first2!=last2);
	}

	/**
	 * @brief Returns true if the range [first1,last1) compares lexicographically
	 * less than the range [first2,last2).
	 *
	 * @param first1 Input iterators to the initial positions of the first sequence.
	 * @param last1 Input iterators to the final positions of the first sequence.
	 * @param first2 Input iterators to the initial positions of the second sequence.
	 * @param last2 Input iterators to the final positions of the second sequence.
	 * @param comp Binary function that accepts two arguments of the types pointed by
	 * the iterators, and returns a value convertible to bool.
	 * @return true if the first range compares lexicographically less than the second.
	 * false otherwise
	 */
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (	InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp)
	{
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first2, *first1))
				return true;
			++first1;
			++first2;
 		}
		return (first2!=last2);
	}

}
#endif
