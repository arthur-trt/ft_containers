/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/21 15:58:06 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include "rb_node.hpp"
#include <memory>
#include <functional>
#include <cstddef>
#include <iostream>
#include <string>
# include "../utils/pair.hpp"
# include "rb_tree_iterator.hpp"
# include "../reverse_iterator.hpp"

namespace ft
{
	template <class _Key, class T, class Compare = std::less<_Key>, class Alloc = std::allocator<T> >
	class RedBlackTree
	{
		public:
		/** ************************************************************************** */
		/**                                MEMBER TYPE                                 */
		/** ************************************************************************** */
			typedef				_Key								key_type;
			typedef				T									value_type;
			typedef 			Alloc								allocator_type;
			typedef				ft::RB_node<T>						Node;
			typedef				Compare								key_compare;

			typedef typename	allocator_type::template
								rebind<Node>::other					node_allocator;

			typedef typename	node_allocator::pointer				node_pointer;
			typedef typename	node_allocator::reference			node_reference;

			typedef				ft::rb_tree_iterator<T>				iterator;

		private:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			node_pointer	_root;
			node_pointer	_empty;
			node_allocator	_node_alloc;
			size_t			_node_count;

			void	leftRotate ( node_pointer node )
			{
				node_pointer	tmp = node->right;

				node->right = tmp->left;
				if (tmp->left != NULL && !isLeaf(node->left))
				{
					tmp->left->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || isLeaf(node->parent))
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
				if (tmp->right != NULL && !isLeaf(node->right))
				{
					tmp->right->parent = node;
				}
				tmp->parent = node->parent;
				if (node->parent == NULL || isLeaf(node->parent))
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
						else
						{
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
				if (root != NULL)
				{
					// std::cout << "Deallocate node (" << root << ") for data : " << root->data.first << "/" << root->data.second << std::endl;
					this->_node_alloc.destroy(root);
					this->_node_alloc.deallocate(root, 1);
				}
			}

			void	rbTransplant ( node_pointer x, node_pointer y )
			{
				if (x->parent == NULL)
				{
					this->_root = y;
				}
				else if (x == x->parent->left)
				{
					if (isLeaf(x->parent->left))
					{
						// std::cout << "Deallocate node (" << x->parent->left << ") for data : " << x->parent->left->data.first << "/" << x->parent->left->data.second << std::endl;
						this->_node_alloc.destroy(x->parent->left);
						this->_node_alloc.deallocate(x->parent->left, 1);
					}
					x->parent->left = y;
				}
				else
				{
					if (isLeaf(x->parent->right))
					{
						// std::cout << "Deallocate node (" << x->parent->right << ") for data : " << x->parent->right->data.first << "/" << x->parent->right->data.second << std::endl;
						this->_node_alloc.destroy(x->parent->right);
						this->_node_alloc.deallocate(x->parent->right, 1);
					}
					x->parent->right = y;
				}
				y->parent = x->parent;
			}

			node_pointer	maximum ( node_pointer node ) const
			{
				while (!isLeaf(node->right) && node->right != NULL)
				{
					node = node->right;
				}
				return (node);
			}

			node_pointer	minimum ( node_pointer node ) const
			{
				while (!isLeaf(node->left) && node->left != NULL)
				{
					node = node->left;
				}
				return (node);
			}

			void	printTreeHelper ( node_pointer node, std::string indent, bool side ) const
			{
				if (!isLeaf(node))
				{
					std::cout << indent;
					if (side)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "   ";
					}

					std::string sColor = node->color ? "🔴" : "⚫";
					std::cout << "(" << node->data << ") (" << sColor << ")" << std::endl;
					printTreeHelper(node->left, indent, false);
					printTreeHelper(node->right, indent, true);
				}
			}

