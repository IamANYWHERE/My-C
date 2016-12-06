#pragma once
#include<iostream>
#include<vector>
using namespace std;

class MaxHeap
{
	//����
public:
	MaxHeap();
	void set(vector<unsigned int>& vec); //��������
	static int HeapSort(MaxHeap& H);     //������
	~MaxHeap() {};
private:
	vector<int> heap;                    //��������
	int currentSize;                     //�����С
	int siftDown(int start, int m);      //������д��������start��λ��
	void Swap(const int i, const int j) { 
		                                 //��������
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}
};

