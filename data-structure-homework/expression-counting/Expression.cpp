#include "Expression.h"



Expression::Expression()
{
	_first = NULL;
}


Expression::~Expression()
{
}

int isp(const char& ch) {
	//��ջ�з��ŵ����ȼ�
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
	//��ջ����ŵ����ȼ�
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
	//���ַ�ѹ��ջ
	if (_first == NULL)
	{
		//ջΪ��ʱ��Ϊջ��ͷ�����ڵ�
		_first = new Node;
		if (_first == NULL)
			return false;
		_first->oper = ch;
		_first->next = NULL;
	}
	else
	{
		//ջ��Ϊ��ʱ�����µķ���ѹ��ջ
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
	//���ʽ���е�ѹ��ջ
	if (leaf == NULL)
		return false;
	_stack.push_back(leaf);
	return true;
}
bool Stack::Pop(char& ch) {
	//��ջ
	if (_first == NULL)
		return false;
	Node* node = _first;
	_first = _first->next;
	ch = node->oper;
	delete node;
	return true;
}
bool Stack::Pop(Leaf*& leaf) {
	//���ʽ���еĳ�ջ
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
	//���ʽת���еõ�ջ��
	if (_first == NULL)
		return false;
	ch = _first->oper;
	return true;
}
bool Stack::IsEmpty() {
	//ջ�Ƿ�Ϊ��
	if (_first == NULL)
		return true;
	else
		return false;
}
bool Expression::InfixToSuffix(string& exp) {
	//ǰ׺���ʽת��Ϊ��׺���ʽ
	RemoveBlank(exp);               //�Ƴ��ո�
	Stack stack;                    //����ջ
	stack.Push('#');                //������־ѹ��ջ
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
	//�������ʽ��
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
	//���ǰ׺���ʽ
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
	//�����׺���ʽ
	RemoveBlank(str);
	cout << str;
}
void Expression::ShowSuffix(Leaf* leaf) {
	//�����׺���ʽ
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
	//�Ƴ��ո�
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