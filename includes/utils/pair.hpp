/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:41:51 by arthur            #+#    #+#             */
/*   Updated: 2022/04/27 16:20:48 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
	/** ************************************************************************** */
	/**                                MEMBER TYPE                                 */
	/** ************************************************************************** */
		typedef T1		first_type;
		typedef	T2		second_type;

	/** ************************************************************************** */
	/**                             MEMBER VARIABLES                               */
	/** ************************************************************************** */
		first_type		first;
		second_type		second;

	/** ************************************************************************** */
	/**                                CONSTRUCTORS                                */
	/** ************************************************************************** */
		/**
		 * @brief Default.
		 * Constructs a pair object with its elements value-initialized.
		 */
		pair () :
			first(T1()),
			second(T2())
		{}

		/**
		 * @brief Copy
		 * The object is initialized with the contents of the pr pair object.
		 * The corresponding member of pr is passed to the constructor of each of its members.
		 *
		 * @param pr Another pair object.
		 */
		template <class U, class V>
		pair ( const pair<U,V> &pr ) :
			first(pr.first),
			second(pr.second)
		{}

		/**
		 * @brief Initialization
		 * Constructs members first and second in place,
		 * passing the elements of first_args as arguments to the constructor of first,
		 * and the elements of second_args to the constructor of second.
		 *
		 * @param a An object of the type of first, or some other type implicitly convertible to it.
		 * @param b An object of the type of second, or some other type implicitly convertible to it.
		 */
		pair (const first_type& a, const second_type& b) :
			first(a),
			second(b)
		{}

		~pair()
		{}

	/** ************************************************************************** */
	/**                                 OPERATORS                                  */
	/** ************************************************************************** */
		/**
		 * @brief Assigns pr as the new content for the pair object.
		 * Member first is assigned pr.first, and member second is assigned pr.second.
		 *
		 * @param pr Another pair object.
		 */
		pair	&operator= ( const pair& pr )
		{
			if (*this != pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
	};

	/** ************************************************************************** */
	/**                           COMPARAISON OPERATORS                            */
	/** ************************************************************************** */

	template <class T1, class T2>
	bool operator== ( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second ));
	}

	template <class T1, class T2>
	bool operator<= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

	/**
	 * @brief Constructs a pair object with its first element set to x and its second element set to y.
	 * The template types can be implicitly deduced from the arguments passed to make_pair.
	 * pair objects can be constructed from other pair objects containing different types, if the respective types are implicitly convertible.
	 *
	 * @param x Values for the members first of the pair object being constructed.
	 * @param y Values for the members second of the pair object being constructed.
	 * @return pair<T1, T2> A pair object whose elements first and second are set to x and y respectivelly.
	 */
	template <class T1, class T2>
	pair<T1, T2> make_pair ( T1 x, T2 y )
	{
		return (pair<T1, T2>(x, y));
	}
} // namespace ft


#endif
