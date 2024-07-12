#include"Expression_Tree.h"

EXPNode::EXPNode(char key)
{
	value = key;
	left = right = nullptr;
}

EXPNode::EXPNode()
{
	value = '\0';
	left = right = nullptr;
}

void ExpressionTree::Destruct(EXPNode* node)
{
	if (node) {
		Destruct(node->left);	//go to all nodes and delete them one by one
		Destruct(node->right);
		delete node;
	}
}

ExpressionTree::ExpressionTree()
{
	root = nullptr;
}

ExpressionTree::~ExpressionTree()
{
	Destruct(root);
}

int ExpressionTree::prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*' )
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

bool ExpressionTree::isOperand(char c)
{
	if (c >= '0' && c <= '9') {
		return true;
	}
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	}
	return false;

}

bool ExpressionTree::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
		return true;
	}
	return false;
}

string ExpressionTree::infixToPostfix(string infix)
{
	string b;
	stack <char>s;

	for (int i = 0; infix[i] != '\0'; i++) {

		if (isOperand(infix[i])) {
			
			b += infix[i];
		}

		else if (infix[i] == '(') {
			s.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (s.top() != '(') {
				b += s.top();
				s.pop();
			}
			s.pop();
		}
		else if (isOperator(infix[i]))
		{
			while (!s.empty() && prec(infix[i]) <= prec(s.top())) {
				b += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}

	}

	while (!s.empty()) {
		b += s.top();
		s.pop();
	}

	return b;
}

void ExpressionTree::ExpTree_from_postfix(string postfix)
{
	stack<EXPNode*>s;
	for (int i = 0; postfix[i] != '\0'; i++) 
	{
		if (isOperand(postfix[i])) 
		{
			s.push(new EXPNode(postfix[i]));
		}
		else 
		{
			EXPNode* rightO = s.top();
			s.pop();
			EXPNode* leftO = s.top();
			s.pop();
			EXPNode* node = new EXPNode(postfix[i]);
			node->left = leftO;
			node->right = rightO;
			s.push(node);
		}
	}
	root = new EXPNode();
	root = s.top();
}

void ExpressionTree::inorderDisplay(EXPNode* node)
{
	if (node) {
		inorderDisplay(node->left);
		cout << node->value << " ";
		inorderDisplay(node->right);
	}
}

EXPNode* ExpressionTree::getRoot()
{
	if (root) {
		return root;
	}
	return nullptr;
}
