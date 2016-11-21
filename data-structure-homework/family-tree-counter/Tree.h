#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Person {                //person�ṹ���ʾ�˽ڵ�
	string _name;                      //����
	vector<Person*> _children;         //�ӽڵ���
}Person;
class Tree {                           //��������ʵ�ּ���ϵͳ����
private:
	Person* _ancestor;                 //��������ʼ�ˣ�ͷ�ڵ㣩
	Person* _operator;                 //���ڲ������˽ڵ�
	bool Findsent(const string& name);                //������ڼ�������û��
	void Search(Person*person,const string& name);    //�ڼ���������
	void Remove(Person* person);                      //�ڼ�����ɾ������˼�����
public:
	Tree() { _ancestor = NULL; _operator = NULL; };   //��ʼ��
	~Tree();
	bool Addmember(const string& childrenname,const string& parentsname="ancestor");  //���˼������
	bool Changemembers(const string& name);                                           //��ĳ�������������һ��
	bool Changename(const string& opname,const string& newname);                      //��ĳ���˵�����
	bool Removefamily(const string& name);                                            //ɾ��ĳ���˵�������
};