#include"Bsort_Tree.h"
#include<iomanip>
int main(void) {
	cout << "**" << setw(30) << "二叉排序树" << setw(30) << "**"<<endl;
	cout << "==============================================================" << endl;
	cout << "**" << setw(36) << "1 --- 建立二叉排序树" << setw(24) << "**" << endl;
	cout << "**" << setw(30) << "2 --- 插入元素" << setw(30) << "**" << endl;
	cout << "**" << setw(30) << "3 --- 查询元素" << setw(30) << "**" << endl;
	cout << "**" << setw(30) << "4 --- 退出程序" << setw(30) << "**" << endl;
	cout << "==============================================================" << endl;

	Bsort_Tree Tree;    //创建二叉排序树系统
	int x = 0;      
	while (x!=4)
	{
		int num1 = 0;
		int num2 = 0;
		cout << "Please select:";
		cin >> x;       //选择要执行操作
		if (cin.fail()) {
			cin.clear();
			string str;
			cin >> str;
			cout << "请正确选择操作！！" << endl;
			continue;
		}
		switch (x)
		{
		case 1:         //输入元素，创建二叉排序树
			if (Tree.Isempty())
			{
				if (Tree.Createtree())
				{
					cout << "Bsort_Tree is:" << endl;
					Tree.ShowTree();
					cout << endl;
					cout << endl;
				}
				else
				{
					cout << "fault to build Bsort_Tree!" << endl;
					cout << endl;
					cout << endl;
				}
			}
			else
			{
				cout << "you have build Bsort_Tree!" << endl;
				cout << endl;
				cout << endl;
			}
			break;
		case 2:   //插入元素
			if (Tree.Isempty())
			{
				cout << "你还没有创建二叉排序树！！！" << endl;
				break;
			}
			cout << "Please input key which inserted:  " ;
			cin >> num1;
			if (Tree.Insert(num1))
			{
				cout << "Bsort_Tree is: " << endl;
				Tree.ShowTree();
				cout << endl;
				cout << endl;
			}
			else
			{
				cout << "fault to insert !" << endl;
				cout << endl;
				cout << endl;
			}
			break;
		case 3:       //查找元素
			if (Tree.Isempty())
			{
				cout << "你还没有创建二叉排序树！！！" << endl;
				break;
			}
			cout << "Please input key which inserted:  ";
			cin >> num2;
			if (Tree.Search(num2))
			{
				cout << "search success!" << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				cout <<num2<< " not exist!" << endl;
				cout << endl;
				cout << endl;
			}
			break;
		case 4:          //退出程序
			break;
		default:
			cout << "sorry! we don't have this selection!" << endl;
			cout << endl;
			cout << endl;
			break;
		}
	}


	return 0;
}