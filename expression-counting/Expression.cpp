#include "Expression.h"



Expression::Expression()
{
	_first = NULL;
}


Expression::~Expression()
{
}

int isp(const char& ch) {
	//在栈中符号的优先级
	switch (ch)
	{
	case '#':return 0;
	case '(':return 1;
	case '*':case '/':case '%':return 5;
	case '+':case '-': return 3;
	case ')': return 6;
	default:
		return -1;
		break;
	}
}
int icp(const char& ch) 
{
	//在栈外符号的优先级
	switch (ch)
	{
	case '#':return 0;
	case '(':return 6;
	case '*':case '/':case '%':return 4;
	case '+':case '-': return 2;
	case ')': return 1;
	default:
		return -1;
		break;
	}
}

bool Stack::Push(const char& ch) {
	//将字符压入栈
	if (_first == NULL)
	{
		//栈为空时，为栈的头创建节点
		_first = new Node;
		if (_first == NULL)
			return false;
		_first->oper = ch;
		_first->next = NULL;
	}
	else
	{
		//栈不为空时，把新的符号压入栈
		Node* node=new Node;
		if (node == NULL)
			return false;
		node->oper = ch;
		node->next = _first;
		_first = node;
	}
	return true;
}
bool Stack::Push(Leaf* leaf) {
	//表达式树中的压入栈
	if (leaf == NULL)
		return false;
	_stack.push_back(leaf);
	return true;
}
bool Stack::Pop(char& ch) {
	//出栈
	if (_first == NULL)
		return false;
	Node* node = _first;
	_first = _first->next;
	ch = node->oper;
	delete node;
	return true;
}
bool Stack::Pop(Leaf*& leaf) {
	//表达式树中的出栈
	if (_stack.size() == 0)
		return false;
	leaf = _stack[_stack.size() - 1];
	_stack.pop_back();
	return true;
}
Stack::~Stack() {
	if (_first != NULL)
	{
		Node* node;
		while (true)
		{
			node = _first;
			_first = _first->next;
			delete node;
			if (_first == NULL)
				break;
		}
	}
}
bool Stack::GetTop(char& ch) {
	//表达式转换中得到栈顶
	if (_first == NULL)
		return false;
	ch = _first->oper;
	return true;
}
bool Stack::IsEmpty() {
	//栈是否为空
	if (_first == NULL)
		return true;
	else
		return false;
}
bool Expression::InfixToSuffix(string& exp) {
	//前缀表达式转换为后缀表达式
	RemoveBlank(exp);               //移除空格
	Stack stack;                    //创建栈
	stack.Push('#');                //结束标志压入栈
	exp.push_back('#');
	char ch;
	for (int i = 0; i < exp.size();)
	{
		if (isdigit(exp[i]))
		{
			
			if (((i - 1) < 0 || !isdigit(exp[i - 1])) &&((i + 1)<=(exp.size() - 1)&& isdigit(exp[i + 1])))
			{
				_expression.push_back('(');
				_expression.push_back(exp[i]);
			}
			else if (((i - 1) < 0 || !isdigit(exp[i - 1])) && ((i + 1)>(exp.size() - 1) || !isdigit(exp[i + 1])))
				_expression.push_back(exp[i]);
			else if (((i-1)>=0&& isdigit(exp[i - 1])) &&((i + 1) <= (exp.size() - 1) && isdigit(exp[i + 1])))
				_expression.push_back(exp[i]);
			else if (((i - 1) >= 0 && isdigit(exp[i - 1])) &&((i+1)>(exp.size()-1)|| !isdigit(exp[i + 1])))
			{
				_expression.push_back(exp[i]);
				_expression.push_back(')');
			}
			i++;
		}
		else
		{
			if (stack.GetTop(ch))
			{
				if (ch == '#')
				{
					if (i==exp.size()-1&&exp[i] != '#')
						return false;
				}
				if (exp[i] == '-')
				{
					if (i == 0||(!isdigit(exp[i-1])&&exp[i-1]!=')'))
					{
						_expression.push_back('(');
						_expression.push_back('-');
						i++;
						while (isdigit(exp[i]))
						{
							_expression.push_back(exp[i]);
							i++;
							if (i > exp.size() - 1)
								break;
						}
						_expression.push_back(')');
						continue;
					}
				}
				if (isp(ch) < icp(exp[i]))
				{
					stack.Push(exp[i]);
					i++;
				}
				else if (isp(ch) > icp(exp[i]))
				{
					stack.Pop(ch);
					_expression.push_back(ch);
				}
				else
				{
					if (ch == '(')
					{
						stack.Pop(ch);
						i++;
					}
					else
					{
						stack.Pop(ch);
						i++;
					}
				}
			}
			else
				return false;
		}
	}
	return true;
}

bool Expression::CreateTree() {
	//创建表达式树
	Stack stack; 
	string str;
	Leaf* leaf = NULL, *sonleaf = NULL;
	for (int i = 0; i < _expression.size(); i++)
	{
		if (isdigit(_expression[i]))
		{
			str.push_back(_expression[i]);
			leaf = new Leaf;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->str = str;
			stack.Push(leaf);
			str.clear();
		}
		else if (_expression[i]=='(')
		{
			while (_expression[i] != ')')
			{
				str.push_back(_expression[i]);
				i++;
			}
			str.push_back(')');
			leaf = new Leaf;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->str = str;
			stack.Push(leaf);
			str.clear();
		}
		else
		{
			str.push_back(_expression[i]);
			leaf = new Leaf;
			stack.Pop(sonleaf);
			if (sonleaf == NULL)
				return false;
			leaf->right = sonleaf;
			stack.Pop(sonleaf);
			if (sonleaf == NULL)
				return false;
			leaf->left = sonleaf;
			leaf->str = str;
			stack.Push(leaf);
			str.clear();
		}
	}
	stack.Pop(leaf);
	_first = leaf;
	return true;
}

void Expression::ShowPrefix(Leaf* leaf) {
	//输出前缀表达式
	if (leaf == NULL)
		return;
	else
	{
		cout << leaf->str;
		ShowPrefix(leaf->left);
		ShowPrefix(leaf->right);
	}
}
void Expression::ShowInfix(string& str) {
	//输出后缀表达式
	RemoveBlank(str);
	cout << str;
}
void Expression::ShowSuffix(Leaf* leaf) {
	//输出后缀表达式
	if (leaf == NULL)
		return;
	else
	{
		ShowSuffix(leaf->left);
		ShowSuffix(leaf->right);
		cout << leaf->str;
	}
}

void Expression::RemoveBlank(string& str) {
	//移除空格
	string string;
	for (int i = 0;i<str.size(); i++)
	{
		if (str[i] != ' ')
		{
			string.push_back(str[i]);
		}
	}
	str = string;
}