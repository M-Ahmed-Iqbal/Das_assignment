#pragma once
#include<iostream>
#include<stack>
using namespace std;
class EXPNode 
{public:
	char value;
	EXPNode* left;
	EXPNode* right;
	EXPNode(char key);
	EXPNode();

};
class ExpressionTree 
{
private:
	EXPNode* root;
	void Destruct(EXPNode* node);
public:
	ExpressionTree();
	~ExpressionTree();
	int prec(char c);
	bool isOperand(char c);
	bool isOperator(char c);
	string infixToPostfix(string infix);
	void ExpTree_from_postfix(string postfix);
	void inorderDisplay(EXPNode* node);
	EXPNode* getRoot();
};