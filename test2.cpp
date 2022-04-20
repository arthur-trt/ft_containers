#include "includes/RBTree/rb_tree.hpp"
#include "includes/RBTree/rb_tree_iterator.hpp"
#include "includes/utils/pair.hpp"
#include <iostream>
#include <string>
#include <map>
#include "includes/map.hpp"

// #include "includes/test.hpp"


int main(void)
{
	// ft::pair<const int, int>	test(17, 18);
	// ft::pair<const int, int>	test2(test);

	// // test2 = ft::make_pair<const int, int>(17, 18);

	ft::RedBlackTree<int, std::pair<int, int> >				test;
	

	for (size_t i = 0; i < 2; i++)
	{
		test.insert(std::make_pair<int, int>(i, i));
	}
	test.deleteNode(1);
	std::cout << "DEbugger" ;
	// ft::RedBlackTree<int, std::pair<int, int> >::iterator	it(test.search(0));

	// while (it != test.end())
	// {
	// 	std::cout << it->first << ": \"" << it->second << "\"" <<std::endl;
		
	// }	
	
	// std::map<const int, int>								test2;
	// std::map<const int, int>::reverse_iterator				it;
	// // ft::pair<ft::map<const int, int>::iterator, bool>	res;

	// for (size_t i = 0; i < 2; i++)
	// {
	// 	// std::cout << i << std::endl;
	// 	test2.insert(std::make_pair<int, int>(i, i));
	// 	// std::cout << i << std::endl;

	// }

	// it = test2.rbegin();
	// while (it != test2.rend())
	// {
	// 	std::cout << it->first << ": \"" << it->second << "\"" << std::endl;
	// 	it++;
	// }
	// test2.insert(std::make_pair<int, int>(5, 5));
	// std::cout << std::boolalpha << test2.empty() << std::endl;
	// test2.deleteNode(5);
	// std::cout << std::boolalpha << test2.empty() << std::endl;
}
