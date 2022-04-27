/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:26:21 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/27 18:18:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester/tester.hpp"
# include "tester/tester_out.hpp"
# include "tester/map_test.hpp"
# include "map.hpp"
# include <map>
# include <fstream>
# include <list>
# include <sys/time.h>

using namespace NS;

static void test_simple_insert( my_out output )
{
	map<int, int> mymap;

	mymap.insert(make_pair(0, 2));
	mymap.insert(make_pair(1, 5));
	mymap.insert(make_pair(1, 8));

	for (size_t l = 0; l < 50; l++)
		mymap.insert(make_pair(l, 2 * l));

	display_map(mymap, output);
}

static void test_accessors( my_out output )
{
	map<int, int> mymap;

	mymap.insert(make_pair(0, 2));
	mymap.insert(make_pair(1, 5));
	mymap.insert(make_pair(1, 8));

	for (size_t l = 0; l < 50; l++)
		mymap.insert(make_pair(l, 2 * l));

	display_map(mymap, output);

	mymap.clear();
	display_map(mymap, output);
	mymap.insert(make_pair(0, 2));
	mymap.insert(make_pair(1, 5));
	mymap.insert(make_pair(1, 8));
	display_map(mymap, output);

}

static void test_index( my_out output )
{
	map<int, int> mymap;

	mymap[0] = 2;
	mymap[1] = 5;
	mymap[1] = 8;

	for (size_t l = 0; l < 50; l++)
		mymap.insert(make_pair(l, 2 * l));

	display_map(mymap, output);

	mymap.clear();
	display_map(mymap, output);
	mymap.insert(make_pair(0, 2));
	mymap.insert(make_pair(1, 5));
	mymap.insert(make_pair(1, 8));
	display_map(mymap, output);

}

static void test_constructors( my_out output )
{
	map<int, int> mymap;
	mymap[0] = 50;
	mymap[90] = 5;
	mymap[2] = 80;

	display_map(mymap, output);
	map<int, int> cpy;

	cpy = mymap;
	display_map(cpy, output);
	cpy[5] = 8;
	mymap[5] = 80;
	mymap[9] = 80;
	display_map(cpy, output);
	display_map(mymap, output);
	swap(cpy, mymap);

	display_map(cpy, output);
	display_map(mymap, output);
	map<int, int> cpy2(cpy);
	display_map(cpy2, output);
}

static void test_iterators( my_out output )
{
	map<int, int> mymap;
	mymap[0] = 50;
	mymap[90] = 5;
	mymap[2] = 80;

	display_map(mymap, output);
}

static void test_reverse_iterators( my_out output )
{
	map<int, int> mymap;
	mymap[0] = 50;
	mymap[90] = 5;
	mymap[2] = 80;

	display_map_reverse(mymap, output);
}

static void test_insert( my_out output )
{
	map<int, int> mymap;
	mymap[0] = 50;
	mymap[90] = 5;
	mymap[2] = 80;

	pair<int, int> tab[6] = {
		make_pair(0, 1),
		make_pair(50, 2),
		make_pair(6, 4),
		make_pair(-45, -5),
		make_pair(4, 98),
		make_pair(6, 9),
	};

	mymap.insert(tab, tab + 6);
	display_map(mymap, output);
	mymap.clear();
	mymap.insert(tab, tab + 6);
	display_map(mymap, output);
}

static void test_cmp( my_out output )
{
	map<int, int> mymap_one;
	mymap_one[0] = 50;
	mymap_one[90] = 5;

	map<int, int> mymap_two;
	mymap_two[0] = 50;
	mymap_two[90] = 5;
	mymap_two[2] = 80;

	display_map(mymap_one, output);
	display_map(mymap_two, output);


	output	<< std::boolalpha
			<< (mymap_one != mymap_two) << std::endl
			<< (mymap_two < mymap_one) << std::endl
			<< (mymap_two <= mymap_one) << std::endl
			<< (!(mymap_two > mymap_one)) << std::endl
			<< (!(mymap_two >= mymap_one)) << std::endl;

	mymap_one[2] = 80;
	output	<< std::boolalpha
			<< (mymap_one == mymap_two) << std::endl
			<< (!(mymap_two < mymap_one)) << std::endl
			<< (mymap_two <= mymap_one) << std::endl
			<< (!(mymap_two > mymap_one)) << std::endl
			<< (mymap_two >= mymap_one) << std::endl;

	mymap_one[1] = 4;
	output	<< std::boolalpha
			<< (mymap_one != mymap_two) << std::endl
			<< (mymap_two > mymap_one) << std::endl
			<< (mymap_two >= mymap_one) << std::endl
			<< (!(mymap_two < mymap_one)) << std::endl
			<< (!(mymap_two <= mymap_one)) << std::endl;
}

static void test_swap( my_out output )
{
	map<int, int> mymap_1;
	mymap_1[10] = 96;
	mymap_1[36] = 9;
	mymap_1[8] = 8;

	map<int, int> mymap_2;
	mymap_2[0] = 50;
	mymap_2[90] = 5;

	display_map(mymap_1, output);
	display_map(mymap_2, output);

	swap(mymap_1, mymap_2);

	display_map(mymap_1, output);
	display_map(mymap_2, output);

	mymap_2.swap(mymap_1);

	display_map(mymap_1, output);
	display_map(mymap_2, output);

}

