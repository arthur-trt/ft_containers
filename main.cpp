/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:32:30 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/03 17:12:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "srcs/vector.hpp"
# include <vector>

int	main(void)
{
	std::vector<int> test(10, 17);
	std::vector<int>::iterator it(test.begin());
	std::vector<int>::iterator ite(test.end());

	test.erase(ite);
	
	return (0);
}
