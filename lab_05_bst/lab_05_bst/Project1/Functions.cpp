/*
	Kim, Ji Soo

	CS A200
	April 17, 2019

	Lab 5
*/

#include "BST.h"


// Definition function insert (non-recursive) 
void BST::insert(int newItem)
{
	Node * newNode = new Node;
	newNode->data = newItem;

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		Node * current = root;
		
		bool inserted = false;

		while (!inserted)
		{
			if (current->data > newItem)
			{
				if (current->llink == nullptr)
				{
					current->llink = newNode;
					inserted = true;
				}
				else
					current = current->llink;
			}
			else
			{
				if (current->rlink == nullptr)
				{
					current->rlink = newNode;
					inserted = true;
				}
				else
					current = current->rlink;
			}
		}
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	if (root == nullptr)
		return 0;
	else
	{
		Node * p = root;
		return totalNodes(p);
	}
}
// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	if (p == nullptr)
		return 0;
	else
		return totalNodes(p->llink) + totalNodes(p->rlink) + 1;
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr) cerr << "There is no tree." << endl;
	else
		preorderTraversal(root);
}

// Definition overloaded function preorderTraversal (recursive)
void BST::postorderTraversal() const
{
	if (root == nullptr) cerr << "There is no tree." << endl;
	else
		postorderTraversal(root);
}

// Definition overloaded function postorderTraversal
void BST::preorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}