static void test_count_find( my_out output )
{
	map<int, int> mymap;
	mymap[10] = 96;
	mymap[36] = 9;
	mymap[8] = 8;

	output	<< std::boolalpha
			<< (mymap.find(10)->second == 96) << std::endl
			<< (mymap.find(36)->second == 9) << std::endl
			<< (mymap.find(99) == mymap.end()) << std::endl
			<< (mymap.find(8) == mymap.begin()) << std::endl
			<< (mymap.count(10) == 1) << std::endl
			<< (mymap.count(9) == 0) << std::endl
			<< (mymap.count(36) == 1) << std::endl
			<< (mymap.count(55) == 0) << std::endl;
}

static void test_range( my_out output )
{
	map<int, int> mymap;
	mymap[10] = 96;
	mymap[36] = 9;
	mymap[8] = 8;

	display_map(mymap, output);

	map<int, int>::iterator ite = mymap.begin();
	++ite;

	output	<< std::boolalpha
			<< (mymap.lower_bound(5) == mymap.begin()) << std::endl
			<< (mymap.lower_bound(9) != mymap.begin()) << std::endl
			<< (mymap.lower_bound(9) == ite) << std::endl
			<< (mymap.lower_bound(60) == mymap.end()) << std::endl;
	++ite;

	output	<< std::boolalpha
			<< (mymap.lower_bound(35) == ite) << std::endl
			<< (mymap.lower_bound(36) == ite) << std::endl
			<< (mymap.lower_bound(37) != ite) << std::endl;
	++ite;
	output	<< std::boolalpha
			<< (mymap.lower_bound(37) == ite) << std::endl
			<< (mymap.lower_bound(37) == mymap.end()) << std::endl;

	ite = mymap.begin();

	output	<< std::boolalpha
			<< (mymap.upper_bound(5) == ite) << std::endl
			<< (mymap.upper_bound(6) == ite) << std::endl
			<< (mymap.upper_bound(8) != ite) << std::endl;
	++ite;
	output	<< std::boolalpha
			<< (mymap.upper_bound(8) == ite) << std::endl
			<< (mymap.upper_bound(9) == ite) << std::endl
			<< (mymap.upper_bound(10) != ite) << std::endl;
	++ite;
	output	<< std::boolalpha
			<< (mymap.upper_bound(10) == ite) << std::endl
			<< (mymap.upper_bound(30) == ite) << std::endl;

	typedef map<int, int>::iterator iter;
	pair<iter, iter> range;

	range = mymap.equal_range(8);
	ite = mymap.begin();
	output	<< std::boolalpha
			<< (range.first == mymap.begin() && range.second == ++ite) << std::endl;

	range = mymap.equal_range(36);
	ite = mymap.begin();
	++ite;
	output	<< std::boolalpha
			<< (range.first == ++ite && range.second == ++ite) << std::endl;

	range = mymap.equal_range(50);
	output	<< std::boolalpha
			<< (range.first == mymap.end()) << std::endl
			<< (range.second == mymap.end()) << std::endl;

	range = mymap.equal_range(0);
	output	<< std::boolalpha
			<< (range.first == mymap.begin()) << std::endl
			<< (range.second == mymap.begin()) << std::endl;
}

int main ( void )
{

	struct timeval begin, end;
	gettimeofday(&begin, 0);

	std::ofstream	satck_out;
	satck_out.open(STRINGIFY(MAPFILE), std::ofstream::out);
	my_out	output(satck_out, std::cout);

	output << CONTAINER_TEST("MAP");
	output << CATEGORY_TEST("Simple");
	test_simple_insert(output);
	output << CATEGORY_TEST("Accessors");
	test_accessors(output);
	output << CATEGORY_TEST("Index");
	test_index(output);
	output << CATEGORY_TEST("Constructors");
	test_constructors(output);
	output << CATEGORY_TEST("Iterators");
	test_iterators(output);
	output << CATEGORY_TEST("Reverse Iterators");
	test_reverse_iterators(output);
	output << CATEGORY_TEST("Insert");
	test_insert(output);
	output << CATEGORY_TEST("Comparaisons");
	test_cmp(output);
	output << CATEGORY_TEST("Swap");
	test_swap(output);
	output << CATEGORY_TEST("Count find");
	test_count_find(output);
	output << CATEGORY_TEST("Range");
	test_range(output);

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds*1e-6;

	output << "Time elapsed : " << elapsed << std::endl;

	return 0;

	//test_one("simple_insert", test_simple_insert);
	//test_one("accessors", test_accessors);
	//test_one("index", test_index);
	//test_one("constructors", test_constructors);
	//test_one("iterators", test_iterators);
	//test_one("reverse_iterators", test_reverse_iterators);
	//test_one("insert", test_insert);
	//test_one("cmp", test_cmp);
	//test_one("swap", test_swap);
	//test_one("count_find", test_count_find);
	//test_one("range", test_range);
}
