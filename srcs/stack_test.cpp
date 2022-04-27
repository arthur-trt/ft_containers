/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:44:28 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 16:19:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester/tester.hpp"
# include "tester/tester_out.hpp"
# include "tester/stack_test.hpp"
# include "stack.hpp"
# include <stack>
# include <fstream>
# include <list>
# include <sys/time.h>

#define TESTED_TYPE foo<int>

using namespace NS;

void	simple_one ( my_out output )
{
	NS::stack<TESTED_TYPE> stck;

	output << "empty: " << stck.empty() << std::endl;
	output << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	output << "Added some elements" << std::endl;

	output << "empty: " << stck.empty() << std::endl;
	display_stack(stck, output);

}

void	copy_constructor ( my_out output )
{
	NS::stack<TESTED_TYPE>::container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	NS::stack<TESTED_TYPE>		stck(ctnr);

	output << "empty: " << stck.empty() << std::endl;
	output << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	output << "Added some elements" << std::endl;

	output << "empty: " << stck.empty() << std::endl;
	display_stack(stck, output);
}

void	list_copy ( my_out output )
{
	std::list<TESTED_TYPE>	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	NS::stack<TESTED_TYPE, std::list<TESTED_TYPE> >	stck(ctnr);

	output << "empty: " << stck.empty() << std::endl;
	output << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	output << "Added some elements" << std::endl;

	output << "empty: " << stck.empty() << std::endl;
	display_stack(stck, output);
}

void	relationnal_operator ( my_out output )
{
	NS::stack<int>::container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	NS::stack<int>	stck(ctnr);
	NS::stack<int>	stck2(ctnr);

	cmp(stck, stck, output);  // 0
	cmp(stck, stck2, output); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2, output); // 2
	cmp(stck2, stck, output); // 3

	stck.push(42);

	cmp(stck, stck2, output); // 4
	cmp(stck2, stck, output); // 5

	stck.push(100);

	cmp(stck, stck2, output); // 6
	cmp(stck2, stck, output); // 7
}

void	relationnal_operator_list ( my_out output )
{
	std::list<int>	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	NS::stack<int, std::list<int> >	stck(ctnr);
	NS::stack<int, std::list<int> >	stck2(ctnr);

	cmp(stck, stck, output);  // 0
	cmp(stck, stck2, output); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2, output); // 2
	cmp(stck2, stck, output); // 3

	stck.push(42);

	cmp(stck, stck2, output); // 4
	cmp(stck2, stck, output); // 5

	stck.push(100);

	cmp(stck, stck2, output); // 6
	cmp(stck2, stck, output); // 7
}


int	main(void)
{
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	std::ofstream	satck_out;
	satck_out.open(STRINGIFY(STACKFILE), std::ofstream::out);
	my_out	output(satck_out, std::cout);

	output << CONTAINER_TEST("VECTOR");
	output << CATEGORY_TEST("Simple");
	simple_one(output);
	output << CATEGORY_TEST("Copy constructor");
	copy_constructor(output);
	output << CATEGORY_TEST("List copy");
	list_copy(output);
	output << CATEGORY_TEST("Relationnal operator");
	relationnal_operator(output);
	output << CATEGORY_TEST("Relationnal operator list");
	relationnal_operator_list(output);

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds*1e-6;

	output << "Time elapsed : " << elapsed << std::endl;

	return 0;

}
