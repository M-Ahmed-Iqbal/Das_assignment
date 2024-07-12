//#include"BST.h"
//
//BSTNode<int>* mergeBSTs(BSTNode<int>* root1, BSTNode<int>* root2) {
//    BSTNode<int>* temp = new BSTNode<int>(0);
//    BSTNode<int>* current =temp;
//
//    while (root2) {
//        if (!root1) {
//            current->right = root2;
//            break;
//        }
//
//        if (root1->data < root2->data) {
//            current->right = root1;
//            root1 = root1->right;
//        }
//        else {
//            current->right = root2;
//            root2 = root2->right;
//        }
//
//        current = current->right;
//    }
//
//    return temp->right;
//}
//int main() 
//{
//    BST<int>b1;
//    	b1.insert(5);
//    	b1.insert(10);
//    	b1.insert(15);
//
//    BST<int>b2;
//        b2.insert(50);
//        b2.insert(30);
//        b2.insert(40);
//        BSTNode<int>* merged = mergeBSTs(b1.getRoot(), b2.getRoot());
//        b1.inOrderDisplay(merged);
//
//}