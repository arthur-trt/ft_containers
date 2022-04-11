/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/08 12:43:14 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include "rb_node.hpp"
#include <memory>
#include <functional>
#include <cstddef>

namespace ft
{
	template <class T, class Compare = std::less<T>, class Node = ft::RB_node<T>, class T_Alloc = std::allocator<T>, class N_Alloc = std::allocator<Node> >
	class RedBlackTree
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef	T					value_type;
			typedef	Node*				node_pointer;
			typedef	Node&				node_reference;
			typedef N_Alloc				node_allocator;

		private:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			node_pointer	_root;
			node_allocator	_node_alloc;

			void		handleRightSituations ( node_pointer node, node_pointer parent, node_pointer grandParent )
			{
				if (node->isLeftChild())
				{
					rotateRight(parent);
				}
				parent->swapColor();
				grandParent->swapColor();
				rotateLeft(grandParent);
				recolorAndRotate(node->isLeftChild() ? grandParent : parent);
			}
			
			void		handleLeftSituations ( node_pointer node, node_pointer parent, node_pointer grandParent )
			{
				if (!node->isLeftChild())
				{
					rotateLeft(parent);
				}
				parent->swapColor();
				grandParent->swapColor();
				rotateRight(grandParent);
				recolorAndRotate(node->isLeftChild() ? parent : grandParent);
			}

			void		handleRecoloring ( node_pointer parent, node_pointer uncle, node_pointer grandParent )
			{
				uncle->swapColor();
				parent->swapColor();
				grandParent->swapColor();
				recolorAndRotate(grandParent);
			}

			void		rotateRight( node_pointer node )
			{
				node_pointer leftNode = node->getLeft();
				node->setLeft(leftNode->getRight());
				if (node->getLeft() != NULL)
				{
					node->getLeft()->setParent(node);
				}
				leftNode->setRight(node);
				leftNode->setParent(node->getParent());
				updateChildOfParentNode(node, leftNode);
				node->setParent(leftNode);
			}

			void		rotateLeft( node_pointer node )
			{
				node_pointer rightNode = node->getRight();
				node->setRight(rightNode->getRight());
				if (node->getRight() != NULL)
				{
					node->getRight()->setParent(node);
				}
				rightNode->setLeft(node);
				rightNode->setParent(node->getParent());
				updateChildOfParentNode(node, rightNode);
				node->setParent(rightNode);
			}

			void		updateChildOfParentNode( node_pointer node, node_pointer tmpNode )
			{
				if (node->getParent() == NULL)
				{
					this->_root = tmpNode;
				}
				else if (node->isLeftChild())
				{
					node->getParent()->setLeft(tmpNode);
				}
				else
				{
					node->getParent()->setRight(tmpNode);
				}
			}

			void		recolorAndRotate ( node_pointer node )
			{
				node_pointer parent = node->getParent();
				if (node != this->_root && parent->getColor() == RED)
				{
					node_pointer	grandParent = parent->getParent();
					node_pointer	uncle = parent->isLeftChild() ? grandParent->getRight() : grandParent->getLeft();
					if (uncle != NULL && uncle->getColor() == RED)
					{
						handleRecoloring(parent, uncle, grandParent);
					}
					else if (parent->isLeftChild())
					{
						handleLeftSituations(node, parent, grandParent);
					}
					else if (!parent->isLeftChild())
					{
						handleRightSituations(node, parent, grandParent);
					}
				}
			}

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			RedBlackTree ( const node_allocator& node_alloc = node_allocator() ) :
				_node_alloc(node_alloc)
			{}

			~RedBlackTree ( void )
			{}

			RedBlackTree	insert(value_type val)
			{
				node_pointer new_node = _node_alloc.allocate(1);
				new_node->setData(val);
				this->_root = insert(this->_root, new_node);
				recolorAndRotate(new_node);
				return (*this);	
			}

			node_pointer	insert (node_pointer pos, const node_pointer to_insert )
			{
				if (to_insert == NULL)
				{
					return (to_insert);
				}
				if (to_insert->getData() < pos->getData())
				{
					pos->setLeft(insert(pos->getLeft(), to_insert));
					pos->getLeft()->setParent(pos);
				}
				else if (pos->getData() > to_insert->getData())
				{
					pos->setRight(insert(pos->getRight(), to_insert));
					pos->getRight()->setParent(pos);
				}
				return (pos);				
			}

	};
}


#endif
