/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:19:46 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 17:38:34 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "tester_out.hpp"

using namespace NS;


template <typename T_MAP>
void	display_map(T_MAP const &map, my_out output)
{
	output << BOLD("-> output : ") << std::endl;

	output << FG1("Content :") << std::endl;
	typename T_MAP::const_iterator it = map.begin(), ite = map.end();
	while (it != ite)
	{
		output << *it << std::endl;
		it++;
	}
	output << DIM("size : ") << map.size() << std::endl;
	output << std::endl;
}

template <typename T_MAP>
void	display_map_reverse(T_MAP const &map, my_out output)
{
	output << BOLD("-> output : ") << std::endl;

	output << FG1("Content :") << std::endl;
	typename T_MAP::const_reverse_iterator it = map.rbegin(), ite = map.rend();
	while (it != ite)
	{
		output << *it << std::endl;
		it++;
	}
	output << DIM("size : ") << map.size() << std::endl;
	output << std::endl;
}


#endif
