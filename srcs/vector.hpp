/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:37:24 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/02 17:03:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "random_access_iterator.hpp"

namespace ft {

	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		/* ************************************************************************** */
		/*                                  TYPEDEFS                                  */
		/* ************************************************************************** */
			/*
			**	First template parameter (T)
			*/
			typedef				T								value_type;
			/*
			**	Second template parameter (Alloc)
			*/
			typedef				Alloc							allocator_type;
			/*
			**	This types provide a reference to an element in the vector
			**	The default one is `value_type&`
			*/
			typedef typename	allocator_type::reference		reference;
			/*
			**	This types provide a constant reference to an element in the vector
			**	The default one is `const value_type&`
			*/
			typedef typename	allocator_type::const_reference	const_reference;
			/*
			**	This types provide a pointer to an element in the vector
			**	The default one is `value_type*`
			*/
			typedef typename	allocator_type::pointer			pointer;
			/*
			**	This types provide a constant pointer to an element in the vector
			**	The default one is `const value_type*`
			*/
			typedef typename	allocator_type::const_pointer	const_pointer;

			typedef typename	allocator_type::size_type		size_type;


		/* ************************************************************************** */
		/*                              PRIVATE MEMBERS                               */
		/* ************************************************************************** */
		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;

		public:
		/* ************************************************************************** */
		/*                                CONSTRUCTORS                                */
		/* ************************************************************************** */
			/*
			**	@brief Default
			**	Empty container contructor (dafault one)
			**	Constructs an empty container with no elements
			**
			**	@param alloc	Allocator object
			**	Container keep a copy of the allocator as the second parameter
			*/
			explicit vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(0),
				_end(0),
				_end_capacity(0)
			{}

			/*
			**	@brief Fill.
			**	Construct a container with `n` elements. Each elements is a copy of `val`
			**
			**	@param n 	Number of elements to create
			**	@param val	Value of each elements
			**	@param alloc Allocator objects
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				_start = _alloc.allocate(n);
				_end_capacity = _start + n;
				_end = _start;
				while(n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}

			/*
			**	@brief Range
			**	Constructs a container with as many elements as the range [first, last)
			**	with each element constructed from its correcponding element in that range,
			**	in the same order.
			**
			**	@param	first	An iterator to the first value
			**	@param	last	An iterator to the last value
			**	@param	alloc	Allocator object
			*/
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(0),
				_end_capacity(0),
				_end(0)
			{
				/*
				**	@todo Add function for insert or push back
				*/
			}
	};
}

#endif
