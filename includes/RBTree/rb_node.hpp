/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:37:35 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/18 12:54:03 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include <memory>
# include "../utils/utils.hpp"
# define BLACK	0
# define RED	1

namespace ft
{
	template <typename T>
	struct RB_node
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef	T					value_type;
			typedef	T&					value_reference;
			typedef T*					value_pointer;

			typedef	RB_node<T>			node_type;
			typedef RB_node<T>&			node_reference;
			typedef RB_node<T>*			node_pointer;

			typedef const T&			const_value_reference;
			typedef const T*			const_value_pointer;

			typedef const RB_node<T>&	const_node_reference;
			typedef const RB_node<T>*	const_node_pointer;

			typedef	std::allocator<node_type>	allocator_type;

		private:
			allocator_type	_alloc;

		public:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			value_type		data;
			RB_node			*parent;
			RB_node			*left;
			RB_node			*right;
			int				color;

		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			 * @brief Default.
			 * Create an empty value initialized node
			 */
			RB_node ( void ) :
				data(T()),
				parent(0),
				left(0),
				right(0),
				color(BLACK)
			{}

			/**
			 * @brief Construct a new RB node object
			 * Create a RB_node with default initialized value
			 *
			 * @param left Left node
			 * @param right Right node
			 * @param parent Parent node
			 * @param color Node's color
			 */
			RB_node ( RB_node *parent, RB_node *left = 0, RB_node *right = 0, int color = BLACK ) :
				data(T()),
				parent(parent),
				left(left),
				right(right),
				color(color)
			{}

			/**
			 * @brief Construct a new RB node object
			 * Create a RB_node with default initialized value
			 *
			 * @param val Node value
			 * @param left Left node
			 * @param right Right node
			 * @param parent Parent node
			 * @param color Node's color
			 */
			RB_node ( const value_type &val, RB_node *parent = 0, RB_node *left = 0, RB_node *right = 0,
				int color = BLACK ) :
				data(val),
				parent(parent),
				left(left),
				right(right),
				color(color)
			{}

			/**
			 * @brief Copy a RB_node
			 *
			 * @param node RB_node to copy
			 */
			RB_node ( const RB_node &node ) :
				data(node.data),
				parent(node.parent),
				left(node.left),
				right(node.right),
				color(node.color)
			{}

			~RB_node( void )
			{}

		/** ************************************************************************** */
		/**                                 OPERATORS                                  */
		/** ************************************************************************** */
			/**
			 * @brief Assigns rhs as the new content for the RB_node object.
			 * Member value is assigned rhs.value, member left is assigned rhs.left,
			 * and member right is assigned right.value.
			 *
			 * @param rhs Another RB_node object.
			 */
			RB_node	&operator= ( const RB_node &rhs )
			{
				if (rhs != *this)
				{
					this->data = rhs.data;
					this->color = rhs.color;
					this->left = rhs.left;
					this->right = rhs.right;
					this->parent = rhs.parent;
				}
				return (*this);
			}

			bool		operator== ( const RB_node &rhs ) const
			{
				return (this->data == rhs.data && this->parent == rhs.parent);
			}

			bool		operator!= ( const RB_node &rhs ) const
			{
				return (!(*this == rhs));
			}

	};
}

#endif
