/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:38:55 by arthur            #+#    #+#             */
/*   Updated: 2022/04/04 16:29:51 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include <functional>
# include <memory>

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
			int			bf;		// Balance factor. Have to be between -1 and 1
			BST_node	*left;
			BST_node	*right;
			BST_node	*parent;

		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			 * @brief Default.
			 * Create an empty value initialized node
			 */
			BST_node () :
				value(T()),
				bf(0),
				left(0),
				right(0),
				parent(0)
			{}

			/**
			 * @brief Construct a new bst node object
			 * Create a BST_node with default initialized value
			 *
			 * @param left Left node
			 * @param right Right node
			 */
			BST_node ( BST_node *parent = 0, BST_node *left = 0, BST_node *right = 0 ) :
				value(T()),
				bf(0),
				left(left),
				right(right),
				parent(parent)
			{}

			/**
			 * @brief Construct a new bst node object with value set
			 * Create a BST_node with a value assigned
			 *
			 * @param val The value to copy
			 * @param left Left node
			 * @param right Right node
			 */
			BST_node ( const value_type &val, BST_node *parent = 0, BST_node *left = 0, BST_node *right = 0) :
				value(val),
				bf(0),
				parent(parent),
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
				bf(node.bf),
				left(node.left),
				right(node.right),
				parent(node.parent)
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
					this->bf = rhs.bf;
					this->left = left;
					this->right = right;
					this->parent = parent;
				}
				return (*this);
			}

			bool		operator== ( const BST_node &rhs )
			{
				return (this->value == rhs.value);
			}
	};


//##https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/avl-trees/AVLTree.cpp
	template <class T, class Compare = std::less<T>, class Node = ft::BST_node<T>, class T_Alloc = std::allocator<T>, class N_Alloc = std::allocator<Node> >
	class BST
	{
		public:
			typedef	BST			self;
			typedef	BST&		self_reference;
			typedef	T			value_type;
			typedef	Node*		node_pointer;
			typedef	N_Alloc		node_allocator;
			typedef	size_t		size_type;

		private:
			node_pointer		root;

		public:

					
	};

} // namespace ft

#endif
