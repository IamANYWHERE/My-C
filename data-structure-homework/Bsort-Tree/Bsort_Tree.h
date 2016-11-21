#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct Leaf {      //���Ľڵ�
	int digit;             //����
	Leaf* left;            //���ӽڵ�
	Leaf* right;           //���ӽڵ�
}Leaf;

class Bsort_Tree {   
	//����������
	//������ұ�
	//С�������
private:
	Leaf* _First;                             //���Ķ���
	Leaf*& compare(Leaf*& leaf,const int& x); //�������Ԫ�رȽϴ�С�����ش�ֵӦ���ڵ�λ��
	void show(Leaf* leaf);                    //�������������
public:
	Bsort_Tree() { _First = NULL; };
	bool Createtree();                        //��������������
	bool Insert(const int& digit);            //����Ԫ��
	bool Search(const int& digit);            //����Ԫ��
	void ShowTree();                          //�������������
	bool Isempty();                           //�Ƿ�Ϊ��
};