#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef struct Student
{
	//һ��������ʾѧ���Ľṹ�壬�γ�������洢ѧ����Ϣ
	int _exam_number;           //����
	string _name;               //��������
	string _sex;                //�Ա�
	int _age;                   //����
	string _classification;     //�������
	Student* _next_student;     //��һ��ѧ��
}Student;


class System {
	//������Ϣϵͳ���Կ�����Ϣ����¼�����������
private:
	Student* _student;           //ѧ�������е�ͷѧ��
	int _number_student;         //��ʾѧ���ĸ���
	Student* _last_student;      //ѧ�������е����һ��ѧ��
public:
	System();
	~System();
	void insert();               //���ڲ���ѧ��������β
	bool insert(const int& x);   //���ڲ���ѧ����ָ��λ��
	bool cutoff(const int& x);   //����ɾ��ָ��λ�õ�ѧ��
	bool search(const int& x);   //�����ҵ�ָ�����ŵ�ѧ��
	bool modify(const int& x);   //�����޸�ָ������ѧ������Ϣ
	bool count();                //�������ѧ����Ϣ
};