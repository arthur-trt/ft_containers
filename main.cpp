/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:32:30 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/15 12:10:48 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "srcs/random_access_iterator.hpp"
# include "srcs/utils.hpp"
# include "srcs/iterator_traits.hpp"
# include "srcs/vector.hpp"
# include <vector>
# include <iostream>
# include <string>
# include <iomanip>
# include "tester.hpp"
# include "reverse_iterator.hpp"
# include <vector>
# include <fstream>
# include <string>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(vector<vector<T> >& lst)
{
	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(vector<T>& lst)
{
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}


int main ()
{
  vector<int> foo (3,0);
  vector<int> bar (5,0);

  bar = foo;
  foo = vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
  return 0;
}
