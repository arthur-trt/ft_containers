/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:46:31 by arthur            #+#    #+#             */
/*   Updated: 2022/03/23 17:13:23 by atrouill         ###   ########.fr       */
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

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			 * @brief Default
			 * Constructs a stack container adaptor object.
			 *
			 * @param ctnr	Container object.
			 */
			explicit stack ( const container_type& ctnr = container_type() ) :
				c(ctnr)
			{}

		/** ************************************************************************** */
		/**                              MEMBER FUNCTIONS                              */
		/** ************************************************************************** */
			/**
			 * @brief Returns whether the stack is empty: i.e. whether its size is zero.
			 *
			 * This member function effectively calls member empty of the underlying container object.
			 */
			bool				empty () const
			{
				return (c.empty());
			}

			/**
			 * @brief Returns the number of elements in the stack.
			 *
			 * This member function effectively calls member size of the underlying container object.
			 */
			size_type			size () const
			{
				return (c.size());
			}

			/**
			 * @brief Returns a reference to the top element in the stack.
			 *
			 * Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
			 * This member function effectively calls member back of the underlying container object.
			 *
			 * @return value_type& A reference to the top element in the stack.
			 */
			value_type			&top ()
			{
				return (c.back());
			}

			const value_type	&top () const
			{
				return (c.back());
			}

			/**
			 * @brief Inserts a new element at the top of the stack, above its current top element.
			 * The content of this new element is initialized to a copy of val.
			 * This member function effectively calls the member function push_back of the underlying container object.
			 *
			 * @param val Value to which the inserted element is initialized.
			 */
			void	push ( const value_type& val )
			{
				c.push_back(val);
			}

			/**
			 * @brief Removes the element on top of the stack, effectively reducing its size by one.
			 * The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.
			 * This calls the removed element's destructor.
			 * This member function effectively calls the member function pop_back of the underlying container object.
			 */
			void	pop ()
			{
				c.pop_back();
			}

		/** ************************************************************************** */
		/**                              FRIEND TEMPLATE                               */
		/** ************************************************************************** */
			/**
			 * Friend is needed here. Because both stack are acceded and we need to access to the private/protected
			 * data of each underline container
			 */
			template<typename T1, typename _Container1>
			friend bool	operator== ( const stack<T1, _Container1>&, const stack<T1, _Container1>& );

			template<typename T1, typename _Container1>
			friend bool operator< ( const stack<T1, _Container1>&, const stack<T1, _Container1>& );
	};
	/** ************************************************************************** */
	/**                            RELATIONAL OPERATORS                            */
	/** ************************************************************************** */
	 /**
	 *  @brief  Stack equality comparison.
	 *  @param  __x  A %stack.
	 *  @param  __y  A %stack of the same type as @a __x.
	 *  @return  True iff the size and elements of the stacks are equal.
	 *
	 *  This is an equivalence relation.  Complexity and semantics
	 *  depend on the underlying sequence type, but the expected rules
	 *  are: this relation is linear in the size of the sequences, and
	 *  stacks are considered equivalent if their sequences compare
	 *  equal.
	 */
	template<typename T, typename _Container>
	inline bool operator== ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return __x.c == __y.c;
	}

	/**
	 *  @brief  Stack ordering relation.
	 *  @param  __x  A %stack.
	 *  @param  __y  A %stack of the same type as @a x.
	 *  @return  True iff @a x is lexicographically less than @a __y.
	 *
	 *  This is an total ordering relation.  Complexity and semantics
	 *  depend on the underlying sequence type, but the expected rules
	 *  are: this relation is linear in the size of the sequences, the
	 *  elements must be comparable with @c <, and
	 *  std::lexicographical_compare() is usually used to make the
	 *  determination.
	 */
	template<typename T, typename _Container>
	inline bool	operator< ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return __x.c < __y.c;

	}

	/// Based on operator==
	template<typename T, typename _Container>
	inline bool	operator!= ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return !(__x == __y);

	}

	/// Based on operator<
	template<typename T, typename _Container>
	inline bool	operator> ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return __y < __x;
	}

	/// Based on operator<
	template<typename T, typename _Container>
	inline bool	operator<= ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return !(__y < __x);
	}

	/// Based on operator<
	template<typename T, typename _Container>
	inline bool	operator>= ( const stack<T, _Container>& __x, const stack<T, _Container>& __y )
	{
		return !(__x < __y);
	}
}
