/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:19:54 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/22 14:09:47 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "utils.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template <typename _Iterator>
	class reverse_iterator
	 :
	 	public ft::iterator<typename ft::iterator_traits<_Iterator>::iterator_category,
	 						typename ft::iterator_traits<_Iterator>::value_type,
	 						typename ft::iterator_traits<_Iterator>::difference_type,
	 						typename ft::iterator_traits<_Iterator>::pointer,
	 						typename ft::iterator_traits<_Iterator>::reference>
	{
		public:
		/** ************************************************************************** */
		/**                                  TYPEDEFS                                  */
		/** ************************************************************************** */
			/**
			 * Iterator type
			 */
			typedef				_Iterator												iterator_type;
			/**
			**	Iterator category
			*/
			typedef typename	ft::iterator_traits<_Iterator>::iterator_category	iterator_category;
			/**
			**	Difference type
			*/
			typedef typename	ft::iterator_traits<_Iterator>::difference_type		difference_type;
			/**
			**	Pointer
			*/
			typedef typename	ft::iterator_traits<_Iterator>::pointer				pointer;
			/**
			**	Reference
			*/
			typedef typename	ft::iterator_traits<_Iterator>::reference			reference;

			typedef typename	ft::iterator_traits<_Iterator>::value_type			value_type;

		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
		protected:
			iterator_type	_curr;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			 *  The default constructor default-initializes member @p _curr.
			 *  If it is a pointer, that means it is zero-initialized.
			 */
			reverse_iterator() :
				_curr()
			{}

			/**
			 *  This %iterator will move in the opposite direction that @p other does.
			 */
			explicit reverse_iterator(iterator_type other) :
				_curr(other)
			{}

			/**
			 *  The copy constructor is normal.
			 */
			reverse_iterator (const reverse_iterator& other) :
				_curr(other._curr)
			{}

			/**
			 *  A reverse_iterator across other types can be copied in the normal
			 *  fashion.
			 */
			template<class _Iter>
			reverse_iterator(const reverse_iterator<_Iter>& x) :
				_curr(x.base())
			{}

			reverse_iterator	&operator=( const reverse_iterator & src )
			{
				if (*this != src)
					this->_curr = src.base();
				return (*this);
			}

		/** ************************************************************************** */
		/**                                  MEMBERS                                   */
		/** ************************************************************************** */
			/**
			**	@brief	Convert a reverse iterator in an iterator
			**
			**	@return	The iterator
			*/
			iterator_type	base() const
			{
				return (this->_curr);
			}

		/** ************************************************************************** */
		/**                                 OPERATORS                                  */
		/** ************************************************************************** */
			/**
			**	@brief Dereference the rvalue
			**
			**	@return The rvalue (where point the pointer)
			*/
			reference	operator*( void ) const
			{
				iterator_type	tmp = _curr;
				return (*--tmp);
			}

			/**
			**	@brief Give the pointer to the lvalue
			**
			**	@return The lvalue (pointer to the element)
			*/
			pointer		operator->( void ) const
			{
				return (&(operator*()));
			}

			/**
			**	@brief	Increment the pointer to the next value
			**
			**	@return A reference to the next value
			*/
			reverse_iterator	&operator++( void )
			{
				--this->_curr;
				return (*this);
			}

			/**
			**	@brief Preincrement the pointer to the next value
			**
			**	@return A reference to the current element
			*/
			reverse_iterator	operator++( int )
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			/**
			**	@brief	Decrement the pointer to the next value
			**
			**	@return A reference to the previous value
			*/
			iterator_type	&operator--( void )
			{
				this->_curr++;
				return (*this);
			}

			/**
			**	@brief Predecrement the pointer to the next value
			**
			**	@return A reference to the current element
			*/
			reverse_iterator	operator--( int )
			{
				iterator_type tmp(*this);
				++this->_curr;
				return (tmp);
			}

			/**
			**	@brief Access the element at this + n
			**
			**	@param	n	The number of element to "skip"
			**
			**	@return The random access iterator who point at this + n
			*/
			reverse_iterator	operator+( difference_type n ) const
			{
				return (reverse_iterator(this->_curr - n));
			}

			/**
			**	@brief Access the element at this - n
			**
			**	@param	n	The number of element to "skip"
			**
			**	@return The random access iterator who point at this + n
			*/
			reverse_iterator	operator-( difference_type n ) const
			{
				return (reverse_iterator(this->_curr + n));
			}

			/**
			**	@brief Give the reference to the random access iterator where
			**	the actuel element is this + n
			**
			**	@param n	Number of elements to "skip"
			**
			**	@return		Random access iterator to the new value
			*/
			reverse_iterator	&operator+=( difference_type n )
			{
				this->_curr -= n;
				return (*this);
			}

			/**
			**	@brief Give the reference to the random access iterator where
			**	the actuel element is this - n
			**
			**	@param n	Number of elements to "skip"
			**
			**	@return		Random access iterator to the new value
			*/
			reverse_iterator	&operator-=( difference_type n )
			{
				this->_curr += n;
				return (*this);
			}

			reference	operator[]( difference_type n ) const
			{
				return *(*this + n);
			}

			operator reverse_iterator<const _Iterator> () const
			{
				return (reverse_iterator<const _Iterator>(this->_curr));
			}

	};
	/** ************************************************************************** */
	/**                           COMPARAISON OPERATORS                            */
	/** ************************************************************************** */

	/**
	**	@brief	Check if lhs and rhs are equal in memory
	**
	**	@param	lhs	The random access memory to compare
	**	@param	rhs	The random acces with who check
	**
	**	@return	True if equal, false otherwise
	*/
	template <typename T_L, typename T_R>
	inline bool operator==(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( lhs.base() == rhs.base() );
	}

	/**
	 * @brief Check if lhs is inferior as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if inferior, false otherwise
	 */
	template <typename T_L, typename T_R>
	inline bool operator<(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( rhs.base() < lhs.base() );
	}

	/**
	**	@brief	Check if lhs and rhs are different in memory
	**
	**	@param	lhs	The random access memory to compare
	**	@param	rhs	The random acces with who check
	**
	**	@return	True if different, false otherwise
	*/
	template <typename T_L, typename T_R>
	inline bool operator!=(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( lhs.base() != rhs.base() );
	}

	/**
	 * @brief Check if lhs is superior as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if superior, false otherwise
	 */
	template <typename T_L, typename T_R>
	inline bool	operator>(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( rhs < lhs );
	}

	/**
	 * @brief Check if lhs is inferior or equal as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if inferior or equal, false otherwise
	 */
	template <typename T_L, typename T_R>
	inline bool operator<=(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( !(rhs < lhs) );
	}

	/**
	 * @brief Check if lhs is superior or equal as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if superior or equal, false otherwise
	 */
	template <typename T_L, typename T_R>
	inline bool	operator>=(	const ft::reverse_iterator<T_L> lhs,
							const ft::reverse_iterator<T_R> rhs)
	{
		return ( !(lhs < rhs) );
	}

	/**
	 * @brief For operation like a - b
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 * @return The difference beetween two
	 */
	template <typename T_L, typename T_R>
	inline typename ft::reverse_iterator<T_L>::difference_type
	operator-(	const ft::reverse_iterator<T_L> lhs,
				const ft::reverse_iterator<T_R> rhs)
	{
		return ( rhs.base() - lhs.base() );
	}

	template<typename _Iterator>
	inline reverse_iterator<_Iterator>
	operator+(	typename reverse_iterator<_Iterator>::difference_type __n,
				const reverse_iterator<_Iterator>& __x)
	{
		return reverse_iterator<_Iterator>(__x.base() - __n);
	}

}

#endif
