#include"BT.h"

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	left = right = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
	Destruct(root);

}
template<class T>
Node<T>* BinaryTree<T>::getRoot()
{
	if (root) 
	{
		return root;
	}
	return nullptr;
}
//question # 1 part (a)
template<class T>
void BinaryTree<T>::Insert_in_level_order_iteration(T val)
{
	if (root == nullptr) {
		root = new Node<T>(val);
		return;
	}
	queue<Node<T>*>q;
	q.push(root);
	while (!q.empty()) 
	{
		Node<T>* temp = q.front();
		q.pop();
		if (temp->left)
			q.push(temp->left);
		else {
			temp->left = new Node<T>(val);
			return;
		}
		if (temp->right)
			q.push(temp->right);
		else {
			temp->right = new Node<T>(val);
			return;
		}
	}
}

template<class T>
void BinaryTree<T>::Insert_in_level_order_recursion(Node<T>* node, T val,bool inserted)
{
	if (node == nullptr) {
		node = new Node<T>(val);
		inserted = true;
		return;
	}

	if (node->left == nullptr) {
		node->left = new Node<T>(val);
		inserted = true;
		return;
	}
	else if (node->right == nullptr) {
		node->right = new Node<T>(val);
		inserted = true;
		return;
	}
	else if(!inserted)
	{
		Insert_in_level_order_recursion(node->left, val,inserted);
	}
	else if (!inserted) {
		Insert_in_level_order_recursion(node->right, val,inserted);

	}
}
//question # 1 part(B)
template<class T>
void BinaryTree<T>::Print_level_order_iteration()
{
	if (root == nullptr)
		return;
	queue<Node<T>*>q;
	q.push(root);
	while (!q.empty())
	{
		Node<T>* Root = q.front();
		q.pop();
		cout << Root->data << " ";
		if (Root->left)
			q.push(Root->left);
		if (Root->right)
			q.push(Root->right);
	}

}

template<class T>
void BinaryTree<T>::Print_level_order_recursion()
{
	int h = this->findHeight(root);
	for (int i = 0; i < h; i++) {
		Print_given_level(root, i);
	}
}
template <typename T>
void BinaryTree<T>::Print_given_level(Node<T>* node, int level) {
	if (node == nullptr) {
		return;
	}

	if (level == 0) {
		cout << node->data << " ";
	}
	else if (level > 0) {
		Print_given_level(node->left, level - 1);
		Print_given_level(node->right, level - 1);
	}
}
template<class T>
int BinaryTree<T>::findHeight(Node<T>* r)
{
	if (r == nullptr)
		return 0;
	return 1 + max(findHeight(r->left), findHeight(r->right));
}

template<class T>
void BinaryTree<T>::Destruct(Node<T>* node) 
{
	if (node) {
		Destruct(node->left);	//go to all nodes and delete them one by one
		Destruct(node->right);
		delete node;
	}
}