			node_pointer	searchTreeHelper ( node_pointer node, value_type data) const
			{
				if (isLeaf(node) || node == NULL)
				{
					return (NULL);
				}
				if (!key_compare()(node->data.first, data.first) && !key_compare()(data.first, node->data.first))
				{
					return (node);
				}
				if (key_compare()(data.first, node->data.first))
				{
					return (searchTreeHelper(node->left, data));
				}
				return (searchTreeHelper(node->right, data));
			}

			node_pointer	searchKeyHelper ( node_pointer node, key_type key) const
			{
				if (isLeaf(node) || node == NULL)
				{
					return (NULL);
				}
				if (!key_compare()(node->data.first, key) && !key_compare()(key, node->data.first))
				{
					return (node);
				}
				if (key_compare()(key, node->data.first))
				{
					return (searchKeyHelper(node->left, key));
				}
				return (searchKeyHelper(node->right, key));
			}

			bool			isLeaf( node_pointer node ) const
			{
				if (node->data == T() && node->left == NULL && node->right == NULL)
					return (true);
				return (false);
			}

			void		construct_node ( node_pointer pos, Node node )
			{
				node_pointer	leaf_r_addr;
				Node			leaf_r(pos);
				node_pointer	leaf_l_addr;
				Node			leaf_l(pos);
				
				
				// Right leaf node
				leaf_r_addr = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(leaf_r_addr, leaf_r);
				node.right = leaf_r_addr;
				// node.right = NULL;
				// Left leaf node
				leaf_l_addr = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(leaf_l_addr, leaf_l);
				node.left = leaf_l_addr;
				// node.left = NULL;
				// leaf_r.parent = pos;
				this->_node_alloc.construct(pos, node);
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
				this->_node_count = 0;
			}

			~RedBlackTree ( void )
			{
				delete_tree(this->_root);
				_node_alloc.destroy(this->_empty);
				_node_alloc.deallocate(this->_empty, 1);
			}

		/** ************************************************************************** */
		/**                             MEMBER FUNCTIONS                               */
		/** ************************************************************************** */
			node_pointer	insert ( node_pointer position, value_type to_insert )
			{
				Node			new_one(to_insert, NULL, NULL, NULL, RED);
				node_pointer	x = this->_root;
				node_pointer	insert_pos = NULL;

				new_one.parent = position;
				new_one.color = (new_one.parent == NULL) ? BLACK : RED;
				if (position == NULL)
				{
					this->_root = _node_alloc.allocate(1);
					insert_pos = this->_root;
				}
				else if (key_compare()(new_one.data.first, position->data.first))
				{
					// std::cout << "Deallocate node (" << y->left << ") for data : " << y->left->data.first << "/" << y->left->data.second << std::endl;
					this->_node_alloc.destroy(position->left);
					this->_node_alloc.deallocate(position->left, 1);
					position->left = _node_alloc.allocate(1);
					insert_pos = position->left;
				}
				else
				{
					// std::cout << "Deallocate node (" << y->right << ") for data : " << y->right->data.first << "/" << y->right->data.second << std::endl;
					this->_node_alloc.destroy(position->right);
					this->_node_alloc.deallocate(position->right, 1);
					position->right = _node_alloc.allocate(1);
					insert_pos = position->right;
				}
				construct_node(insert_pos, new_one);
				this->_node_count++;
				if (insert_pos->parent == NULL)
				{
					insert_pos->color = BLACK;
					return (insert_pos);
				}
				if (insert_pos->parent->parent == NULL)
				{
					return (insert_pos);
				}
				insert_fix(insert_pos);
				return (insert_pos);
			}
			
			node_pointer	insert ( value_type	to_insert )
			{
				Node			new_one(to_insert, NULL, NULL, NULL, RED);
				node_pointer	y = NULL;
				node_pointer	x = this->_root;
				node_pointer	insert_pos = NULL;

				while (x != NULL && !isLeaf(x))
				{
					y = x;
					if (key_compare()(new_one.data.first, x->data.first))
					{
						x = x->left;
					}
					else
					{
						x = x->right;
					}
				}
				return (insert(y, to_insert));
			}

