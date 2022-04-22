#include "includes/RBTree/rb_tree.hpp"
#include "includes/RBTree/rb_tree_iterator.hpp"
#include "includes/utils/pair.hpp"
#include <iostream>
#include <string>
#include <map>
#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/tester/tester_out.hpp"
#include <cstdlib>
#include <memory>
#include <algorithm>    // For std::shuffle
//#include <random>


int main(void)
{
	srand((unsigned) time(0));
	ft::vector<int>								vec;
	ft::vector<int>::iterator					it;
	ft::map<int, int >							test;

	for (size_t i = 1000; i > 0; i--)
	{
		vec.insert(vec.begin(), i);
	}
    std::random_shuffle(vec.begin(), vec.end());

	for (size_t i = 0; i < 900; i++)
	{
		vec.erase(vec.begin() + (rand() % (vec.size() - 1)));
	}
	it = vec.begin();

	while (it != vec.end())
	{
		test.insert(ft::make_pair<int, int>(*it, *it));
		it++;
	}

	//test.printTree();
	ft::map<int, int>::reverse_iterator	it2 = test.rbegin();
	ft::map<int, int>::iterator			it3;
	while (it2 != test.rend())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}

	std::cout << *(test.lower_bound(384)) << std::endl;

	//for (size_t i = 0; i < 100; i++)
	//{
	//	it3 = test.find(i);
	//	if (it3 != test.end())
	//		std::cout << *(test.find(i)) << std::endl;
	//}



	//(rand() % vec.size());

	//ft::RedBlackTree<int, ft::pair<int, int> >::iterator	it = test.minimum();

	//while (it != test.end())
	//{
		//std::cout << *it << std::endl;
		//it++;
	//}




}
