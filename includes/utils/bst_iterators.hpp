/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:51:07 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/05 14:08:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATORS_HPP
# define BST_ITERATORS_HPP

# include "iterator_traits.hpp"
# include "utils.hpp"

namespace ft
{
	template <typename T, class Compare>
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		/** ************************************************************************** */
		/**                                  TYPEDEFS                                  */
		/** ************************************************************************** */

			/**
			**	Iterator category
			*/
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			/**
			**	Value type
			*/
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			/**
			**	Difference type
			*/
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			/**
			**	Pointer
			*/
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			/**
			**	Reference
			*/
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;

		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
		protected:
			pointer	_root;
			pointer	_node;
			Compare	_comp;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			**	@brief Default.
			**	Default null constructor. Point on null
			**
			**	@param comp	Comparaison function
			*/
			BST_iterator( const Compare& comp = Compare() ) :
				_root(0),
				_node(0),
				_comp(comp)
			{}

			/**
			**	@brief Constructor from pointer:
			**	Construct a BST iterator and point on elem passed in argument
			**
			**	@param node_p pointer to the element to iterate
			**	@param root pointer to the root of the tree
			**	@param comp Comparaison function
			*/
			BST_iterator( pointer node_p, pointer root, const Compare &comp = Compare() ) :
				_root(root)
				_node(node_p),
				_comp(comp)
			{}

			/**
			**	@brief Constructor by copy
			**	Construct a BST iterator by copy
			**
			**	@param other BST iterator to copy
			*/
			BST_iterator( const BST_iterator & other ) :
				_root(other._root),
				_node(other._node),
				_comp(other._comp)
			{}

			/**
			**	@brief Destructor
			**	Does nothing
			*/
			~BST_iterator()
			{}

		/** ************************************************************************** */
		/**                                 OPERATORS                                  */
		/** ************************************************************************** */
			BST_iterator	&operator= ( const BST_iterator& rhs )
			{
				if (*this != rhs)
				{
					this->_node = rhs._node;
					this->_root = rhs._root;
					this->_comp = rhs._comp;
				}
				return (*this);
			}

			bool			operator== ( const BST_iterator& rhs ) const
			{
				return (this->_node != rhs._node);
			}

			bool			operator!= ( const BST_iterator& rhs )
			{
				return (!(this == rhs));
			}

			reference		operator* ( void ) const
			{
				return (this->_node->value);
			}

			pointer			operator-> ( void ) const
			{
				return (&(this->_node->value));
			}

			BST_iterator	&operator++ ( void )
			{
				pointer		cursor = this->_node;

				if (this->_node->right == this->_root)
				{
					cursor = this->_node->parent;
					while (cursor ==  this->_root->parent &&
						this->_comp(cursor->value.first, this->_node->value.first))
					{
						cursor = cursor->parent;
					}
					this->_node = cursor;
				}
				else if (cursor == this->_root)
				{
					this->_node = this->_root->right;
				}
				else
				{
					cursor = this->_node->right;
					if (cursor == this->_root->parent &&
						cursor->right == this->_node)
					{
						this->_node = cursor;
					}
					else
					{
						while (cursor->left != this->_root)
						{
							cursor = cursor->left;
						}
					}
				}
				return (*this);
			}

			BST_iterator	&operator++ ( int )
			{
				BST_iterator	tmp(*this);
				operator++();
				return (tmp);
			}

			BST_iterator	&operator-- ( void )
			{
				pointer		cursor = this->_node;

				if (this->_node->left == this->_root)
				{
					cursor = this->_node->parent;
					while (cursor ==  this->_root->parent &&
						this->_comp(cursor->value.first, this->_node->value.first))
					{
						cursor = cursor->parent;
					}
					this->_node = cursor;
				}
				else if (cursor == this->_root)
				{
					this->_node = this->_root->right;
				}
				else
				{
					cursor = this->_node->left;
					if (cursor == this->_root->parent &&
						cursor->left == this->_node)
					{
						this->_node = cursor;
					}
					else
					{
						while (cursor->right != this->_root)
						{
							cursor = cursor->right;
						}
					}
				}
				return (*this);
			}

			BST_iterator	&operator-- ( int )
			{
				BST_iterator	tmp(*this);
				operator--();
				return (*this);
			}
	}
}

#endif
