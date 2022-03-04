/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:19:20 by arthur            #+#    #+#             */
/*   Updated: 2022/03/04 14:07:15 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "utils/utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
		/** ************************************************************************** */
		/**                                  TYPEDEFS                                  */
		/** ************************************************************************** */

			/**
			**	Iterator category
			*/
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			/**
			**	Value type
			*/
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			/**
			**	Difference type
			*/
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			/**
			**	Pointer
			*/
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			/**
			**	Reference
			*/
			typedef typename	ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;

		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
		private:
			pointer	_elem;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */

			/**
			**	@brief Default.
			**	Default null constructor. Point on null
			*/
			random_access_iterator(void) :
				_elem(0)
			{}

			/**
			**	@brief Constructor from pointer:
			**	Construct a random access iterator and point on elem passed in argument
			**
			**	@param elem pointer to the element to iterate
			*/
			random_access_iterator(pointer elem) :
				_elem(elem)
			{}

			/**
			**	@brief Constructor by copy
			**	Construct a random access iterator by copy
			**
			**	@param rhs	RAI to copy
			*/
			random_access_iterator(const random_access_iterator & other) :
				_elem(other._elem)
			{}

			/**
			**	@brief Destructor
			**	Does nothing
			*/
			~random_access_iterator()
			{}

		/** ************************************************************************** */
		/**                                  MEMBERS                                   */
		/** ************************************************************************** */

			/**
			**	@brief	Convert a reverse iterator in an iterator
			**
			**	@return	The iterator
			*/
			pointer	base() const
			{
				return (this->_elem);
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
				return (*this->_elem);
			}

			/**
			**	@brief Give the pointer to the lvalue
			**
			**	@return The lvalue (pointer to the element)
			*/
			pointer		operator->( void ) const
			{
				return (&(this->_elem));
			}

			/**
			**	@brief	Increment the pointer to the next value
			**
			**	@return A reference to the next value
			*/
			random_access_iterator	&operator++( void )
			{
				this->_elem++;
				return (*this);
			}

			/**
			**	@brief Preincrement the pointer to the next value
			**
			**	@return A reference to the current element
			*/
			random_access_iterator	operator++( int )
			{
				random_access_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/**
			**	@brief	Decrement the pointer to the next value
			**
			**	@return A reference to the previous value
			*/
			random_access_iterator	&operator--( void )
			{
				this->_elem--;
				return (*this);
			}

			/**
			**	@brief Predecrement the pointer to the next value
			**
			**	@return A reference to the current element
			*/
			random_access_iterator	operator--( int )
			{
				random_access_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			/**
			**	@brief Access the element at this + n
			**
			**	@param	n	The number of element to "skip"
			**
			**	@return The random access iterator who point at this + n
			*/
			random_access_iterator	operator+( difference_type n ) const
			{
				return (this->_elem + n);
			}

			/**
			**	@brief Access the element at this - n
			**
			**	@param	n	The number of element to "skip"
			**
			**	@return The random access iterator who point at this + n
			*/
			random_access_iterator	operator-( difference_type n ) const
			{
				return (this->_elem - n);
			}

			/**
			**	@brief Give the reference to the random access iterator where
			**	the actuel element is this + n
			**
			**	@param n	Number of elements to "skip"
			**
			**	@return		Random access iterator to the new value
			*/
			random_access_iterator	&operator+=( difference_type n )
			{
				_elem += n;
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
			random_access_iterator	&operator-=( difference_type n )
			{
				_elem -= n;
				return (*this);
			}

			reference	operator[]( difference_type n ) const
			{
				return *(*this + n);
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
	// template <typename T>
	// inline bool operator==(	const ft::random_access_iterator<T> lhs,
	// 						const ft::random_access_iterator<T> rhs)
	// {
	// 	return ( lhs.base() == rhs.base() );
	// }

	/* Same but for `random_access_iterator == const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool operator==(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() == rhs.base() );
	}

	/**
	**	@brief	Check if lhs and rhs are different in memory
	**
	**	@param	lhs	The random access memory to compare
	**	@param	rhs	The random acces with who check
	**
	**	@return	True if different, false otherwise
	*/
	template <typename T>
	inline bool operator!=(	const ft::random_access_iterator<T> lhs,
							const ft::random_access_iterator<T> rhs)
	{
		return ( lhs.base() != rhs.base() );
	}

	/* Same but for `random_access_iterator != const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool operator!=(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
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
	template <typename T>
	inline bool operator>(	const ft::random_access_iterator<T> lhs,
							const ft::random_access_iterator<T> rhs)
	{
		return ( lhs.base() > rhs.base() );
	}

	/* Same but for `random_access_iterator > const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool	operator>(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() < rhs.base() );
	}

	/**
	 * @brief Check if lhs is inferior as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if inferior, false otherwise
	 */
	template <typename T>
	inline bool operator<(	const ft::random_access_iterator<T> lhs,
							const ft::random_access_iterator<T> rhs)
	{
		return ( lhs.base() < rhs.base() );
	}

	/* Same but for `random_access_iterator > const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool operator<(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() < rhs.base() );
	}

	/**
	 * @brief Check if lhs is superior or equal as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if superior or equal, false otherwise
	 */
	template <typename T>
	inline bool operator>=(	const ft::random_access_iterator<T> lhs,
							const ft::random_access_iterator<T> rhs)
	{
		return ( lhs.base() >= rhs.base() );
	}

	/* Same but for `random_access_iterator > const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool	operator>=(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() >= rhs.base() );
	}

	/**
	 * @brief Check if lhs is inferior or equal as rhs in memory
	 *
	 * @param lhs The random acces memmory to compare
	 * @param rhs The random access with who check
	 *
	 * @return True if inferior or equal, false otherwise
	 */
	template <typename T>
	inline bool operator<=(	const ft::random_access_iterator<T> lhs,
							const ft::random_access_iterator<T> rhs)
	{
		return ( lhs.base() <= rhs.base() );
	}

	/* Same but for `random_access_iterator > const random_access_iterator` */
	template <typename T_L, typename T_R>
	inline bool operator<=(	const ft::random_access_iterator<T_L> lhs,
							const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() <= rhs.base() );
	}

	template <typename T_L, typename T_R>
	inline typename ft::random_access_iterator<T_L>::difference_type
	operator-(	const ft::random_access_iterator<T_L> lhs,
				const ft::random_access_iterator<T_R> rhs)
	{
		return ( lhs.base() - rhs.base() );
	}


} // namespace ft


#endif
