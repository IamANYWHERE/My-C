#pragma once
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include"WinnerTree.h"

using namespace std;

class Quick;
class Sort {
private:
	vector<unsigned int> _vec;                     //���ڴ洢�����������
	int getDigit(unsigned int value, int d);       //�õ���dλ����1����Сλ
	unsigned int merge(vector<unsigned int>& vec1,vector<unsigned int>& vec2, int left, int mid, int right); //�鲢
public:
	Sort();
	~Sort();
	unsigned int Bubble(vector<unsigned int>& vec);         //ð������
	unsigned int Insertsort(vector<unsigned int>& vec);     //��������
	unsigned int Shellsort(vector<unsigned int>& vec);      //ϣ������
	unsigned int Quicksort(Quick& quickdata,const int left,const int right);                             //��������
	unsigned int Selectsort(vector<unsigned int>& vec,const int left,const int right);                   //ѡ������
	unsigned int TournamentSort(vector<unsigned int>& a, const int left, const int right);               //����������
	unsigned int mergeSort(vector<unsigned int>& vec1, vector<unsigned int>& vec2, int left, int right); //�鲢����
	unsigned int RadixSort(vector<unsigned int>& vec, int left, int right, int d);                       //��������
	unsigned int BinaryInsertSort(vector<unsigned int>& vec, int left, int right);                       //�۰��������
	vector<unsigned int>& getVector() {        //��ȡ�����������
		return _vec;
	}
	void random_number(const int& x);          //���������
};
class Quick {                                  //�����������
private:
	vector<unsigned int> vec;                  //�洢�����������
	int number;                                //���ݽ�������
	void Swap(unsigned int& x, unsigned int& y) {  //��������
		unsigned int transform;                
		transform = x;
		x = y;
		y = transform;
		number++;
	}
public:
	Quick() :number(0) {};                     
	int Partition(const int low, const int high); //���ֳ���������
	void setVec(vector<unsigned int>& v) {        //��������
		vec = v;
	}
	int getNumber() {                             //�õ���������
		return number;
	}
};