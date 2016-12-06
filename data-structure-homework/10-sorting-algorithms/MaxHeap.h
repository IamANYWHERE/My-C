#pragma once
#include<iostream>
#include<vector>
using namespace std;

class MaxHeap
{
	//堆类
public:
	MaxHeap();
	void set(vector<unsigned int>& vec); //设置数组
	static int HeapSort(MaxHeap& H);     //堆排序
	~MaxHeap() {};
private:
	vector<int> heap;                    //数据数组
	int currentSize;                     //数组大小
	int siftDown(int start, int m);      //将最堆中大的数调到start的位置
	void Swap(const int i, const int j) { 
		                                 //交换数据
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}
};

