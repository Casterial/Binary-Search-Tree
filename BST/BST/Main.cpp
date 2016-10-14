#include <iostream>
#include <cstdlib>

#include "BST.h"

int input;
int main()
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 89 };
	BST myTree;

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}
	std::cout << "Printing the tree in order\n";
	myTree.PrintInOrder();
	std::cout << std::endl;

	//printing the first root.
	myTree.PrintChildren(myTree.ReturnRootkey());
	std::cout << std::endl;

	//Prints out the tree.
	for (int i = 0; i < 16; i++)
	{
		myTree.PrintChildren(TreeKeys[i]);
		std::cout << std::endl;
	}
	
	//deleting a Node.
	std::cout << "Enter a value to delete. Enter -1 to stop the process\n";
	while (input != -1)
	{
		std::cout << "Delete Node: ";
		std::cin >> input;
		{
			if (input != -1)
			{
				std::cout << std::endl;
				myTree.RemoveNode(input);
				myTree.PrintInOrder();
				std::cout << std::endl;
			}
		}
	}
	//Prints out the tree.
	for (int i = 0; i < 16; i++)
	{
		myTree.PrintChildren(TreeKeys[i]);
		std::cout << std::endl;
	}
	std::cout << "The smallest vlaue in the tree is " << myTree.min() << std::endl;
	std::cout << "The largest numbers in your tree is " << myTree.max() << std::endl;
	

	system("pause");
	return 0;
}