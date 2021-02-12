#include<iostream>
#include<stdio.h>

class Node {
private:
	std::string val;
	Node * left,*right;
public:
	Node(std::string data,Node* lft,Node* rte)
	{
		val = data;
		left = lft;
		right = rte;
	}
	std::string getVal ();
	Node* getLeft ();
	Node* getRight ();
	void setLeft (Node * ptr);
	void setRight (Node * ptr);
	void setVal(std::string val);
	
	
	
	
};

	std::string Node::getVal()
	{
		return val;
	}
	void Node::setVal(std::string v)
	{
		val = v;
	}
	Node* Node::getLeft()
	{
		return left;
	}
	Node* Node::getRight()
	{
		return right;
	}
	void Node::setLeft(Node * ptr)
	{
		left = ptr;
	}
	void Node::setRight(Node * ptr)
	{
		right = ptr;
	}




class bst {

private:
Node * root = NULL;

public:
void addNode(std::string val);
void preorder(Node * ptr);
void inorder(Node * ptr);
void postorder(Node *ptr);
Node* predecessor(Node * ptr);
Node* successor(Node *ptr);
void delNode (std::string val);
Node * parent(Node* ptr);
void traversal()
{
std::cout<<"Tree Traversal:\n1)Pre-order\n2)In-Order\n3)Post-Order\n";
int ch;
std::cin>>ch;
switch(ch)
{
case 1:
	std::cout<<"The preorder traversal of the given tree is:\n";
	preorder(root);
	break;

case 2:
	std::cout<<"The inorder traversal of the given tree is:\n";
	inorder(root);
	break;
case 3:
	std::cout<<"The post order traversal of the given tree is:\n";
	postorder(root);
	break;
}

}
};
void bst::addNode(std::string val)
{
	if(root == NULL)
	{
		root = new Node(val,NULL,NULL);
	}
	else
	{
		Node *x = root;
		while(x != NULL)
		{
			if(x->getVal() < val)
			{
				if (x->getRight() == NULL)
				{
					x->setRight(new Node(val,NULL,NULL));
					break;
				}
				else
					x = x->getRight();
			}
			if(x->getVal() > val)
			{
				if (x->getLeft() == NULL)
				{
					x->setLeft(new Node(val,NULL,NULL));
					break;
				}
				else
					x = x->getLeft();
			}
		}
	}
}

void bst::preorder(Node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		std::cout<<ptr->getVal()<<"\n";
		preorder(ptr->getLeft());
		preorder(ptr->getRight());
	}
}
void bst::inorder(Node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		inorder(ptr->getLeft());
		std::cout<<ptr->getVal()<<"\n";
		inorder(ptr->getRight());
	}
}
void bst::postorder(Node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		postorder(ptr->getLeft());
		postorder(ptr->getRight());
		std::cout<<ptr->getVal()<<"\n";
	}
}


Node* bst::predecessor(Node *ptr)
{
	ptr = ptr->getLeft();
	while(ptr->getRight()!= NULL)
		ptr = ptr->getRight();
	return ptr;

}
Node* bst::successor(Node *ptr)
{
	ptr = ptr->getRight();
	while(ptr->getLeft()!= NULL)
		ptr = ptr->getLeft();
	return ptr;

}

Node* bst::parent(Node* n)
{
 	Node * ptr = root;
	while(ptr != NULL)
	{
		if(ptr->getVal() == n->getVal())
			return NULL;
		if(ptr->getLeft()->getVal() == n->getVal())
			return ptr;
		else if(ptr->getRight()->getVal() == n->getVal())
			return ptr;
		if(ptr->getVal() < n->getVal())
			ptr = ptr->getRight();
		else
			ptr = ptr->getLeft();
	}
}
void bst::delNode(std::string val)
{
	int found = 0;
	Node *ptr = root;
	if(root == NULL)
	{
		std::cout<<"Empty Tree!!...\n";
		return;
	}
	while(ptr != NULL)
	{
		if(ptr->getVal() == val)
		{
			found = 1;
			std::cout<<"Value Matched!!\n";
			if(ptr->getRight() == ptr->getLeft())  //Leaf Node.
			{
				std::cout<<"Leaf Node\n";
				std::cout<<"Both NULL\n";
				if(root == ptr)
					root = NULL;
				else if(parent(ptr)->getRight() != NULL && parent(ptr)->getRight()->getVal() == ptr->getVal())
					parent(ptr)->setRight(NULL);
				else
					parent(ptr)->setLeft(NULL);
			}
			else if(ptr->getRight() == NULL || ptr->getLeft() == NULL)  //Node with exactly one child.
			{
				if(ptr->getRight() == NULL) //Node with Left Child only.
				{
					std::cout<<"Node with Left Child only\n";
					std::cout<<"Left Child Only\n";
					if(parent(ptr) == NULL)
						root = root->getLeft();
					else if(parent(ptr)->getRight()->getVal() == val)
						parent(ptr)->setRight(ptr->getLeft());
					else
						parent(ptr)->setLeft(ptr->getLeft());					
				}
				else //Node with Right Child only.
				{
					std::cout<<"Right Child Only\n";
					if(parent(ptr) == NULL)
						root = root->getRight();
					else if(parent(ptr)->getRight()->getVal() == val)
						parent(ptr)->setRight(ptr->getLeft());
					else
						parent(ptr)->setLeft(ptr->getLeft());					
				}		
		
			}
			else //Node with two children.
			{
				std::cout<<"Node with two children";
				Node *temp = predecessor(ptr);
				std::cout<<"val="<<temp->getVal()<<"\n";
				
				if(temp->getRight() == temp->getLeft()) //The predecessor is a leaf node.
				{
				 	if(parent(temp)->getLeft() != NULL && parent(temp)->getLeft()->getVal() == temp->getVal())
					{
						parent(temp)->setLeft(NULL);
						
					}
					else
					{
						parent(temp)->setRight(NULL);
					}
					
					ptr->setVal(temp->getVal());
				}
				else  //The predecessor has one child.
				{
					std::cout<<"The predecessor has one child.";
					if(parent(temp)->getLeft()!= NULL && parent(temp)->getLeft()->getVal() == temp->getVal())
					{
						if(temp->getLeft() != NULL)
							parent(temp)->setLeft(temp->getLeft());
						else
							parent(temp)->setLeft(temp->getRight());
					}
					else
					{
						if(temp->getLeft() != NULL)
							parent(temp)->setRight(temp->getLeft());
						else
							parent(temp)->setRight(temp->getRight());
					}
					ptr->setVal(temp->getVal());
				}
			}
		}
		if(ptr->getVal() < val)
			ptr = ptr->getRight();
		else
			ptr = ptr->getLeft();
	}
	if(found == 0)
		std::cout<<"Value not found!!!...\n";
	else
		std::cout<<"Deleted successfully!!!!!!...\n";
}	
int main()
{
	bst tree = bst();
	std::string s;
	int n;
	std::cout<<"Enter the number of nodes:";
	std::cin>>n;
	for(int i = 0;i < n;i++)
	{
		std::cout<<"Enter the data:";
		std::string ch;
		std::cin>>ch;
		tree.addNode(ch);
	}
	n = 1;
	while(n == 1)
	{
	int ch;
	std::cout<<"1)Delete Node\n2)Traverse\n3)Exit\nEnter your choice:";
	std::cin>>ch;
	switch(ch)
	{
		case 1:
			std::cout<<"Enter the node to delete:";
			std::cin>>s;
			tree.delNode(s);
		
			break;
		case 2:
			tree.traversal();
			break;
		case 3:
			n = 0;
			break;
		}
	}
	return 0;
}
