#pragma once 
#include<iostream>
#include<queue>
using namespace std;

class AVLNode {
public:

    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int key);
};

class AVL {
private:
    AVLNode* root;
    int getNodeHeight(AVLNode* node);
    void updateNodeHeight(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    int getBalanceFactor(AVLNode* node);
    void Destructor(AVLNode* node);

public:
    AVL();
    ~AVL();
    AVLNode* getRoot();
    void setRoot(AVLNode* node);
    AVLNode* insert(AVLNode*node, int key);
    void inorderTraversal(AVLNode* node);
    void print_in_level_order();
};

