#include <iostream>
#include <cstdlib>

#include "BST.h"


BST::BST()
{
	root = NULL;
}
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}
void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			AddLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}

	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		std::cout << "The key " << key << " has already been added to the tree.\n";
	}
}
void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			PrintInOrderPrivate(Ptr->left);
		}
		std::cout << Ptr->key << " ";
		if (Ptr->right != NULL)
		{
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else
	{
		std::cout << "The tree is empty\n";
	}
}

BST::node* BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}
BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr->key == key)
		{
			return Ptr;
		}
		else
		{
			if (key < Ptr->key)
			{
				return ReturnNodePrivate(key, Ptr->left);
			}
			else
			{
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}
int BST::ReturnRootkey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}


void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(key);
	if (Ptr != NULL)
	{
		//Left
		std::cout << "Parent Node = " << Ptr->key << std::endl;
		Ptr->left == NULL ?
			std::cout << "Left Child = NULL" << std::endl	:
			std::cout << "Left Child = " << Ptr->left->key << std::endl;
		//Right
		Ptr->right == NULL ?
			std::cout << "Right Child = NULL\n" :
			std::cout << "Right Child = " << Ptr->right->key << std::endl;
	}
	else
	{
		std::cout << "Key " << key << " is not in the tree\n";
	}
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}
void BST::RemoveNodePrivate(int key, node* parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				std::cout << "The key " << key << " was not found in the tree\n";
			}
		}
	}

	else
	{
		std::cout << "The tree is empty.\n";
	}
}

void BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		node* delPtr = root;
		int rootkey = root->key;
		int smallestInrightSubtree;

		//case 0 - 0 children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		//case 1 - 1 child
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			std::cout << "The root node with key " << rootkey << " was deleted."
				<< "The new root contains key " << root->key << std::endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			std::cout << "The root node with key " << rootkey << " was deleted."
				<< "The new root contains key " << root->key << std::endl;
		}
		//case 2  -2 children

		else
		{
			smallestInrightSubtree = minPrivate(root->right);
			RemoveNodePrivate(smallestInrightSubtree, root);
			root->key = smallestInrightSubtree;
			std::cout << "The root key containing key " << rootkey << " was overwritten with key " << root->key << std::endl;

		}
	}
	else
	{
		std::cout << "Can not remove root. The tree is empty.\n";
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallestInrightSubtree;

		//case 0 - 0 children
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			std::cout << "the node contaning key " << matchKey << " was removed\n";
		}
		//case 1 - 1 child
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			std::cout << "the node contaning key " << matchKey << " was removed\n";
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			std::cout << "the node contaning key " << matchKey << " was removed\n";
		}

		//case 2 - 2 children
		else
		{
			smallestInrightSubtree = minPrivate(match->right);
			RemoveNodePrivate(smallestInrightSubtree, match);
			match->key = smallestInrightSubtree;
		}

	}
	else
	{
		std::cout << "Can not remove match. The tree is empty.\n";
	}
}

BST::~BST()
{
	RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr->left != NULL)
		{
			RemoveSubtree(Ptr->left);
		}
		if (Ptr->right != NULL)
		{
			RemoveSubtree(Ptr->right);
		}
		std::cout << "Deleting the node containg key " << Ptr->key << std::endl;
		delete Ptr;
	}
}