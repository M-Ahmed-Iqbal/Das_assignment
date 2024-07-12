#include"BST.h"

template<class T>
BST<T>::BST()
{
	root = nullptr;
}
template<class T>
BSTNode<T>::BSTNode(T val)
{
	this->data = val;
	left = right = nullptr;
}
template<class T>
BST<T>::~BST()
{
	Destructor(root);	//recursively destruct
}
template<class T>
void BST<T>::Destructor(BSTNode<T>* node)
{
	if (node) {
		Destructor(node->left);	//go to all nodes and delete them one by one
		Destructor(node->right);
		delete node;
	}
}
//insert some nodes to test delete and search function
template<class T>
void BST<T>::insert(T val)
{
	if (!root)	
		root = new BSTNode<T>(val);
	else
	{
		
		BSTNode<T>* temp = root;
		BSTNode<T>* prev = temp;
		while (temp)
		{
			if (temp->data > val)
			{
				prev = temp;
				temp = temp->left;
			}
			else
			{
				prev = temp;
				temp = temp->right;
			}
		}
		if (prev->data > val)
			prev->left = new BSTNode<T>(val);
		else
			prev->right = new BSTNode<T>(val);
	}
}
template<class T>
BSTNode<T>* BST<T>::getRoot()
{
	if (root)
		return root;
	return nullptr;
}
//Question #1 part C
template<class T>
BSTNode<T>* BST<T>::Search_a_node_iteration(T val)
{
	BSTNode<T>* temp = root;
	while (temp)
	{
		if (temp->data == val)
			return temp;
		else
		{
			if (temp->data > val)    
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return nullptr;
}
template <typename T>
BSTNode<T>* BST<T>::Search_a_node_recursion( BSTNode<T>* node, T val)
{
	if (node == nullptr || node->data == val)
		return node;

	if (node->data > val)
		return Search_a_node_recursion( node->left,val);
	else
		return Search_a_node_recursion(node->right, val);
}

template<class T>
void BST<T>::Print_level_order_iteration()
{
	if (root == nullptr)
		return;
	queue<BSTNode<T>*>q;
	q.push(root);
	while (!q.empty())
	{
		BSTNode<T>* Root = q.front();
		q.pop();
		cout << Root->data << " ";
		if (Root->left)
			q.push(Root->left);
		if (Root->right)
			q.push(Root->right);
	}
}
template <class T>
BSTNode<T>* BST<T>::inorderSucessor(BSTNode<T>* node) {
	BSTNode<T>* temp = node;
	while (temp && temp->left) {
		temp = temp->left;
	}
	return temp;
}

template<class T>
BSTNode<T>* BST<T>::Delete_a_node_recursion(BSTNode<T>* node, T val){
	if (node == nullptr) {
		return node;
	}
	else
		if (val < node->data) {
		node->left = Delete_a_node_recursion(node->left, val);
	}
	else if (val > node->data) {
		node->right = Delete_a_node_recursion(node->right, val);
	}
	else {
		if (node->left == nullptr) 
		{
			BSTNode<T>* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			BSTNode<T>* temp = node->left;
			delete node;
			return temp;
		}
		//if both children are present
		BSTNode<T>* temp = inorderSucessor(node->right);
		node->data = temp->data;
		node->right = Delete_a_node_recursion(node->right, temp->data);

	}
	return node;
}
template <typename T>
BSTNode<T>* BST<T>::Delete_a_node_iteration(BSTNode<T>* node, T val) {
	BSTNode<T>* current = node;
	BSTNode<T>* parent = nullptr;

	// Find the node to be deleted
	while (current != nullptr && current->data != val) {
		parent = current;
		if (val < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// If the node is not found
	if (current == nullptr) {
		return node;
	}

	// Node with only one child or no child
	if (current->left == nullptr) {
		BSTNode<T>* temp = current->right;
		if (parent == nullptr) {
			node = temp;//if parent is nullptr then its means root is deleted
		}
		else if (current == parent->left) {
			parent->left = temp;
		}
		else {
			parent->right = temp;
		}
		delete current;
	}
	else if (current->right == nullptr) {
		BSTNode<T>* temp = current->left;
		if (parent == nullptr) {
			node = temp;
		}
		else if (current == parent->left) {
			parent->left = temp;
		}
		else {
			parent->right = temp;
		}
		delete current;
	}
	else {
		// Node with two children
		BSTNode<T>* successor = inorderSucessor(current->right);
		current->data = successor->data;
		current->right = Delete_a_node_iteration(current->right, successor->data);
	}

	return node;
}

template<class T>
void BST<T>::inOrderDisplay(BSTNode<T>* node)
{
	if (node == nullptr)
		return;
	inOrderDisplay(node->left);
	cout << node->data << " ";
	inOrderDisplay(node->right);
}

template<class T>
void BST<T>::kthLargestElement(BSTNode<T>* node, int k, int& c)
{
	if (node == NULL || c >= k)
		return;

	// reverse in order traversal
	kthLargestElement(node->right, k, c);
	c++;
	if (c == k)
	{
		cout << k<<"th largest element is "
			<< node->data << endl;
		return;
	}
	kthLargestElement(node->left, k, c);
}

