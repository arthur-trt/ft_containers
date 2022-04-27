/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 10:38:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "rb_node.hpp"
# include "rb_tree_iterator.hpp"
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"
# include <memory>
# include <functional>
# include <cstddef>
# include <iostream>
# include "../utils/pair.hpp"

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
								rebind<Node>::other	node_allocator;

			typedef typename	node_allocator::pointer				node_pointer;
			typedef typename	node_allocator::reference			node_reference;

			typedef				ft::rb_tree_iterator<T>				iterator;

		private:
		/** ************************************************************************** */
		/**                             MEMBER VARIABLES                               */
		/** ************************************************************************** */
			node_pointer	_root;
			node_pointer	_empty;
			node_pointer	_leaf_left;
			node_pointer	_leaf_right;
			node_allocator	_node_alloc;
			size_t			_node_count;

			bool _comp(value_type a, value_type b, Compare u = Compare())
			{
				return u(a.first, b.first);
			}

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

			bool		isLeaf( node_pointer node ) const
			{
				if (node->parent == NULL && node->left == NULL && node->right == NULL)
					return (true);
				return (false);
			}

			void	delete_tree ( node_pointer root )
			{
				if (root != NULL)
				{
					delete_tree(root->left);
					delete_tree(root->right);
				}
				if (root != this->_empty && root != NULL && root != this->_leaf_left && root != this->_leaf_right)
				{
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
				while (node->right != this->_empty)
				{
					node = node->right;
				}
				return (node);
			}

			node_pointer	minimum ( node_pointer node )
			{
				while (node->left != this->_empty)
				{
					node = node->left;
				}
				return (node);
			}

			void	printTreeHelper ( node_pointer node, std::string indent, bool side ) const
			{
				if (node != this->_empty)
				{
					std::cout << indent;
					if (node == this->_leaf_left)
					{
						std::cout << "L----";
						std::cout << "Left leaf" << std::endl;
					}
					else if (node == this->_leaf_right)
					{
						std::cout << "R----";
						std::cout << "r_leaf_right leaf" << std::endl;
					}
					else
					{
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
			}

			iterator	searchTreeHelper ( node_pointer node, value_type data ) const
			{
				if (node == NULL || isLeaf(node))
				{
					return (this->end());
				}
				if (!key_compare()(node->data.first, data.first) && !key_compare()(data.first, node->data.first))
				{
					return (iterator(node));
				}
				if (key_compare()(data.first, node->data.first))
				{
					return (searchTreeHelper(node->left, data));
				}
				return (searchTreeHelper(node->right, data));
			}

			iterator	searchTreeHelper ( node_pointer node, key_type key ) const
			{
				if (node == NULL || isLeaf(node))
				{
					return (this->end());
				}
				if (!key_compare()(node->data.first, key) && !key_compare()(key, node->data.first))
				{
					return (iterator(node));
				}
				if (key_compare()(key, node->data.first))
				{
					return (searchTreeHelper(node->left, key));
				}
				return (searchTreeHelper(node->right, key));
			}

			void	setHeader ( void )
			{
				node_pointer	most_right = this->maximum(this->_root);
				node_pointer	most_left = this->minimum(this->_root);


				this->_leaf_right->parent = most_right;
				this->_leaf_right->parent->right = this->_leaf_right;

				this->_leaf_left->parent = most_left;
				this->_leaf_left->parent->left = this->_leaf_left;

				this->_empty->parent = 0;
			}

			void	unsetHeader ( void )
			{
				if (this->_leaf_right->parent)
				{
						this->_leaf_right->parent->right = this->_empty;
				}
				if (this->_leaf_left->parent)
				{
						this->_leaf_left->parent->left = this->_empty;
				}
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
				this->_leaf_left = _node_alloc.allocate(1);
				_node_alloc.construct(this->_leaf_left, tmp);
				this->_leaf_right = _node_alloc.allocate(1);
				_node_alloc.construct(this->_leaf_right, tmp);
				this->_root = NULL;
				this->_node_count = 0;
			}

			RedBlackTree ( const RedBlackTree & src )
			{
				Node		tmp;
				iterator	it;

				this->_empty = _node_alloc.allocate(1);
				_node_alloc.construct(this->_empty, tmp);
				this->_leaf_left = _node_alloc.allocate(1);
				_node_alloc.construct(this->_leaf_left, tmp);
				this->_leaf_right = _node_alloc.allocate(1);
				_node_alloc.construct(this->_leaf_right, tmp);
				this->_root = NULL;
				this->_node_count = 0;

				it = src.begin();
				while (it != src.end())
				{
					insert(*it);
					it++;
				}
			}

			~RedBlackTree ( void )
			{
				delete_tree(this->_root);
				_node_alloc.destroy(this->_empty);
				_node_alloc.deallocate(this->_empty, 1);
				_node_alloc.destroy(this->_leaf_left);
				_node_alloc.deallocate(this->_leaf_left, 1);
				_node_alloc.destroy(this->_leaf_right);
				_node_alloc.deallocate(this->_leaf_right, 1);
			}

		/** ************************************************************************** */
		/**                             MEMBER FUNCTIONS                               */
		/** ************************************************************************** */
			iterator	insert ( value_type	to_insert )
			{
				Node			new_one(to_insert, NULL, this->_empty, this->_empty, RED);
				node_pointer	y = NULL;
				node_pointer	x = this->_root;
				node_pointer	insert_pos = NULL;

				this->unsetHeader();
				while (x != NULL && x != this->_empty)
				{
					y = x;
					if (_comp(new_one.data, x->data))
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
				else if (key_compare()(new_one.data.first, y->data.first))
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
				this->_node_count++;
				if (insert_pos->parent == NULL)
				{
					this->setHeader();
					insert_pos->color = BLACK;
					return (iterator(insert_pos));
				}
				if (insert_pos->parent->parent == NULL)
				{
					this->setHeader();
					return (iterator(insert_pos));
				}
				insert_fix(insert_pos);
				this->setHeader();
				return (iterator(insert_pos));
			}

			void	deleteNode ( node_pointer to_delete )
			{
				node_pointer	tmp;
				node_pointer	new_root;
				int				original_color;

				this->unsetHeader();
				tmp = to_delete;
				original_color = tmp->color;
				if (to_delete->left == this->_empty)
				{
					new_root = to_delete->right;
					rbTransplant(to_delete, to_delete->right);
				}
				else if (to_delete->right == this->_empty)
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
					tmp->left = to_delete->left;
					tmp->left->parent = tmp;
					tmp->color = to_delete->color;
				}
				this->_node_alloc.destroy(to_delete);
				this->_node_alloc.deallocate(to_delete, 1);
				this->_node_count--;
				if (original_color == BLACK)
				{
					delete_fix(new_root);
				}
				if (!isLeaf(this->_root))
					this->setHeader();
				else
				{
					this->_root = NULL;
				}
			}

			void	deleteNode ( value_type data )
			{
				node_pointer	tmp(this->_root);

				while (tmp != this->_empty)
				{
					if ((*tmp).data == data)
					{
						return (deleteNode(tmp));
					}
					if (key_compare()(tmp->data.first, data.first))
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
				if (tmp != this->end())
					deleteNode(tmp);
			}

			void		clear ( void )
			{
				delete_tree(this->_root);
				this->_root = NULL;
				this->_node_count = 0;
				this->_leaf_left->parent = NULL;
				this->_leaf_right->parent = NULL;
			}

			iterator	search ( value_type data ) const
			{
				if (this->_root != NULL)
				{
					return (searchTreeHelper(this->_root, data));
				}
				return (this->end());
			}

			iterator	search ( key_type key ) const
			{
				if (this->_root != NULL)
				{
					return (searchTreeHelper(this->_root, key));
				}
				return (this->end());
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

			iterator		end ( void ) const
			{
				return (iterator(this->_leaf_right));
			}

			iterator		begin ( void ) const
			{
				if (this->_root == NULL)
					return (this->end());
				return (iterator(this->_leaf_left->parent));
			}

			size_t			max_size ( void ) const
			{
				return (node_allocator().max_size());
			}

			void		swap ( RedBlackTree &__rhs )
			{
				__rhs.unsetHeader();
				this->unsetHeader();
				std::swap(this->_root, __rhs._root);
				std::swap(this->_leaf_left, __rhs._leaf_left);
				std::swap(this->_leaf_right, __rhs._leaf_right);
				std::swap(this->_empty, __rhs._empty);
				std::swap(this->_node_count, __rhs._node_count);
				if (this->_root)
					this->setHeader();
				if (__rhs._root)
					__rhs.setHeader();
				std::swap(this->_node_alloc, __rhs._node_alloc);

			}

			size_t			getSize ( void ) const
			{
				return (this->_node_count);
			}
			template <class T1, class T2, class T3, class T4>
			friend inline bool	operator== (	const RedBlackTree<T1, T2, T3, T4> &__lhs,
												const RedBlackTree<T1, T2, T3, T4> &__rhs );

			template <class T1, class T2, class T3, class T4>
			friend inline bool	operator< (	const RedBlackTree<T1, T2, T3, T4> & __rhs,
											const RedBlackTree<T1, T2, T3, T4> & __lhs );
	};

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator== (	const RedBlackTree<_Key, T, Compare, Alloc> &__lhs,
								const RedBlackTree<_Key, T, Compare, Alloc> &__rhs )
	{
		return (	__lhs._node_count == __rhs._node_count &&
					ft::equal(__lhs.begin(), __lhs.end(), __rhs.begin()));
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator!= (	const RedBlackTree<_Key, T, Compare, Alloc> &__lhs,
								const RedBlackTree<_Key, T, Compare, Alloc> &__rhs )
	{
		return (!(__lhs == __rhs));
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator< (	const RedBlackTree<_Key, T, Compare, Alloc> & __rhs,
							const RedBlackTree<_Key, T, Compare, Alloc> & __lhs )
	{
		return (ft::lexicographical_compare(__rhs.begin(), __rhs.end(), __lhs.begin(), __lhs.end()));
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator> (	const RedBlackTree<_Key, T, Compare, Alloc> & __rhs,
							const RedBlackTree<_Key, T, Compare, Alloc> & __lhs )
	{
		return (__lhs < __rhs);
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator<=	(	const RedBlackTree<_Key, T, Compare, Alloc> & __rhs,
								const RedBlackTree<_Key, T, Compare, Alloc> & __lhs )
	{
		return (!(__lhs < __rhs));
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline bool	operator>=	(	const RedBlackTree<_Key, T, Compare, Alloc> & __rhs,
								const RedBlackTree<_Key, T, Compare, Alloc> & __lhs )
	{
		return (!(__rhs < __lhs));
	}

	template <class _Key, class T, class Compare, class Alloc>
	inline void	swap		(	const RedBlackTree<_Key, T, Compare, Alloc> & __rhs,
								const RedBlackTree<_Key, T, Compare, Alloc> & __lhs )
	{
		__rhs.swap(__lhs);
	}

}


#endif
