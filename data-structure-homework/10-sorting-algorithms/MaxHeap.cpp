#include "MaxHeap.h"

MaxHeap::MaxHeap()
{

}
void MaxHeap::set(vector<unsigned int>& vec) {
	currentSize = vec.size();
	for (int i = 0; i < currentSize; i++) {
		heap.push_back(vec[i]);
	}
}

int MaxHeap::siftDown(int start,int m) {
	//将堆中最大的数据上调到start
	int count=0;
	int i = start;
	int j = i * 2 + 1;
	int tmp = heap[i];
	while (j<=m)
	{
		if (j < m&&heap[j] < heap[j + 1])j++;
		if (heap[j] <= tmp)break;
		else {
			count++;
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	count++;
	heap[i] = tmp;
	return count/2;
}
int MaxHeap::HeapSort(MaxHeap& H) {
	//堆排序
	cout << endl;
	int count = 0;
	for (int i = (H.currentSize - 2) / 2; i >= 0; i--) {
		count+=H.siftDown(i, H.currentSize - 1);
	}//初始化堆
	for (int i = H.currentSize - 1; i >= 0; i--) {
		H.Swap(0, i);
		count+=H.siftDown(0, i - 1)/2;
		count++;
	}//排序
	return count;
}
