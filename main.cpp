/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:32:30 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/04 22:55:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "srcs/random_access_iterator.hpp"
# include "srcs/utils/utils.hpp"
# include "srcs/utils/iterator_traits.hpp"
# include "srcs/vector.hpp"
# include <vector>
# include <iostream>
# include <string>
# include <iomanip>

int	main(void)
{
	int	n = 10;
	std::string	val("je test");
	int	i = 0;


	ft::vector<std::string> test1(n, val);
	ft::vector<std::string>	test2(test1);

	test1.pop_back();
	// test1.pop_back();

	test1.insert(test1.begin() + 2, std::string("super"));
	ft::vector<std::string>::iterator it(test1.begin());
	while (it != test1.end())
	{
		std::cout << *it << std::endl;
		i++;
		++it;
	}


	return (0);
}