			void	deleteNode ( node_pointer to_delete )
			{
				node_pointer	tmp;
				node_pointer	new_root;
				int				original_color;

				tmp = to_delete;
				original_color = tmp->color;
				if (isLeaf(to_delete->left))
				{
					new_root = to_delete->right;
					rbTransplant(to_delete, to_delete->right);
				}
				else if (isLeaf(to_delete->right))
				{
					new_root = to_delete->left;
					rbTransplant(to_delete, to_delete->left);
				}
				else
				{
					tmp = minimum(to_delete->right);
					original_color = tmp->color;
					new_root = tmp->right;
					if (tmp->parent == to_delete)
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
					if (isLeaf(tmp->left))
					{
						this->_node_alloc.destroy(tmp->left);
						this->_node_alloc.deallocate(tmp->left, 1);
					}
					tmp->left = to_delete->left;
					tmp->left->parent = tmp;
					tmp->color = to_delete->color;
				}
				if (isLeaf(to_delete->left) && isLeaf(to_delete->right))
				{
					this->_node_alloc.destroy(to_delete->left);
					this->_node_alloc.deallocate(to_delete->left, 1);
				}
				this->_node_alloc.destroy(to_delete);
				this->_node_alloc.deallocate(to_delete, 1);
				this->_node_count--;
				if (original_color == BLACK)
				{
					delete_fix(new_root);
				}
			}

			void	deleteNode ( value_type data )
			{
				node_pointer	tmp(this->_root);

				while (!isLeaf(tmp) && tmp != this->_empty)
				{
					if (*tmp == data)
					{
						return (deleteNode(tmp));
					}
					if (key_compare()(tmp->data.first, tmp->data.first))
					{
						tmp = tmp->right;
					}
					else
					{
						tmp = tmp->left;
					}
				}
			}

			void	deleteNode ( key_type key )
			{
				node_pointer	tmp;

				tmp = search(key);
				if (tmp != NULL)
					deleteNode(tmp);
			}

			node_pointer	search ( key_type key ) const
			{
				if (this->_root != NULL)
				{
					return (searchKeyHelper(this->_root, key));
				}
				return (NULL);
			}

			node_pointer	search ( value_type data ) const
			{
				if (this->_root != NULL)
				{
					return (searchTreeHelper(this->_root, data));
				}
				return (NULL);
			}

			void	printTree ( void ) const
			{
				if (this->_root != NULL)
				{
					printTreeHelper(this->_root, "", true);
				}
			}

			node_pointer	getRoot ( void ) const
			{
				return (this->_root);
			}

			iterator		maximum ( void ) const
			{
				node_pointer	tmp(this->_root);

				while (!isLeaf(tmp->right) && tmp->right != NULL)
				{
					tmp = tmp->right;
				}
				return (iterator(tmp));
			}

			iterator		minimum ( void ) const
			{
				node_pointer	tmp(this->_root);

				while (!isLeaf(tmp->left) && tmp->left != NULL)
				{
					tmp = tmp->left;
				}
				return (iterator(tmp));
			}

			iterator		end ( void ) const
			{
				node_pointer	tmp(this->_root);

				while (tmp->right != NULL)
				{
					tmp = tmp->right;
				}
				return (iterator(tmp));
			}

			size_t			max_size ( void )
			{
				return (node_allocator().max_size());
			}

			RedBlackTree	swap ( RedBlackTree &__rhs )
			{
				if (this->_root == NULL)
				{
					if (__rhs->_root != NULL)
					{
						this->_root = __rhs._root;
						this->_node_alloc = __rhs._node_alloc;
					}
				}
			}

			size_t			getSize ( void ) const
			{
				return (this->_node_count);
			}

			// iterator		lower_bound ( const key_type& _key )
			// {
			// 	node_pointer	tmp(this->_root);

			// 	while (!key_compare())
			// }
	};
}


#endif
