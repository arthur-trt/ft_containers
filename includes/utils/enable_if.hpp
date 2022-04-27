/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:24:51 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/04 15:28:40 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/**
 * @brief The type T is enabled as member type enable_if::type if Cond is true.
 * Otherwise, enable_if::type is not defined.
 * This is useful to hide signatures on compile time when a particular
 * condition is not met, since in this case, the member enable_if::type will
 * not be defined and attempting to compile using it should fail.
 *
 * @param b A compile-time constant of type bool.
 * @param T A type.
 */

namespace ft {
	template <bool b, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if <true, T> { typedef T type; };
}

#endif
