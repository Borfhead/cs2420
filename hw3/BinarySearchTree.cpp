#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

template <class T>
class BinarySearchTree
{
private:
	struct Node
	{
		Node* m_pLeft;
		Node* m_pRight;
		T m_data;
	};
	Node* m_pRoot;
	unsigned int m_numNodes;

public:
	BinarySearchTree();
	~BinarySearchTree();
	void destroySubTree(Node*&);
	bool insert(T);
	bool insert(Node*&, Node*&);
	void display();
	void outputTree();
	void printInOrder(Node*&);
	void outputTreeInOrder(Node*&);
	void remove(T);
	void deleteNode(T, Node*&);
	void makeDeletion(Node*&);
	bool search(T);
	bool search(T, Node*&);
	unsigned int numberNodes();
	unsigned int numberLeafNodes();
	unsigned int numberLeafNodes(Node*&);
	unsigned int height();
	unsigned int height(Node*&);
	std::ofstream out;


};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_pRoot = nullptr;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroySubTree(m_pRoot);
}

template <class T>
bool BinarySearchTree<T>::insert(T value)
{
	Node* newNode = nullptr;

	newNode = new Node;
	newNode->m_data = value;
	newNode->m_pLeft = newNode->m_pRight = nullptr;

	return insert(newNode, m_pRoot);
}

template <class T>
bool BinarySearchTree<T>::insert(Node*& newNode, Node*& ptrRoot)
{
	if (ptrRoot == nullptr)
	{
		ptrRoot = newNode;
		m_numNodes++;
		return true;
	}
	else if (newNode->m_data < ptrRoot->m_data)
	{
		return insert(newNode, ptrRoot->m_pLeft);
	}
	else if (newNode->m_data > ptrRoot->m_data)
	{
		return insert(newNode, ptrRoot->m_pRight);
	}
	return false;

}


template <class T>
void BinarySearchTree<T>::destroySubTree(Node*& ptrRoot)
{
	if (ptrRoot)
	{
		if (ptrRoot->m_pLeft)
		{
			destroySubTree(ptrRoot->m_pLeft);
		}
		if (ptrRoot->m_pRight)
		{
			destroySubTree(ptrRoot->m_pRight);
		}
	}
}

template <class T>
void BinarySearchTree<T>::display()
{
	printInOrder(m_pRoot);
}

template <class T>
void BinarySearchTree<T>::printInOrder(Node*& ptrRoot)
{
	if (ptrRoot)
	{
		printInOrder(ptrRoot->m_pLeft);
		std::cout << ptrRoot->m_data << std::endl;
		printInOrder(ptrRoot->m_pRight);
	}
}

template <class T>
void BinarySearchTree<T>::outputTree()
{
	outputTreeInOrder(m_pRoot);
}

template <class T>
void BinarySearchTree<T>::outputTreeInOrder(Node*& ptrRoot)
{
	if (ptrRoot)
	{
		outputTreeInOrder(ptrRoot->m_pLeft);
		out << ptrRoot->m_data << std::endl;
		outputTreeInOrder(ptrRoot->m_pRight);
	}
	
}

template <class T>
void BinarySearchTree<T>::remove(T value)
{
	deleteNode(value, m_pRoot);
}

template <class T>
void BinarySearchTree<T>::deleteNode(T value, Node*& ptrRoot)
{
	if (search(value))
	{
		if (value < ptrRoot->m_data)
		{
			deleteNode(value, ptrRoot->m_pLeft);
		}
		else if (value > ptrRoot->m_data)
		{
			deleteNode(value, ptrRoot->m_pRight);
		}
		else
		{
			makeDeletion(ptrRoot);
		}
	}
}

template <class T>
void BinarySearchTree<T>::makeDeletion(Node*& ptrRoot)
{
	Node* temp = nullptr;
	if (ptrRoot == nullptr)
	{
		//Do nothing
	}

	else if (ptrRoot->m_pRight == nullptr)
	{
		temp = ptrRoot;
		ptrRoot = ptrRoot->m_pLeft;
		m_numNodes--;
		delete temp;
	}

	else if (ptrRoot->m_pLeft == nullptr)
	{
		temp = ptrRoot;
		ptrRoot = ptrRoot->m_pRight;
		m_numNodes--;
		delete temp;
	}
	else
	{
		temp = ptrRoot->m_pRight;
		while (temp->m_pLeft)
		{
			temp = temp->m_pLeft;
		}
		temp->m_pLeft = ptrRoot->m_pLeft;
		temp = ptrRoot;
		ptrRoot = ptrRoot->m_pRight;
		m_numNodes--;
		delete temp;
	}
}

template <class T>
bool BinarySearchTree<T>::search(T value)
{
	return search(value, m_pRoot);
}

template <class T>
bool BinarySearchTree<T>::search(T value, Node*& ptrRoot)
{
	if (ptrRoot)
	{
		if (value == ptrRoot->m_data)
		{
			return true;
		}
		else if (value < ptrRoot->m_data)
		{
			return search(value, ptrRoot->m_pLeft);
		}
		else if (value > ptrRoot->m_data)
		{
			return search(value, ptrRoot->m_pRight);
		}
	}
	return false;
}

template <class T>
unsigned int BinarySearchTree<T>::numberNodes()
{
	return m_numNodes;
}

template <class T>
unsigned int BinarySearchTree<T>::numberLeafNodes()
{
	return numberLeafNodes(m_pRoot);
}

template <class T>
unsigned int BinarySearchTree<T>::numberLeafNodes(Node*& ptrRoot)
{
	if (ptrRoot == nullptr)
	{
		return 0;
	}
	else if (ptrRoot->m_pLeft == nullptr && ptrRoot->m_pRight == nullptr)
	{
		return 1;
	}
	else
	{
		return (numberLeafNodes(ptrRoot->m_pLeft) + numberLeafNodes(ptrRoot->m_pRight));
	}
}

template <class T>
unsigned int BinarySearchTree<T>::height()
{
	return height(m_pRoot);
}

template <class T>
unsigned int BinarySearchTree<T>::height(Node*& ptrRoot)
{
	if (ptrRoot == nullptr)
	{
		return 0;
	}

	unsigned int leftHeight = height(ptrRoot->m_pLeft);
	unsigned int rightHeight = height(ptrRoot->m_pRight);

	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}