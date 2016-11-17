#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Person {                //person结构体表示人节点
	string _name;                      //人名
	vector<Person*> _children;         //子节点们
}Person;
class Tree {                           //树类用来实现家谱系统方法
private:
	Person* _ancestor;                 //家族中起始人（头节点）
	Person* _operator;                 //正在操作的人节点
	bool Findsent(const string& name);                //这个人在家谱中有没有
	void Search(Person*person,const string& name);    //在家谱中找人
	void Remove(Person* person);                      //在家谱中删除这个人及其后代
public:
	Tree() { _ancestor = NULL; _operator = NULL; };   //初始化
	~Tree();
	bool Addmember(const string& childrenname,const string& parentsname="ancestor");  //把人加入家谱
	bool Changemembers(const string& name);                                           //在某个人下面加入下一代
	bool Changename(const string& opname,const string& newname);                      //改某个人的名字
	bool Removefamily(const string& name);                                            //删除某个人的子孙们
};