#pragma once
#include<iostream>
using namespace std;
#include<queue>

template<class T>
class BSTNode
{
public:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode(T val);
};
template<class T>
class BST
{
private:
	BSTNode<T>* root;
	void Destructor(BSTNode<T>* node);
public:
	BST();
	~BST();
	//we need to insert some nodes before searching or deleting them
	void insert(T val);
	BSTNode<T>* getRoot();
	BSTNode<T>* Search_a_node_iteration(T val);
	BSTNode<T>* Search_a_node_recursion(BSTNode<T>* node,T val);
	void Print_level_order_iteration();
	BSTNode<T>* inorderSucessor(BSTNode<T>* node);
	BSTNode<T>* Delete_a_node_recursion(BSTNode<T>* node, T val);
	BSTNode<T>* Delete_a_node_iteration(BSTNode<T>* node, T val);
	void inOrderDisplay(BSTNode<T>* node);
	void kthLargestElement(BSTNode<T>* node, int k, int& c);
};


