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
	vector<unsigned int> _vec;                     //用于存储产生的随机数
	int getDigit(unsigned int value, int d);       //得到第d位数，1是最小位
	unsigned int merge(vector<unsigned int>& vec1,vector<unsigned int>& vec2, int left, int mid, int right); //归并
public:
	Sort();
	~Sort();
	unsigned int Bubble(vector<unsigned int>& vec);         //冒泡排序
	unsigned int Insertsort(vector<unsigned int>& vec);     //插入排序
	unsigned int Shellsort(vector<unsigned int>& vec);      //希尔排序
	unsigned int Quicksort(Quick& quickdata,const int left,const int right);                             //快速排序
	unsigned int Selectsort(vector<unsigned int>& vec,const int left,const int right);                   //选择排序
	unsigned int TournamentSort(vector<unsigned int>& a, const int left, const int right);               //锦标赛排序
	unsigned int mergeSort(vector<unsigned int>& vec1, vector<unsigned int>& vec2, int left, int right); //归并排序
	unsigned int RadixSort(vector<unsigned int>& vec, int left, int right, int d);                       //基数排序
	unsigned int BinaryInsertSort(vector<unsigned int>& vec, int left, int right);                       //折半插入排序
	vector<unsigned int>& getVector() {        //获取随机数的数组
		return _vec;
	}
	void random_number(const int& x);          //生成随机数
};
class Quick {                                  //快速排序的类
private:
	vector<unsigned int> vec;                  //存储的随机数数组
	int number;                                //数据交换次数
	void Swap(unsigned int& x, unsigned int& y) {  //交换数据
		unsigned int transform;                
		transform = x;
		x = y;
		y = transform;
		number++;
	}
public:
	Quick() :number(0) {};                     
	int Partition(const int low, const int high); //划分成两个区域
	void setVec(vector<unsigned int>& v) {        //设置数组
		vec = v;
	}
	int getNumber() {                             //得到交换次数
		return number;
	}
};