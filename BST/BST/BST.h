#ifndef _BST_H
#define _BST_H

class BST
{
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};
	node* root;
	node* CreateLeaf(int key);
	void AddLeafPrivate(int key, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNode(int key);
	node* ReturnNodePrivate(int key, node* Ptr);
	//Min & Max Functions
	int minPrivate(node* Ptr);
	int maxPrivate(node* Ptr);
	//===================
	void RemoveNodePrivate(int key, node* Parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	void RemoveSubtree(node* Ptr);


public:
	BST();
	~BST();
	void AddLeaf(int key);
	void PrintInOrder();
	int ReturnRootkey();
	void PrintChildren(int key);
	//Min & Max Functions
	int min();
	int max();
	//===================
	void RemoveNode(int key);
};

#endif