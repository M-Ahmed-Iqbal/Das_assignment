#include "AvlTree.h"

AVLNode::AVLNode(int data) {
    value = data;
    left = right = nullptr;
    height = 1;
}

AVL::AVL() {
    root = nullptr;
}

AVL::~AVL() {
    Destructor(root);
}

AVLNode* AVL::getRoot() {
    return root;
}

void AVL::setRoot(AVLNode* node)
{
    root = node;
}

int AVL::getNodeHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

void AVL::updateNodeHeight(AVLNode* node) {
    if (node != nullptr) {
        node->height = 1 + max(getNodeHeight(node->left), getNodeHeight(node->right));
    }
}

AVLNode* AVL::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* rightSubtree = x->right;

    x->right = y;
    y->left = rightSubtree;

    updateNodeHeight(y);
    updateNodeHeight(x);

    return x;
}

AVLNode* AVL::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* leftSubtree = y->left;

    y->left = x;
    x->right = leftSubtree;

    updateNodeHeight(x);
    updateNodeHeight(y);

    return y;
}

int AVL::getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

void AVL::Destructor(AVLNode* node) {
    if (node) {
        Destructor(node->left);
        Destructor(node->right);
        delete node;
    }
}

AVLNode* AVL::insert(AVLNode* node, int key) {
    if (node == nullptr) {
        return new AVLNode(key);
    }

    if (key < node->value) {
        node->left = insert(node->left, key);
    }
    else if (key > node->value) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    updateNodeHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (key < node->left->value) {
            return rotateRight(node);
        }
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balance < -1) {
        if (key > node->right->value) {
            return rotateLeft(node);
        }
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}


void AVL::inorderTraversal(AVLNode* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }
    
}

void AVL::print_in_level_order()
{
    queue<AVLNode*> Queue;
    AVLNode* temp;

    Queue.push(getRoot());
    while (!(Queue.empty())) {
        temp = Queue.front();
        Queue.pop();
        cout << temp->value << " ";

        if (temp->left) {
            Queue.push(temp->left);

        }

        if (temp->right) {
            Queue.push(temp->right);
            
        }
       
    }
    cout << endl;
}
