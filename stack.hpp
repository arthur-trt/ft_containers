/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:46:31 by arthur            #+#    #+#             */
/*   Updated: 2022/03/23 15:25:25 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <memory>
# include "vector.hpp"
namespace ft {
	template <typename T, typename _Container = ft::vector<T> >
	class stack
	{
		public:
		/** ************************************************************************** */
		/**                                  TYPEDEFS                                  */
		/** ************************************************************************** */
			typedef	typename	_Container::value_type		value_type;
			typedef typename	_Container::reference		reference;
			typedef typename	_Container::const_reference	const_reference;
			typedef typename	_Container::size_type		size_type;
			typedef				_Container					container_type;

		protected:
		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
			/**
			 * Underline container used by stack
			 */
			container_type		c;
	};
}