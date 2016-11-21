#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Node {    //�ڵ����ڱ��ʽת����stack��
	char oper;           //����
	Node* next;          //��һ�ڵ�
}Node;
typedef struct Leaf {    //�ڵ�����stack�����ɵı��ʽ��
	string str;          //���Ż�����
	Leaf* left;          //��ڵ�
	Leaf* right;         //�ҽڵ�
}Leaf;

class Stack {            //ջ���ڱ��ʽת�������ɱ��ʽ��
private:
	Node* _first;        //���ʽת���е�ջ��
	vector<Leaf*> _stack;//���ɱ��ʽ����ջ
public:
	Stack() { _first = NULL; };
	~Stack();
	bool Push(const char& ch);  //ѹ��ջ
	bool Push(Leaf* leaf);      //ѹ��ջ
	bool Pop(char& ch);         //������ջ
	bool Pop(Leaf*& leaf);      //������ջ
	bool GetTop(char& ch);      //�õ�����������
	bool IsEmpty();             //ջ�Ƿ��
};


class Expression                       //���ʽ��
{                                      //�Ա��ʽ����ת��
public:                                //���ɱ��ʽ��
	Expression();                      //���ǰ�к�׺���ʽ
	~Expression();
	bool InfixToSuffix(string& exp);   //��׺���ʽ���׺���ʽ
	bool CreateTree();                 //�������ʽ��
	void ShowPrefix(Leaf* leaf);       //���ǰ׺���ʽ
	void ShowInfix(string& str);       //�����׺���ʽ
	void ShowSuffix(Leaf* leaf);       //�����׺���ʽ
	Leaf* GetTop() { return _first; }; //�õ����ʽ����ͷ�ڵ�
private:
	string _expression;                //��׺���ʽ�洢�ĵط�
	Leaf* _first;                      //���ʽ����ͷ�ڵ�
	void RemoveBlank(string& str);     //�Ƴ����ʽ�еĿո�
};

