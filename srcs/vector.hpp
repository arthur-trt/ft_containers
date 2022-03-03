/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:19:04 by arthur            #+#    #+#             */
/*   Updated: 2022/03/03 17:59:21 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "random_access_iterator.hpp"

namespace ft {

	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		/** ************************************************************************** */
		/**                                  TYPEDEFS                                  */
		/** ************************************************************************** */
			/**
			**	First template parameter (T)
			*/
			typedef				T											value_type;
			/**
			**	Second template parameter (Alloc)
			*/
			typedef				Alloc										allocator_type;
			/**
			**	This types provide a reference to an element in the vector
			**	The default one is `value_type&`
			*/
			typedef typename	allocator_type::reference						reference;
			/**
			**	This types provide a constant reference to an element in the vector
			**	The default one is `const value_type&`
			*/
			typedef typename	allocator_type::const_reference					const_reference;
			/**
			**	This types provide a pointer to an element in the vector
			**	The default one is `value_type*`
			*/
			typedef typename	allocator_type::pointer							pointer;
			/**
			**	This types provide a constant pointer to an element in the vector
			**	The default one is `const value_type*`
			*/
			typedef typename	allocator_type::const_pointer					const_pointer;
			/**
			 *	A random access iterator to value_type
			 * 	Can access memory in read and write
			 */
			typedef				ft::random_access_iterator<value_type>			iterator;
			/**
			 *	A random access iterator to const value_type
			 *	Can access memory in read
			 */
			typedef				ft::random_access_iterator<const value_type>	const_iterator;
			

			typedef typename	allocator_type::size_type						size_type;


		/** ************************************************************************** */
		/**                              PRIVATE MEMBERS                               */
		/** ************************************************************************** */
		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_end_capacity;

		public:
		/** ************************************************************************** */
		/**                                CONSTRUCTORS                                */
		/** ************************************************************************** */
			/**
			**	@brief Default
			**	Empty container contructor (dafault one)
			**	Constructs an empty container with no elements
			**
			**	@param alloc	Allocator object
			**	Container keep a copy of the allocator as the second parameter
			*/
			explicit vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(0),
				_end(0),
				_end_capacity(0)
			{}

			/**
			**	@brief Fill.
			**	Construct a container with `n` elements. Each elements is a copy of `val`
			**
			**	@param n 	Number of elements to create
			**	@param val	Value of each elements
			**	@param alloc Allocator objects
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				_start = _alloc.allocate(n);
				_end_capacity = _start + n;
				_end = _start;
				while(n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}

			/**
			**	@brief Range
			**	Constructs a container with as many elements as the range [first, last)
			**	with each element constructed from its correcponding element in that range,
			**	in the same order.
			**
			**	@param	first	An iterator to the first value
			**	@param	last	An iterator to the last value
			**	@param	alloc	Allocator object
			*/
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				/**
				**	@todo Add function for insert or push back
				*/
			}

			~vector ( void )
			{
				this->clear();
				this->_alloc.deallocate(this->_start, this->capacity());
			}

		/** ************************************************************************** */
		/**                                 ITERATORS                                  */
		/** ************************************************************************** */
			/**
			 * Returns an iterator pointing to the first element in the vector.
			 * 
			 * @return An iterator to the beginning of the sequence container.
			 */
			iterator		begin ( void )
			{
				return (this->_start);
			}

			const_iterator	begin ( void ) const
			{
				return (this->_start);
			}

			/**
			 * Returns an iterator pointing to the last element in the vector.
			 * 
			 * @return An iterator to the end of the sequence container.
			 */
			iterator		end ( void )
			{
				return (this->_end);
			}

			const_iterator	end ( void ) const
			{
				return (this->_end);
			}

		/** ************************************************************************** */
		/**                                  CAPACITY                                  */
		/** ************************************************************************** */
			/**
			 * @brief Returns the number of elements in the vector.
			 * This is the number of actual objects held in the vector,
			 * which is not necessarily equal to its storage capacity.
			 * 
			 * @return The number of elements in the container.
			 */
			size_type	size ( void ) const
			{
				return (this->_end - this->_start);
			}
			
			/**
			 * @brief Returns the maximum number of elements that the vector can hold.
			 * This is the maximum potential size the container can reach due to known 
			 * system or library implementation limitations, but the container is by no 
			 * means guaranteed to be able to reach that size: it can still fail to allocate 
			 * storage at any point before that size is reached.
			 * 
			 * @return The maximum number of elements a vector container can hold as content. 
			 */
			size_type	max_size ( void ) const
			{
				return (allocator_type().max_size());
			}

			/**
			 * @brief Resizes the container so that it contains n elements.
			 * If n is smaller than the current container size, the content is reduced to its first n elements,
			 * removing those beyond (and destroying them).
			 * If n is greater than the current container size, the content is expanded by inserting at the end
			 * as many elements as needed to reach a size of n. If val is specified,
			 * the new elements are initialized as copies of val, otherwise, they are value-initialized.
			 * If n is also greater than the current container capacity,
			 * an automatic reallocation of the allocated storage space takes place.
			 * 
			 * @param n New container size, expressed in number of elements.
			 * @param val Object whose content is copied to the added elements in case that n is
			 * greater than the current container size.
			 */
			void		resize ( size_type n, value_type val = value_type() )
			{
				if (n < this->size())
					this->erase(this.begin() + n, this.end());
				else
					this->insert(this.end(), n - this->size(), val);
			}

			/**
			 * @brief Returns the size of the storage space currently allocated for the vector,
			 * expressed in terms of elements.
			 * 
			 * @return The size of the currently allocated storage capacity in the vector,
			 * measured in terms of the number elements it can hold.
			 */
			size_type	capacity ( void ) const
			{
				return (size_type(const_iterator(this->_end_capacity) - this->begin()));
			}

			/**
			 * @brief Returns whether the vector is empty (i.e. whether its size is 0).
			 * 
			 * @return True if empty, false overwise
			 */
			bool		empty( void ) const
			{
				return (this->begin() == this->end());
			}

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 * If n is greater than the current vector capacity, the function causes the container
			 * to reallocate its storage increasing its capacity to n (or greater).
			 * 
			 * @param n Minimum capacity for the vector.
			 */
			void		reserve ( size_type n )
			{
				if (n > this->max_size())
					throw (std::length_error());
				if (n > this->capacity())
				{
					pointer	new_array;
					
					new_array = this->_alloc.allocate(n);
					for (size_type i = 0; i < this->_end; i++)
					{
						this->_alloc.construct(&new_array[i], this->_start[i]);
						this->_alloc.destroy(&this->_start[i]);
					}
					this->_alloc.deallocate(this->_start, this->_end_capacity);
					this->_start = new_array;
					this->_end_capacity= n;					
				}
			}

		/** ************************************************************************** */
		/**                               ELEMENT ACCESS                               */
		/** ************************************************************************** */
			/**
			 * @brief Returns a reference to the element at position n in the vector container.
			 * 
			 * @param n Position of an element in the container.
			 * 
			 * @return The element at the specified position in the vector.
			 */
			reference		operator[] ( size_type n )
			{
				return (*(this->_start + n));	
			}

			const_reference	operator[] ( size_type n ) const
			{
				return (*(this->_start + n));
			}

			/**
			 * @brief Returns a reference to the element at position n in the vector.
			 * 
			 * @param n Position of an element in the container.
			 * @return reference 
			 */
			reference		at ( size_type n )
			{
				if (n >= this->size())
					throw (std::out_of_range());
				return (this->operator[](n));				
			}

			const_reference	at ( size_type n ) const
			{
				if (n >= this->size())
					throw (std::out_of_range());
				return (this->operator[](n));	
			}

			/**
			 * @brief Returns a reference to the first element in the vector.
			 * 
			 * @return A reference to the first element in the vector container. 
			 */
			reference		front ( void )
			{
				return (*(this->_start));
			}

			const_reference	front ( void ) const
			{
				return (*(this->_start));
			}

			/**
			 * @brief Returns a reference to the last element in the vector.
			 * 
			 * @return A reference to the last element in the vector container. 
			 */
			reference		back ( void )
			{
				return (*(this->_end - 1));
			}

			const_reference	back ( void ) const
			{
				return (*(this->_end - 1));
			}

		/** ************************************************************************** */
		/**                                  MODIFIERS                                 */
		/** ************************************************************************** */
			/**
			 * @brief Range.
			 * The new contents are elements constructed from each of the elements in
			 * the range between first and last, in the same order.
			 * 
			 * @param first Input iterators to the initial position in a sequence
			 * @param last Input iterators to the final position in a sequence
			 */
			template <class InputIterator>
			void		assign ( InputIterator first, InputIterator last )
			{
				/**
				 * @todo
				 */
			}

			/**
			 * @brief Fill.
			 * The new contents are n elements, each initialized to a copy of val.
			 * 
			 * @param n New size for the container.
			 * @param val Value to fill the container with
			 */
			void		assign ( size_type n, const value_type& val )
			{
				
			}

			/**
			 * @brief Adds a new element at the end of the vector,
			 * after its current last element.
			 * The content of val is copied (or moved) to the new element.
			 * 
			 * @param val Value to be copied (or moved) to the new element.
			 */
			void		push_back ( const value_type& val )
			{
				if (this->_end == this->_end_capacity)
				{
					/**
					 * @todo
					 * 
					 */
				}
				this->_alloc.construct (this->_end, val);
				this->_end++;
			}

			/**
			 * @brief Removes the last element in the vector,
			 * effectively reducing the container size by one.
			 * This destroys the removed element.
			 */
			void		pop_back( void )
			{
				this->_alloc.destroy(&(this->_end));
				this->_end--;
			}

			/**
			 * @brief Single element.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted.
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 * @return An iterator that points to the first of the newly inserted elements.
			 */
			iterator	insert ( iterator position, const value_type& val )
			{
				
			}

			/**
			 * @brief Fill.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted. 
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param n Number of elements to insert.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 */
			void		insert ( iterator position, size_type n, const value_type& val )
			{
				
			}

			/**
			 * @brief Range.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted.
			 * 
			 * @param position Position in the vector where the new elements are inserted.
			 * @param first Input iterators to the initial position in a sequence
			 * @param last Input iterators to the final position in a sequence
			 */
			template <class InputIterator>
    		void		insert (iterator position, InputIterator first, InputIterator last)
			{
				
			}

			/**
			 * @brief Removes from the vector a single element (position)
			 * 
			 * @param position Iterator pointing to a single element to be removed from the vector.
			 * @return An iterator pointing to the new location of the element that followed the
			 * last element erased by the function call
			 */
			iterator	erase ( iterator position )
			{
				
			}

			/**
			 * @brief Removes from the vector a range of elements ([first,last))
			 * 
			 * @param first Input iterators to the initial position in a sequence
			 * @param last Input iterators to the final position in a sequence
			 * 
			 * @return An iterator pointing to the new location of the element that followed the
			 * last element erased by the function call
			 */
			iterator	erase (iterator first, iterator last)
			{
				size_type	count = last - first;
				if (count <= count)
					return (last);
				
			}

			/**
			 * @brief Exchanges the content of the container by the content of x,
			 * which is another vector object of the same type. Sizes may differ.
			 * 
			 * @param x Another vector container of the same type
			 */
			void	swap ( vector& x )
			{
				std::swap(this->_start, x._start);
				std::swap(this->_end, x._end);
				std::swap(this->_end_capacity, this->_end_capacity);
			}

			/**
			 * @brief Removes all elements from the vector (which are destroyed),
			 * leaving the container with a size of 0.
			 */
			void	clear( void )
			{
				this->erase(this->begin(), this->end());
			}

		/** ************************************************************************** */
		/**                                  ALLOCATOR                                 */
		/** ************************************************************************** */
			/**
			 * @brief Returns a copy of the allocator object associated with the vector.
			 * 
			 * @return The allocator.
			 */
			allocator_type	get_allocator ( void ) const
			{
				return (this->_alloc);
			}
	};
	
}

#endif
