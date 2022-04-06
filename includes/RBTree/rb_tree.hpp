/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/06 17:58:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "rb_node.hpp"
# include <memory>

namespace ft
{
	template <class T, class Compare = std::less<T>, class Node = ft::RB_node<T>,
		class T_Alloc = std::allocator<T>, class N_Alloc = std::allocator<Node> >
	class RedBlackTree
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef typename	T			value_type;
			typedef typename	Node*		node_pointer;
			typedef typename	Node&		node_reference;
			typedef typename	N_Alloc		node_allocator;

		private:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			node_pointer	_root;
			node_allocator	_node_alloc;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			RedBlackTree ( const node_allocator& node_alloc = node_alloc() ) :
				_node_alloc(node_alloc)
			{}

			~RedBlackTree ( void )
			{}

			void	insert ( const node_pointer to_insert )
			{
				if (to_insert == NULL)
				{
					return (to_insert);
				}
				
			}

	};
}


#endif
