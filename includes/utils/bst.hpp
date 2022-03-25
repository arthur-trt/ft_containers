/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:38:55 by arthur            #+#    #+#             */
/*   Updated: 2022/03/24 22:29:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

namespace ft
{
	template <typename T>
	struct BST_node
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef	T	value_type;

		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			value_type	value;
			BST_node	*left;
			BST_node	*right;

		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			 * @brief Default.
			 * Create an empty value initialized node
			 */
			BST_node () :
				value(T()),
				left(0),
				right(0)
			{}

			/**
			 * @brief Construct a new bst node object
			 * Create a BST_node with default initialized value
			 * 
			 * @param left Left node
			 * @param right Right node
			 */
			BST_node ( BST_node *left = 0, BST_node *right = 0 ) :
				value(T()),
				left(left),
				right(right)
			{}

			/**
			 * @brief Construct a new bst node object with value set
			 * Create a BST_node with a value assigned
			 * 
			 * @param val The value to copy
			 * @param left Left node
			 * @param right Right node
			 */
			BST_node ( const value_type &val, BST_node *left = 0, BST_node *right = 0) :
				value(val),
				left(left),
				right(right),
			{}

			/**
			 * @brief Copy a BST_node
			 * 
			 * @param node BST_node to copy
			 */
			BST_node ( const BST_node &node ) :
				value(node.value),
				left(node.left),
				right(node.right)
			{}

		/** ************************************************************************** */
		/**                                 OPERATORS                                  */
		/** ************************************************************************** */
			/**
			 * @brief Assigns rhs as the new content for the BST_node object.
			 * Member value is assigned rhs.value, member left is assigned rhs.left,
			 * and member right is assigned right.value.
			 * 
			 * @param rhs Another BST_node object.
			 */
			BST_node	&operator= ( const BST_node &rhs )
			{
				if (rhs != *this)
				{
					this->value = rhs.value;
					this->left = left;
					this->right = right;
				}
				return (*this);
			}

			bool		operator== ( const BST_node &rhs )
			{
				return (this->value == rhs.value);
			}
	};

	class BST
	{
		
	};
	
} // namespace ft

#endif