////question 2 part a
////check wether given array is min heap or not
//#include<iostream>
//#include"AvlTree.h"
//#include"Expression_Tree.h"
//#include"BST.h"
//using namespace std;
//bool isMinHeap(int arr[], int size, int index=0)
//{
//
//    if (index >= size) {
//        return true;
//    }
//    int left = index * 2 + 1;
//    int right = index * 2 + 2;
//    if ((left<size && arr[index]>arr[left]) || (right<size && arr[index]>arr[right]))
//        return false;
//    return isMinHeap(arr, size, left) && isMinHeap(arr, size, right);
//}
//int main() 
//{
//    cout << "Part a" << endl;
//    //part a testing
//    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
//  
//
//    if (isMinHeap(arr, 7)) {
//        cout << "The array represents a min-heap." << endl;
//    }
//    else {
//        cout << "The array does not represent a min-heap." << endl;
//    }
//    //part b testing
//    cout << "Part b" << endl;
//
//    AVL a;
//    a.setRoot(a.insert(a.getRoot(), 40));
//    a.setRoot(a.insert(a.getRoot(), 20));
//    a.setRoot(a.insert(a.getRoot(), 10));
//    a.setRoot(a.insert(a.getRoot(), 25));
//    a.setRoot(a.insert(a.getRoot(), 30));
//    a.setRoot(a.insert(a.getRoot(), 22));
//    a.setRoot(a.insert(a.getRoot(), 50));
//
//    a.inorderTraversal(a.getRoot());
//    cout << endl;
//    a.print_in_level_order();   //we can see from level order traversal and value of root is 25 so tree is 
//                                //perfectly balanced  
//    AVLNode* b = a.getRoot();
//    cout << b->value << endl;
//    
//    //part c testing
//    cout << "Part c" << endl;
//
//    ExpressionTree e;
//    string infix = "2+5*8+a/9-4+b";
//    string postfix= e.infixToPostfix(infix);
//    cout << postfix << endl;
//    e.ExpTree_from_postfix(postfix);
//    e.inorderDisplay(e.getRoot());
//   //part e testing
//    cout << "Part e" << endl;
//    BST<int>b1;
//    	b1.insert(5);
//    	b1.insert(10);
//    	b1.insert(15);
//        b1.insert(50);
//        b1.insert(30);
//        b1.insert(35);
//        int c = 0;
//        b1.kthLargestElement(b1.getRoot(), 4, c);
//    
//}