#include <iostream>
#include <cstdlib>

#include "BST.h"


//Min() Function
int BST::min()
{
	return minPrivate(root);
}
int BST::minPrivate(node* Ptr)
{
	if (root == NULL)
	{
		std::cout << "The tree is empty\n";
		return -1000;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return minPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

//max() Function
int BST::max()
{
	return maxPrivate(root);
}
int BST::maxPrivate(node* Ptr)
{
	if (root == NULL)
	{
		std::cout << "The tree is empty\n";
		return -1000;
	}
	else
	{
		if (Ptr->right != NULL)
		{
			return maxPrivate(Ptr->right);
		}
		else
		{
			return Ptr->key;
		}
	}
}
