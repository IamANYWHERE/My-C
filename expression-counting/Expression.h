#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Node {    //节点用于表达式转换的stack中
	char oper;           //符号
	Node* next;          //下一节点
}Node;
typedef struct Leaf {    //节点用于stack和生成的表达式树
	string str;          //符号或数字
	Leaf* left;          //左节点
	Leaf* right;         //右节点
}Leaf;

class Stack {            //栈用于表达式转换和生成表达式树
private:
	Node* _first;        //表达式转换中的栈顶
	vector<Leaf*> _stack;//生成表达式树的栈
public:
	Stack() { _first = NULL; };
	~Stack();
	bool Push(const char& ch);  //压入栈
	bool Push(Leaf* leaf);      //压入栈
	bool Pop(char& ch);         //顶部出栈
	bool Pop(Leaf*& leaf);      //顶部出栈
	bool GetTop(char& ch);      //得到顶部的数据
	bool IsEmpty();             //栈是否空
};


class Expression                       //表达式类
{                                      //对表达式进行转换
public:                                //生成表达式树
	Expression();                      //输出前中后缀表达式
	~Expression();
	bool InfixToSuffix(string& exp);   //中缀表达式变后缀表达式
	bool CreateTree();                 //创建表达式树
	void ShowPrefix(Leaf* leaf);       //输出前缀表达式
	void ShowInfix(string& str);       //输出中缀表达式
	void ShowSuffix(Leaf* leaf);       //输出后缀表达式
	Leaf* GetTop() { return _first; }; //得到表达式树的头节点
private:
	string _expression;                //后缀表达式存储的地方
	Leaf* _first;                      //表达式树的头节点
	void RemoveBlank(string& str);     //移除表达式中的空格
};

