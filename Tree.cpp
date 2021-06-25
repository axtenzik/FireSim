#include "Tree.h"
#include <iostream>

Tree::Tree(int x, int y)
{
	xcoord = x;
	ycoord = y;
	status = 1;
	hydration = 1; //when constructed the tree has a hydration of 1
}

int Tree::getX()
{
	return xcoord;
}

int Tree::getY()
{
	return ycoord;
}

int Tree::getHydration()
{
	return hydration;
}

void Tree::setHydration(int hydro)
{
	hydration = hydro;
}

int Tree::getStatus()
{
	return status;
}

void Tree::setStatus(int newStatus)
{
	status = newStatus;
}

TreeNode::TreeNode(int x, int y)
{
	tree = new Tree(x, y);
	next = NULL;
}

Tree* TreeNode::getTree()
{
	return tree;
}

TreeNode* TreeNode::getNext()
{
	return next;
}

void TreeNode::setNext(TreeNode* nextNode)
{
	next = nextNode;
}

TreeList::TreeList()
{
	start = NULL;
	end = NULL;
}

bool TreeList::isEmpty()
{
	return start == NULL;
}

void TreeList::addTree(int x, int y)
{
	TreeNode* current;
	current = new TreeNode(x, y);
	if (end == NULL) //if theres no trees the current tree will be set for the start and the end
	{
		start = current;
		end = current;
	}
	else
	{
		end->setNext(current); //sets nodes currently held in end next node to be current
		end = current; //sets current to node at end of list
	}
}

void TreeList::listAll()
{
	TreeNode* current;
	if (!isEmpty()) // if not empty
	{
		std::cout << "start of list: " << std::endl;
		current = start;
		while (current != NULL) //will loop while current is an object
		{
			std::cout << "Tree is " << current->getTree()->getX() << ", " << current->getTree()->getY() << std::endl;
			current = current->getNext();
		}
		std::cout << "End of list" << std::endl;
	}
	else
	{
		std::cout << "list empty" << std::endl;
	}
}

TreeNode* TreeList::getStart()
{
	return start;
}