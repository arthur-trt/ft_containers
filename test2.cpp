#include "includes/rb_tree.hpp"
#include "includes/rb_tree_iterator.hpp"
#include "includes/pair.hpp"
#include <iostream>
#include <string>
#include <map>
#include "includes/vector.hpp"
#include "includes/map.hpp"
#include <cstdlib>
#include <memory>
#include <algorithm>    // For std::shuffle
//#include <random>


int main(void)
{
	srand((unsigned) time(0));
	ft::vector<int>								vec;
	ft::vector<int>::iterator					it;
	// ft::RedBlackTree<const int, ft::pair<const int, int> >							test;
	ft::map<int, int>							mine;
	std::map<int, int>							our;

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
		mine.insert(ft::make_pair(*it, *it));
		our.insert(std::make_pair(*it, *it));
		it++;
	}

	// ft::map<int, int>		super;

	// mine.printTree();
	ft::map<int, int>::reverse_iterator				it2 = mine.rbegin();
	std::map<int, int>::reverse_iterator			it3 = our.rbegin();
	while (it3 != our.rend())
	{
		std::cout << *it2 << "\t\t";
		std::cout << it3->first << ": \"" << it3->second << "\"" << std::endl;
		it2++;
		it3++;
	}

	// std::cout << *(test.lower_bound(384)) << std::endl;

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
