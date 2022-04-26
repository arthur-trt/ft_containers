/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:42:42 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/25 16:22:10 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

# include "rb_node.hpp"
# include "rb_tree_iterator_base.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	struct rb_tree_iterator
	{
		typedef				T									value_type;
		typedef				T*									pointer;
		typedef				T&									reference;

		typedef 			ft::bidirectional_iterator_tag		iterator_category;
    	typedef 			ptrdiff_t 							difference_type;

		typedef				rb_tree_iterator<T>					_Self;
		typedef	typename	RB_node<T>::node_pointer			_node_pointer;

		// _node_pointer	_header;
		_node_pointer	_node_;

		rb_tree_iterator (/* _node_pointer header = 0*/ ) :
			/*_header(header),*/
			_node_(0)
		{}

		explicit rb_tree_iterator ( _node_pointer __x/*, _node_pointer header*/ ) :
			/*_header(header),*/
			_node_(__x)
		{}

		reference	operator* ( void ) const
		{
			return (_node_->data);
		}

		pointer		operator-> ( void ) const
		{
			return (&(_node_->data));
		}

		_Self&		operator++ ( void )
		{
			// std::cout << "\t(it++) : Header->right: " << this->_header->right << std::endl;
			_node_ = ft::_rb_tree_increment(_node_/*, _header*/);
			return (*this);
		}

		_Self		operator++ ( int )
		{
			_Self	__tmp = *this;
			_node_ = ft::_rb_tree_increment(_node_/*, _header*/);
			return (__tmp);
		}

		_Self&		operator-- ( void )
		{
			_node_ = ft::_rb_tree_decrement(_node_/*, _header*/);
			return (*this);
		}

		_Self		operator-- ( int )
		{
			_Self	__tmp = *this;
			_node_ = ft::_rb_tree_decrement(_node_/*, _header*/);
			return (__tmp);
		}

		bool		operator== ( const _Self & rhs ) const
		{
			return (_node_ == rhs._node_);
		}

		bool		operator!= ( const _Self & rhs ) const
		{
			return (_node_ != rhs._node_);
		}
	};

	template <typename T>
	struct rb_tree_const_iterator
	{
		typedef				T									value_type;
		typedef				const T*							pointer;
		typedef				const T&							reference;

		typedef				rb_tree_iterator<T>					iterator;

		typedef 			ft::bidirectional_iterator_tag		iterator_category;
    	typedef 			ptrdiff_t          		       		difference_type;

		typedef				rb_tree_const_iterator<T>			_Self;
		typedef	typename	RB_node<T>::const_node_pointer		_node_pointer;

		// _node_pointer	_header;
		_node_pointer	_node_;

		rb_tree_const_iterator ( /*_node_pointer header = 0*/ ) :
			// _header(header),
			_node_(0)
		{}

		explicit rb_tree_const_iterator ( _node_pointer __x/*, _node_pointer header*/ ) :
			// _header(header),
			_node_(__x)
		{}

		rb_tree_const_iterator ( const iterator & it ) :
			// _header(it._header),
			_node_(it._node_)
		{}

		iterator	_const_cast( void ) const
		{
			return (iterator(const_cast<typename iterator::_node_pointer>(_node_/*, _header*/)));
		}

		reference	operator* ( void ) const
		{
			return (_node_->data);
		}

		pointer		operator-> ( void ) const
		{
			return (&(_node_->data));
		}

		_Self&		operator++ ( void )
		{
			_node_ = ft::_rb_tree_increment(_node_/*, _header*/);
			return (*this);
		}

		_Self		operator++ ( int )
		{
			_Self	__tmp = *this;
			_node_ = ft::_rb_tree_increment(_node_/*, _header*/);
			return (__tmp);
		}

		_Self&		operator-- ( void )
		{
			_node_ = ft::_rb_tree_decrement(_node_/*, _header*/);
			return (*this);
		}

		_Self		operator-- ( int )
		{
			_Self	__tmp = *this;
			_node_ = ft::_rb_tree_decrement(_node_/*, _header*/);
			return (__tmp);
		}

		bool		operator== ( const _Self & rhs ) const
		{
			return (_node_ == rhs._node_);
		}

		bool		operator!= ( const _Self & rhs ) const
		{
			return (_node_ != rhs._node_);
		}
	};

	template <typename T>
	inline bool	operator== ( const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs )
	{
		return (lhs._node_ == rhs._node_);
	}

	template <typename T>
	inline bool	operator!= ( const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs )
	{
		return (lhs._node_ != rhs._node_);
	}
}

#endif
