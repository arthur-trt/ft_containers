#include "includes/RBTree/rb_tree.hpp"
#include <iostream>

int main(void)
{
	ft::RedBlackTree<int>	test;

	test.insert(1);
	test.insert(2);
	test.insert(3);
	test.insert(4);

	test.printTree();

	test.deleteNode(1);

	test.printTree();

	std::cout << "test";
}
