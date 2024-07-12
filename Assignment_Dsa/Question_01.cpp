//#include"BT.h"
//#include"BST.h"
//#include"Max_heap.h"
//#include"Min_Heap.h"
//int main() {
//	BinaryTree<int>b;
//	//testing part A
//	cout << "part A , B " << endl;
//	b.Insert_in_level_order_iteration(5);
//	b.Insert_in_level_order_iteration(10);
//	b.Insert_in_level_order_iteration(12);
//	b.Insert_in_level_order_recursion(b.getRoot(),15,false);
//	b.Insert_in_level_order_recursion(b.getRoot(), 17,false);
//	b.Insert_in_level_order_recursion(b.getRoot(), 20, false);
//
//
//	//testing part B
//	b.Print_level_order_iteration();
//	cout << endl;
//	b.Print_level_order_recursion();
//	cout << endl;
//	BST<int>b1;
//	b1.insert(5);
//	b1.insert(10);
//	b1.insert(15);
//	//testing part C
//	//searching a node with value 15 and printing its value
//	cout << "part C " << endl;
//
//	BSTNode<int>* a;
//		a = b1.Search_a_node_iteration(15);
//		if (a)
//			cout << a->data << endl;
//	else
//		cout << "value not found" << endl;
//	a = b1.Search_a_node_recursion(b1.getRoot(), 10);
//	if (a)
//		cout << a->data << endl;
//	else
//		cout << "value not found" << endl;
//	a = b1.Search_a_node_iteration(2);
//	if (a)
//		cout << a->data << endl;
//	else
//		cout << "value not found" << endl;
//	a = b1.Search_a_node_recursion(b1.getRoot(), 3);
//	if (a)
//		cout << a->data << endl;
//	else
//		cout << "value not found" << endl;
//	//part D testing
//	cout << "Part D " << endl;
//	b1.insert(1);
//	b1.insert(9);
//	b1.insert(8);
//	b1.inOrderDisplay(b1.getRoot());
//	cout << endl;
//	b1.Delete_a_node_iteration(b1.getRoot(), 10);
//	b1.inOrderDisplay(b1.getRoot());
//	cout << endl;
//	b1.Delete_a_node_recursion(b1.getRoot(), 1);
//	b1.inOrderDisplay(b1.getRoot());
//	cout << endl;
//	//testing part E
//	cout << "part E " << endl;
//	MinHeap m(10);
//	m.insert_iteration(100);
//	m.insert_iteration(10);
//	m.insert_iteration(50);
//	m.insert_recursion(60);
//	m.insert_recursion(5);
//	m.insert_recursion(7);
//	m.display();
//	//testing part F
//	cout << "part F " << endl;
//	MaxHeap M(10);
//	M.insert(5);
//	M.insert(10);
//	M.insert(15);
//	M.insert(2);
//	M.insert(116);
//	M.insert(19);
//	M.display();
//	//removing node with value 2 and displaying again
//	M.removeNode_iteration(2);
//	M.display();
//	cout << "checking for edge cases" << endl;
//	//checking for exception 12 is not in tree 
//	M.removeNode_iteration(12);
//	//removing node with value 5 and displaying again
//	M.removeNode_recursion(5);
//	M.display();
//	cout << "checking for edge cases" << endl;
//	//checking for exception 18 is not in tree 
//	M.removeNode_recursion(18);
//
//	
//
//	
//
//}