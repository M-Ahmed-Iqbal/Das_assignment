#pragma once
#include <iostream>
using namespace std;
#include<queue>
template<class T>
class Node
{
public:
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T data);
};

template<class T>
class BinaryTree
{
private:
	
	Node<T>* root; 
	void Destruct(Node<T>* r);
public:
	BinaryTree(); 
	~BinaryTree();

	Node<T>* getRoot(); // returns the root node of tree if exists
	void Insert_in_level_order_iteration( T val);
	 void Insert_in_level_order_recursion(Node<T>*node,T val,bool inserted );
	void Print_level_order_iteration();
	void Print_level_order_recursion();
	void Print_given_level(Node<T>* node, int level);
	int findHeight(Node<T>* r);
};