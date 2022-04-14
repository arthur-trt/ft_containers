#include "includes/RBTree/rb_tree.hpp"
#include "includes/utils/pair.hpp"
#include <iostream>
#include <string>

#include "includes/test.hpp"


int main(void)
{
	ft::RedBlackTree<int, ft::pair<int, std::string>, std::greater<int> >	test;

	test.insert(ft::make_pair<int, std::string>(1, "un"));
	test.insert(ft::make_pair<int, std::string>(2, "deux"));
	test.insert(ft::make_pair<int, std::string>(3, "trois"));
	test.insert(ft::make_pair<int, std::string>(4, "quatre"));
	test.insert();
	//test.insert();
	//test.insert();
	//test.insert();

	test.printTree();

	//ft::pair<int, std::string>	test;
	//ft::pair<int, std::string>	test2;

	//fun<ft::pair<int, std::string>, ft::pair<int, std::string> > super;

	//test = ft::make_pair<int, std::string>(5, "cinq");

	//test2 = ft::make_pair<int, std::string>(10, "dix");

	//std::cout << super.fun2(test, test2);
}
