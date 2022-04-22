/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:27:02 by arthur            #+#    #+#             */
/*   Updated: 2022/04/22 11:11:49 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "RBTree/rb_tree.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include <memory>

namespace ft
{
	template <	class _Key, class _T, class _Compare = std::less<_Key>,
				class _Alloc = std::allocator<ft::pair<const _Key,_T> > >
	class map
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			/*
			**	The first template parameter
			*/
			typedef				_Key												key_type;
			/*
			**	The second template parameter
			*/
			typedef				_T													mapped_type;
			/*
			**	Value type saved in node
			*/
			typedef				ft::pair<const key_type, mapped_type>				value_type;
			/*
			**	The third template parameter
			*/
			typedef				_Compare											key_compare;
			/*
			**	The fourth template parameter
			*/
			typedef				_Alloc												allocator_type;
			/**
			**	This types provide a reference to an element in the vector
			**	The default one is `value_type&`
			*/
			typedef typename	allocator_type::reference							reference;
			/**
			**	This types provide a constant reference to an element in the vector
			**	The default one is `const value_type&`
			*/
			typedef typename	allocator_type::const_reference						const_reference;
			/**
			**	This types provide a pointer to an element in the vector
			**	The default one is `value_type*`
			*/
			typedef typename	allocator_type::pointer								pointer;
			/**
			**	This types provide a constant pointer to an element in the vector
			**	The default one is `const value_type*`
			*/
			typedef typename	allocator_type::const_pointer						const_pointer;
			/**
			 *	A bidirectionnal iterator to value_type
			 * 	Can access memory in read and write
			 */
			typedef				ft::rb_tree_iterator<value_type>					iterator;
			/**
			 *	A bidirectionnal iterator to const value_type
			 *	Can access memory in read
			 */
			typedef				ft::rb_tree_const_iterator<value_type>				const_iterator;
			/**
			 *	A reverse bidirectionnal iterator to value_type
			 * 	Can access memory in read and write
			 */
			typedef				ft::reverse_iterator<iterator>						reverse_iterator;
			/**
			 *	A const reverse bidirectionnal iterator to const value_type
			 *	Can access memory in read
			 */
			typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			/**
			 * an unsigned integral type that can represent any non-negative value
			 * of difference_typean unsigned integral type that can represent any
			 * non-negative value of difference_type
			 */
			typedef typename	allocator_type::size_type							size_type;
			/**
			 * a signed integral type, identical to: iterator_traits<iterator>::difference_type
			 */
			typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			/**
			 * The node_pointer type
			 */
			typedef	typename	ft::RedBlackTree<const key_type, value_type,
												_Compare, _Alloc>::node_pointer		node_pointer;


		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
		protected:
			allocator_type													_alloc;
			_Compare														_comp;
			ft::RedBlackTree<const key_type, value_type, _Compare, _Alloc>	_rb_tree;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			**	@brief empty container constructor (default constructor)
			**	Constructs an empty container, with no elements.
			**
			**	@param comp Binary predicate that, taking two element keys as argument,
			**	returns true if the first argument goes before the second argument in the
			**	strict weak ordering it defines, and false otherwise.
			**	@param alloc Allocator object.
			*/
			explicit map (	const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type() ) :
				_alloc(alloc),
				_comp(comp),
				_rb_tree()
			{}

			/**
			 * @brief Range constructor
			 * Constructs a container with as many elements as the range [first,last),
			 * with each element constructed from its corresponding element in that range.
			 *
			 * @param first Input iterators to the initial position in a range.
			 * @param last Input iterators to the final position in a range.
			 * @param comp Binary predicate that, taking two element keys as argument,
			 *	returns true if the first argument goes before the second argument in the
			 *	strict weak ordering it defines, and false otherwise.
			 * @param alloc Allocator object.
			 */
			template <class InputIterator>
			map (	InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type() ) :
				_alloc(alloc),
				_comp(comp),
				_rb_tree()
			{
				// Insert geos here
			}

			/**
			 * @brief Copy constructor
			 * Constructs a container with a copy of each of the elements in x.
			 *
			 * @param x Another map object of the same type
			 * (with the same class template arguments Key, T, Compare and Alloc),
			 */
			map ( const map& x ) :
				_alloc(x._alloc),
				_comp(x._comp),
				_rb_tree()
			{
				// Insert goes here
			}

			/**
			 * @brief Assign "x" to this.
			 *
			 * @param x the list where get elements.
			 * @return this list.
			 */
			map& operator= ( const map& x )
			{
				if (&x == this)
					return (*this);
				this->clear();
				this->insert(x.begin(), x.end());
				return (*this);
			}

			/**
			 * @brief Destroy the map object
			 */
			~map ( void )
			{
				// Leaks goes here
			}

		/** ************************************************************************** */
		/**                                 ITERATORS                                  */
		/** ************************************************************************** */
			/**
			 * Returns an iterator pointing to the first element in the map.
			 *
			 * @return An iterator to the first element in the container.
			 */
			iterator 				begin ( void )
			{
				return (_rb_tree.minimum());
			}

			const_iterator			begin ( void ) const
			{
				return (_rb_tree.minimum());
			}

			/**
			 * Returns an iterator pointing to the last element in the map.
			 *
			 * @return An iterator to the last element in the container.
			 */
			iterator				end ( void )
			{
				return (_rb_tree.end());
			}

			const_iterator			end ( void ) const
			{
				return (_rb_tree.end());
			}

			/**
			 * @brief Return a reverse iterator pointing to the last element in the map.
			 *
			 * @return A reverse iterator to the end of the sequence container.
			 */
			reverse_iterator		rbegin ( void )
			{
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator	rbegin ( void ) const
			{
				return (reverse_iterator(this->end()));
			}

			/**
			 * @brief Return a reverse iterator pointing to the first element in the map.
			 *
			 * @return A reverse iterator to the begin of the sequence container.
			 */
			reverse_iterator		rend ( void )
			{
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator	rend ( void ) const
			{
				return (reverse_iterator(this->begin()));
			}

		/** ************************************************************************** */
		/**                                  CAPACITY                                  */
		/** ************************************************************************** */

			/**
			 * @brief Test whether container is empty
			 *
			 * @return true
			 * @return false
			 */
			bool 		empty ( void ) const
			{
				return (this->_rb_tree.getSize() == 0);
			}

			/**
			 * @brief Return container size
			 * Returns the number of elements in the map container.
			 *
			 * @return The number of elements in the container.
			 */
			size_type	size ( void ) const
			{
				return (this->_rb_tree.getSize());
			}

			/**
			 * @brief Return maximum size
			 * Returns the maximum number of elements that the map container can hold.
			 *
			 * @return The maximum number of elements a map container can hold as content.
			 */
			size_type	max_size ( void ) const
			{
				return (this->_rb_tree.max_size());
			}

		/** ************************************************************************** */
		/**                               ELEMENT ACCESS                               */
		/** ************************************************************************** */
			/**
			 * @brief Access element
			 * If k matches the key of an element in the container, the function returns a reference to its mapped value.
			 * If k does not match the key of any element in the container,
			 * the function inserts a new element with that key and returns a reference to its mapped value.
			 *
			 * @param key Key value of the element whose mapped value is accessed.
			 * @return mapped_type& A reference to the mapped value of the element with a key value equivalent to k.
			 */
			mapped_type&	operator[] ( const key_type & key )
			{
				iterator	tmp = lower_bound(key);
				tmp = insert(tmp, value_type(key, mapped_type()));
				return ((*tmp).second);
			}

		/** ************************************************************************** */
		/**                                  MODIFIERS                                 */
		/** ************************************************************************** */
			/**
			 * @brief Insert elements (single elements)
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 *
			 * @param val Value to be copied to (or moved as) the inserted element.
			 * @return eturn a pair, with its member pair::first set to an iterator pointing to either the newly inserted element
			 * or to the element with an equivalent key in the map.
			 * The pair::second element in the pair is set to true if a new element was inserted or
			 * false if an equivalent key already existed.
			 */
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				node_pointer	tmp;

				tmp = this->_rb_tree.search(val);
				if (tmp != NULL)
					return (ft::make_pair<iterator, bool>(iterator(tmp), false));
				else
				{
					tmp = this->_rb_tree.insert(val);
					return (ft::make_pair<iterator, bool>(iterator(tmp), true));
				}
			}

			/**
			 * @brief Insert elements
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 *
			 * @param position Hint for the position where the element can be inserted.
			 * @param val Value to be copied to (or moved as) the inserted element.
			 * @return an iterator pointing to either the newly inserted element or to the element
			 * that already had an equivalent key in the map.
			 */
			iterator	insert ( iterator position, const value_type& val )
			{
				node_pointer	tmp;

				(void)position;
				tmp = this->_rb_tree.search(val);
				if (tmp == NULL)
					tmp = this->_rb_tree.insert(val);
				return (iterator(tmp));
			}

			/**
			 * @brief Insert elements
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 *
			 * @param first An iterator to first element
			 * @param last An iterator to last element
			 */
			template <class InputIterator>
			void	insert ( InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0 )
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			/**
			 * @brief Erase elements
			 * Removes from the map container either a single element or a range of elements ([first,last)).
			 *
			 * @param pos Iterator pointing to a single element to be removed from the map.
			 */
			void		erase ( iterator pos )
			{
				this->_rb_tree.deleteNode(*pos);
			}

			/**
			 * @brief Erase elements
			 * Removes from the map container either a single element or a range of elements ([first,last)).
			 *
			 * @param _key Key of the element to be removed from the map.
			 * @return the number of elements erased.
			 */
			size_type	erase ( const key_type& _key )
			{
				iterator	tmp = this->_rb_tree.search(_key);
				if (tmp == NULL)
				{
					return (0);
				}
				else
				{
					erease(tmp);
					return (1);
				}
			}

			/**
			 * @brief Erase elements
			 * Removes from the map container either a single element or a range of elements ([first,last)).
			 *
			 * @param first An iterator to first element
			 * @param last An iterator to last element
			 */
			void		erase ( iterator first, iterator last )
			{
				while (first != last)
				{
					erase (*first);
					first++;
				}
			}

			iterator	lower_bound ( const key_type& _key )
			{
				iterator	low = this->begin();

				while (low != this->end() && key_compare()(low->first, _key))
					low++;
				return (low);
			}

	};
}

#endif
