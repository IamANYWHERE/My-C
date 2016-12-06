#include"Sorting.h"
#include"MaxHeap.h"
#include<string>
#include<iomanip>
int main(void)
{
	cout << "**" << setw(10)<<" "<< "排序算法比较" << setw(12) << "**" << endl;
	cout << "====================================" << endl;
	cout << "**" << setw(10) << "1" << " --- 冒泡排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"2"<< " --- 选择排序" <<setw(11)<< "**" << endl;
	cout << "**" << setw(10) <<"3"<< " --- 直接插入排序" << setw(7) << "**" << endl;
	cout << "**" << setw(10) <<"4"<< " --- 希尔排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"5"<< " --- 快速排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"6"<< " --- 堆排序" << setw(13) << "**" << endl;
	cout << "**" << setw(10) <<"7"<< " --- 归并排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"8"<< " --- 基数排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) << "9" << " --- 折半插入排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) << "10" << " --- 锦标赛排序" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"11"<< " --- 退出程序" << setw(11) << "**" << endl;
	Sort sort;
	unsigned int number = 0;
	while (true) {
		cout << "请输入要产生的随机数的个数：";
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			string str;
			cin >> str;
			cout << "非法输入，请输入正整数！！" << endl;
		}
		else
			break;
	}//输入随机数个数
	sort.random_number(number); //产生随机数
	if (sort.getVector().size() == 0) {
		cout << "数据个数不能小于等于0" << endl;
		return 0;
	}                           
	time_t t_start, t_end;       //计算时间的
	cout << endl;
	int switch_on;
	int translate=0;
	bool judge = true;
	while (judge)           
	{
		while (true) {
			cout << "请选择排序算法：      ";
			cin >> switch_on;
			if (cin.fail()) {
				cin.clear();
				string str;
				cin >> str;
				cout << "没有此操作！！" << endl;
			}
			else
				break;
		}   //输入操作
		vector<unsigned int> vec, vec2;
		int size = 0;
		int i = 0, d = 0;
		Quick quickdata;
		MaxHeap maxheap;
		switch (switch_on)
		{
		case 1:
			//冒泡排序
			vec = sort.getVector();
			t_start = time(NULL);
			translate=sort.Bubble(vec);
			t_end = time(NULL);
				cout << "冒泡排序所用时间：    " << t_end - t_start << endl;
				cout << "冒泡排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 2:
			//选择排序
			vec = sort.getVector();
			size = vec.size();
			t_start = time(NULL);
			translate = sort.Selectsort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "选择排序所用时间：    " << t_end - t_start << endl;
				cout << "选择排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 3:
			//插入排序
			vec = sort.getVector();
			t_start = time(NULL);
			translate = sort.Insertsort(vec);
			t_end = time(NULL);
				cout << "直接插入排序所用时间：    " << t_end - t_start << endl;
				cout << "直接插入排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 4:
			//希尔排序
			vec = sort.getVector();
			t_start = time(NULL);
			translate = sort.Shellsort(vec);
			t_end = time(NULL);
				cout << "希尔排序所用时间：    " << t_end - t_start << endl;
				cout << "希尔排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 5:
			//快速排序
			quickdata.setVec(sort.getVector());
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.Quicksort(quickdata, 0, size - 1);
			t_end = time(NULL);
				cout << "快速排序所用时间：    " << t_end - t_start << endl;
				cout << "快速排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 6:
			//堆排序
			vec = sort.getVector();
			maxheap.set(vec);
			t_start = time(NULL);
			translate = MaxHeap::HeapSort(maxheap);
			t_end = time(NULL);
				cout << "堆排序所用时间：    " << t_end - t_start << endl;
				cout << "堆排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 7:
			//归并排序
			vec = sort.getVector();
			vec2 = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.mergeSort(vec, vec2, 0, size - 1);
			t_end = time(NULL);
				cout << "归并排序所用时间：    " << t_end - t_start << endl;
				cout << "归并排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 8:
			//基数排序
			vec = sort.getVector();
			size = sort.getVector().size();
			i = size;
			while (true) {
				if (i == 0)
					break;
				i /= 10;
				d++;
			}
			t_start = time(NULL);
			translate = sort.RadixSort(vec, 0, size - 1, d);
			t_end = time(NULL);
				cout << "基数排序所用时间：    " << t_end - t_start << endl;
				cout << "基数排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 9:
			//折半插入排序
			vec = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.BinaryInsertSort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "折半插入排序所用时间：    " << t_end - t_start << endl;
				cout << "折半插入排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 10:
			//竞标赛排序
			vec = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.TournamentSort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "锦标赛排序所用时间：    " << t_end - t_start << endl;
				cout << "锦标赛排序交换次数：    " << translate << endl;
				cout << endl;
			break;
		case 11:
			//结束程序
			cout << endl;
			judge = false;
			break;
		default:
			cout << "没有此操作！！" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}
