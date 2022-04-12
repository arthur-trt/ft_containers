/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/12 18:50:16 by arthur           ###   ########.fr       */
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
	template <class T, class Compare = std::less<T>, class Node = ft::RB_node<T>, class Alloc = std::allocator<T> >
	class RedBlackTree
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef				T									value_type;
			typedef 			Alloc								allocator_type;

			typedef typename	allocator_type::template
								rebind<Node>::other	node_allocator;

			typedef typename	node_allocator::pointer				node_pointer;
			typedef typename	node_allocator::reference			node_reference;

		private:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			node_pointer	_root;
			node_pointer	_empty;
			node_allocator	_node_alloc;

			void	leftRotate ( node_pointer node )
			{
				node_pointer	tmp = node->right;

				node->right = tmp->left;
				if (tmp->left != NULL && tmp->left != this->_empty)
				{
					tmp->left->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || node->parent == this->_empty)
				{
					this->_root = tmp;
				}
				else if (node == node->parent->left)
				{
					node->parent->left = tmp;
				}
				else
				{
					node->parent->right = tmp;
				}
				tmp->left = node;
				node->parent = tmp;
			}

			void	rightRotate ( node_pointer node )
			{
				node_pointer tmp = node->left;

				node->left = tmp->right;
				if (tmp->right != NULL && tmp->right != this->_empty)
				{
					tmp->right->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || node->parent == this->_empty)
				{
					this->_root = tmp;
				}
				else if (node == node->parent->right)
				{
					node->parent->right = tmp;
				}
				else
				{
					node->parent->left = tmp;
				}
				tmp->right = node;
				node->parent = tmp;
			}

			void	insert_fix ( node_pointer node )
			{
				node_pointer	tmp;

				while (node->parent->color == 1)
				{
					if (node->parent == node->parent->parent->right)
					{
						tmp = node->parent->parent->left;
						if (tmp && tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								rightRotate(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							leftRotate(node->parent->parent);
						}
					}
					else
					{
						tmp = node->parent->parent->right;

						if (tmp && tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								leftRotate(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							rightRotate(node->parent->parent);
						}
					}
					if (node == this->_root) {
						break;
					}
				}
				this->_root->color = 0;
			}

			void	delete_fix ( node_pointer node )
			{
				node_pointer	tmp;
				
				while (node != this->_root && node->color == BLACK)
				{
					if (node == node->parent->left)
					{
						tmp = node->parent->right;
						if (tmp->color == RED)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							leftRotate(node->parent);
							tmp = node->parent->right;
						}
						if (tmp->left->color == BLACK && tmp->right->color == BLACK)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->right->color == BLACK)
							{
								tmp->left->color = BLACK;
								tmp->color = RED;
								rightRotate(tmp);
								tmp = node->parent->right;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							leftRotate(node->parent);
							node = this->_root;
						}
					}
					else
					{
						tmp = node->parent->left;
						if (tmp->color == RED)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							rightRotate(node->parent);
							tmp = node->parent->left;
						}
						if (tmp->right->color == BLACK)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->left->color == BLACK)
							{
								tmp->right->color = BLACK;
								tmp->color = RED;
								leftRotate(tmp);
								tmp = node->parent->left;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;
							rightRotate(node->parent);
							node = this->_root;
						}
					}
				}
				node->color = BLACK;
			}

			void	delete_tree ( node_pointer root )
			{
				if (root != NULL)
				{
					delete_tree(root->left);
					delete_tree(root->right);
				}
				this->_node_alloc.destroy(root);
				this->_node_alloc.deallocate(root, 1);
			}

			void	rbTransplant ( node_pointer x, node_pointer y )
			{
				if (x->parent == NULL)
				{
					this->_root = y;
				}
				else if (x == x->parent->left)
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->parent = x->parent;
			}

			node_pointer	maximum ( node_pointer node )
			{
				while (node->right != NULL)
				{
					node = node->right;
				}
				return (node);
			}

			node_pointer	minimum ( node_pointer node )
			{
				while (node->left != NULL)
				{
					node = node->left;
				}
				return (node);
			}

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			RedBlackTree ( const node_allocator& node_alloc = node_allocator() ) :
				_node_alloc(node_alloc)
			{
				Node	tmp;

				this->_empty = _node_alloc.allocate(1);
				_node_alloc.construct(this->_empty, tmp);
				this->_root = NULL;
			}

			~RedBlackTree ( void )
			{
				_node_alloc.destroy(this->_empty);
				_node_alloc.deallocate(this->_empty, 1);
				delete_tree(this->_root);
			}

		/** ************************************************************************** */
		/**                             MEMBER FUNCTIONS                               */
		/** ************************************************************************** */
			void	insert ( value_type	to_insert )
			{
				Node			new_one(to_insert);
				node_pointer	y = NULL;
				node_pointer	x = this->_root;
				node_pointer	insert_pos = NULL;

				while (x != NULL && x != this->_empty)
				{
					y = x;
					if (new_one.data < x->data)
					{
						x = x->left;
					}
					else
					{
						x = x->right;
					}
				}

				new_one.parent = y;
				new_one.color = (new_one.parent == NULL) ? BLACK : RED;
				if (y == NULL)
				{
					this->_root = _node_alloc.allocate(1);
					insert_pos = this->_root;
				}
				else if (new_one.data < y->data)
				{
					y->left = _node_alloc.allocate(1);
					insert_pos = y->left;
				}
				else
				{
					y->right = _node_alloc.allocate(1);
					insert_pos = y->right;
				}
				this->_node_alloc.construct(insert_pos, new_one);

				if (new_one.parent == NULL || new_one.parent->parent == NULL)
					return ;
				insert_fix(insert_pos);
			}

			void	deleteNode ( value_type data )
			{
				node_pointer	tmp(this->_root);
				node_pointer	to_delete = NULL;
				node_pointer	new_root = NULL;
				int				original_color;
				
				while (this->_root != NULL /* && to_delete == NULL */)
				{
					if (this->_root->data == data)
					{
						to_delete = this->_root;
					}
					if (this->_root->data <= data)
					{
						this->_root = this->_root->right;
					}
					else
					{
						this->_root = this->_root->left;
					}
				}

				if (to_delete == NULL)
					return;
				
				tmp = to_delete;
				original_color = tmp->color;
				if (to_delete->left == NULL)
				{
					new_root = to_delete->right;
					rbTransplant(to_delete, to_delete->right);
				}
				else if (to_delete->right == NULL)
				{
					new_root = to_delete->left;
					rbTransplant(to_delete, to_delete->left);
				}
				else
				{
					tmp = minimum(to_delete->right);
					original_color = tmp->color;
					new_root = tmp->right;
					if (new_root && tmp->parent == to_delete)
					{
						new_root->parent = tmp;
					}
					else
					{
						rbTransplant(tmp, tmp->right);
						tmp->right = to_delete->right;
						tmp->right->parent = tmp;
					}
					rbTransplant(to_delete, tmp);
					tmp->left = to_delete->left;
					tmp->left->parent = tmp;
					tmp->color = to_delete->color;
				}
				this->_node_alloc.destroy(to_delete);
				this->_node_alloc.deallocate(to_delete, 1);
				if (original_color == BLACK)
				{
					delete_fix(new_root);
				}
			}
	};
}


#endif
