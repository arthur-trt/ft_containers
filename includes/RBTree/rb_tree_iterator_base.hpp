/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iterator_base.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:54:57 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 10:35:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_ITERATOR_BASE_HPP
# define RB_TREE_ITERATOR_BASE_HPP

# include "rb_node.hpp"

namespace ft
{
	template <typename T>
	bool						__is_leaf ( ft::RB_node<T>* __x )
	{
		if (__x->parent == NULL && __x->left == NULL && __x->right == NULL)
			return (true);
		return (false);
	}

	template <typename T>
	static	ft::RB_node<T>*		_local_rb_tree_increment ( ft::RB_node<T>* __x ) throw()
	{
		if (__x->right && __x->right->parent != 0)
		{
			__x = __x->right;
			while (__x->left != 0 && __x->left->parent != 0)
				__x = __x->left;
		}
		else
		{
			ft::RB_node<T>*	__y = __x->parent;
			while (__x == __y->right)
			{
				__x = __y;
				__y = __y->parent;
			}
			if (__x->right != __y)
				__x = __y;
		}
		return (__x);
	}

	template <typename T>
	ft::RB_node<T>*			_rb_tree_increment ( ft::RB_node<T>* __x ) throw()
	{
		return (_local_rb_tree_increment(__x));
	}

	template <typename T>
	const ft::RB_node<T>*	_rb_tree_increment ( const ft::RB_node<T>* __x ) throw()
	{
		return (_local_rb_tree_increment(const_cast<ft::RB_node<T>*>(__x)));
	}

	template <typename T>
	static ft::RB_node<T>*	_local_rb_tree_decrement ( ft::RB_node<T>* __x ) throw()
	{
		if (__x->color == RED && __x->parent->parent == __x)
		{
			__x = __x->right;
		}
		else if (__x->left != 0 && !__is_leaf(__x->left))
		{
			ft::RB_node<T>* __y = __x->left;
			while (__y->right != 0 && !__is_leaf(__y->right))
			{
				__y = __y->right;

			}
			__x = __y;
		}
		else
		{
			ft::RB_node<T>*	__y = __x->parent;
			while (__x == __y->left)
			{
				__x = __y;
				__y = __y->parent;
			}
			__x = __y;
		}
		return (__x);
	}

	template <typename T>
	ft::RB_node<T>*			_rb_tree_decrement ( ft::RB_node<T>* __x ) throw()
	{
		return (_local_rb_tree_decrement(__x));
	}

	template <typename T>
	const ft::RB_node<T>*	_rb_tree_decrement ( const ft::RB_node<T>* __x) throw()
	{
		return (_local_rb_tree_decrement(const_cast<ft::RB_node<T>*>(__x)));
	}
}

#endif
