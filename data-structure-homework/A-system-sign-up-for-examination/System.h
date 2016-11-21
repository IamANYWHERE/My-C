#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef struct Student
{
	//一个用来表示学生的结构体，形成链表方便存储学生信息
	int _exam_number;           //考号
	string _name;               //考生姓名
	string _sex;                //性别
	int _age;                   //年龄
	string _classification;     //报考类别
	Student* _next_student;     //下一个学生
}Student;


class System {
	//考生信息系统，对考生信息进行录入和其他操作
private:
	Student* _student;           //学生链表中的头学生
	int _number_student;         //表示学生的个数
	Student* _last_student;      //学生链表中的最后一个学生
public:
	System();
	~System();
	void insert();               //用于插入学生于链表尾
	bool insert(const int& x);   //用于插入学生于指定位置
	bool cutoff(const int& x);   //用于删除指定位置的学生
	bool search(const int& x);   //用于找到指定考号的学生
	bool modify(const int& x);   //用于修改指定考号学生的信息
	bool count();                //输出所有学生信息
};