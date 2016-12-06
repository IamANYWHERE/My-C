#include"Sorting.h"

Sort::Sort() {
}
Sort::~Sort() {

}
unsigned int Sort::Bubble(vector<unsigned int>& vec) {
	//冒泡排序
	bool judge = false;
	unsigned int x=0;
	unsigned int number = 0;
	int size = vec.size();
	for (int j = 0; j < size-1; j++)
	{
		for (int i = size-1; i >= 1; i--)
		{
			if (vec[i] < vec[i - 1])
			{
				x = vec[i-1];
				vec[i-1] = vec[i];
				vec[i] = x;
				number += 1;
				judge = true;
			}
		}
		if (judge == false)
			break;
		judge = false;
	}
	return number;
}
unsigned int Sort::Insertsort(vector<unsigned int>& vec) {
	//插入排序
	unsigned int x;
	unsigned int number = 0;
	int size = vec.size();
	for (int i = 1; i <=size-1; i++)
	{
		x = vec[i];
		for (int j = i-1; j>=0; j--)
		{
			if (x < vec[j])
			{
				vec[j + 1] = vec[j];
				number += 1;
				if (j == 0)
				{
					vec[0] = x;
					number += 1;
				}
			}
			else
			{
				vec[j + 1] = x;
				number += 1;
				break;
			}
		}
	}
	return number;
}
void Sort::random_number(const int& x) {
	//产生随机数
	srand((unsigned)time(NULL));
	for (int i = 0; i < x; i++)
	{
		_vec.push_back(rand() % x);
		
	}
}
unsigned int Sort::Shellsort(vector<unsigned int>& vec) {
	//希尔排序
	int size = vec.size();
	int gap = size;
	int j;
	unsigned int number = 0;
	int temp = 0;
	do {
		gap = int(gap / 3) + 1;
		for (int i = gap; i < size; i++)
		{
			if (vec[i] < vec[i - gap])
			{
				temp = vec[i];
				j = i - gap;
				while (j >= 0 && temp<vec[j]) {
					vec[j + gap] = vec[j];

					number++;
					j -= gap;
				}
				vec[j + gap] = temp;
				number++;
			}
		}
	} while (gap > 1);
	return number;
}

unsigned int Sort::Quicksort(Quick& quickdata,const int left,const int right) {
	//快速排序
	//递归见数组划分位两个区域，直到全部排好序
	if (left < right)
	{
		int pivotpos = quickdata.Partition(left, right);
		Quicksort(quickdata, left, pivotpos-1);
			Quicksort(quickdata, pivotpos+1, right);
	}
	return quickdata.getNumber();
}
int Quick::Partition(const int low, const int high) {
	//划分成两个区域，前面的区域小于中间值，后面的区域大于或等于中间值
	int pivotpos = low;            
	unsigned int pivot = vec[low];  //把vec[low]的值作为中间值
	for (int i = low + 1; i <= high; i++) 
		if (vec[i] < pivot)
		{
			pivotpos++;
			if (i != pivotpos)Swap(vec[i], vec[pivotpos]);
		}       //将数组划分位两个区域，前面小，后面大
	vec[low] = vec[pivotpos]; //将中间值移动到两个区域之间
	vec[pivotpos] = pivot;    
	number++;
	return pivotpos;        //返回中间值的位置
}

unsigned int Sort::Selectsort(vector<unsigned int>& vec,const int left,const int right) {
	//选择排序
	unsigned int translate;
	int number=0;
	for (int i = left; i < right; i++)
	{
		int x = i;
		for (int j = i+1; j <= right; j++)
			if (vec[j] < vec[x])x = j;
		if (x != i)
		{
			translate = vec[i];
			vec[i] = vec[x];
			vec[x] = translate;
			number++;
		}
	}
	return number;
}
unsigned int Sort::TournamentSort(vector<unsigned int>& a, const int left, const int right) {
	//竞标赛排序
	int size = right - left + 1;
	WinnerTree WT(size);
	int* data = new int[size + 1];
	int i;
	for (i = 1; i <= size; i++) {
		data[i] = a[i + left - 1];
	}
	if (!WT.Initial(data, size))return 0;
	for (i = 1; i <= size; i++) {
		a[i + left - 1] = WT.Winner();
		WT.Update();
		WT.rePlay();
		if (WT.Winner() == WT.maxValue)break;
	}
	cout << endl;
	return WT.number;
}

unsigned int Sort::merge(vector<unsigned int>& vec1, vector<unsigned int>& vec2, int left, int mid, int right) {
	//归并
	if (left >= right)return 0;
	for (int i = 0; i <= mid; i++)
		vec2[i] = vec1[i];
	for (int i = mid + 1; i <= right; i++)
		vec2[right - i + mid + 1] = vec1[i];
	int k = left;
	int a = left;
	int b = right;
	while (k <= right) {
		if (vec2[a] <= vec2[b])
			vec1[k++] = vec2[a++];
		else
			vec1[k++] = vec2[b--];
	}
	return right + 1;
}
unsigned int Sort::mergeSort(vector<unsigned int>& vec1, vector<unsigned int>& vec2, int left, int right) {
	//归并排序
	if (left >= right)return 0;
	int mid = (left + right) / 2;
	int a=0, b=0, c=0;
	a = mergeSort(vec1, vec2, left, mid);
	b = mergeSort(vec1, vec2, mid + 1, right);
	c=merge(vec1, vec2, left, mid, right);
	return a + b + c;
}
int Sort::getDigit(unsigned int value, int d) {
	//得到value的第d位数字，1位最小位
	int digit = 0;
	for (int i = 0; i < d; i++) {
		digit = value % 10;
		value /= 10;
	}
	return digit;
}

unsigned int Sort::RadixSort(vector<unsigned int>& vec, int left, int right, int d) {
	//基数排序
	if (d <= 0) {
		return 0;
	}
	int number = 0;
	int i, j, count[10], p1, p2;
	vector<unsigned int> auxArray(right - left + 1);
	for (i = 0; i < 10; i++) {
		count[i] = 0;
	}
	for (j = left; j <= right; j++) {
		count[getDigit(vec[j], d)]++;
	}
	
	for (i = 1; i < 10; i++) {
		count[i] = count[i] + count[i - 1];
	}
	for (j = left; j <= right; j++) {
		i = getDigit(vec[j], d);
		auxArray[count[i] - 1] = vec[j];
		count[i]--;
	}
	for (j = left, i = 0; j <= right; j++, i++) {
		vec[j] = auxArray[i];
	}
	number += right - left + 1;
	for (i = 0; i < 10; i++) {
		if (i == 9) {
			p1 = left+count[i];
			p2 = right;
		}
		else {
			p1 = left+count[i];
			p2 = left+count[i + 1] - 1;
		}
		if(p2>=p1)
			number+=RadixSort(vec, p1, p2, d - 1);
	}
	return number;
}

unsigned int Sort::BinaryInsertSort(vector<unsigned int>& vec, int left, int right) {
	//折半插入排序
	int i,j,low,high,middle;
	int value,number=0;
	for (int i = left + 1; i <= right; i++) {
		low = left; high = i - 1;
		value = vec[i];
		while (low <= high) {
			middle = (low + high) / 2;
			if (value<vec[middle])
				high = middle - 1;
			else
				low = middle + 1;
		}
		for (j = i; j > low; j--)
		{
			number++;
			vec[j] = vec[j - 1];
		}
		vec[low] = value;
		number++;
	}
	return number / 2;
}