/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:37:35 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/06 18:01:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include <memory>
# define BLACK	0
# define RED	1

namespace ft
{
	template <typename T>
	struct RB_node
	{
		private:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef	T	value_type;

		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			value_type		data;
			RB_node			*parent;
			RB_node			*left;
			RB_node			*right;
			int				color;

		public:
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
			RB_node ( RB_node *left = 0, RB_node *right = 0, RB_node *parent = 0, int color = BLACK ),
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
			RB_node ( const valut_type &val = T(), RB_node *left = 0, RB_node *right = 0,
				RB_node *parent = 0, int color = BLACK ),
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
					this->left = left;
					this->right = right;
					this->parent = parent;
				}
				return (*this);
			}

			bool		operator== ( const RB_node &rhs )
			{
				return (this->data == rhs.data);
			}
	}
}

#endif
