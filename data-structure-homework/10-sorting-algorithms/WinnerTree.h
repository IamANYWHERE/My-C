#pragma once
#include<iostream>

using namespace std;

class WinnerTree
{
	//ʤ��������
public:
	const int maxValue = 0x7ffffff;    //��������ᳬ��maxValue��ֵ
	WinnerTree(int TreeSize = 20) :n(0),number(0) { t = new int[TreeSize]; };
	~WinnerTree() { delete[]t; };
	bool Initial(int a[], int size);                              //��ʼ��ʤ����
	bool rePlay();                                                //���±�������ʤ��
	void Update() { e[t[1]] = maxValue; };                        //��ԭ����С��ֵ��Ϊ����Ա����±���
	int Winner()const { return(n != 0) ? e[t[1]] : 0; };          //���ʤ�ߵı��
	int Winner(int a, int b) { return (e[a] <= e[b]) ? a : b; };  //���a��b֮�е�ʤ��
	int number;                                                   //���ڼ��㽻������
private:
	int* t;                                                       //ʤָ������������������
	int* e;                                                       //�����������
	int n;                                                        //�����С
	int lowExt;                                                   //����������ݸ���
	int offset;                                                   //��ȥ����������ݺ�ĸ���
	void Play(int k, int lc, int rc);                             //����
};

