#include"System.h"

int main(void) {
	cout << "首先请建立考生信息系统！" << endl;
	cout << "请输入考生人数：";
	int x = 0;
	cin >> x;

	System system;
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	for (int i = 0; i < x; i++)
	{
		system.insert();
	}
	cout << endl;
	cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
	system.count();
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;
	cout << endl;

	int operation = 6;
	while (operation != 0)
	{
		cout << "请您选择要进行的操作：";
		cin >> operation;
		if (operation == 1)     //插入
		{
			cout << "请输入你要插入的考生位置：";
			int x;
			cin >> x;
			if (!system.insert(x))
			{
				cout << endl;
				cout << "对不起，不能插入此位置！" << endl;
			}
			cout << endl;
			cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
			system.count();
		}
		else if (operation == 2) //删除
		{
			cout << "请输入要删除的考生的考号：";
			int x;
			cin >> x;
			if (!system.cutoff(x))
			{
				cout << "对不起，没有此考生！" << endl;
			}
			cout << endl;
			cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
			system.count();
		}
		else if (operation == 3) //查找
		{
			cout << "请输入要查找的考生的考号：";
			int x;
			cin >> x;
			if (!system.search(x))
			{
				cout << "对不起，没有此考生！" << endl;
			}
		}
		else if (operation == 4) //修改
		{
			cout << "请输入要修改的考生的考号：";
			int x;
			cin >> x;
			if (!system.modify(x))
			{
				cout << "对不起，没有此考生！" << endl;
			}
			cout << endl;
			cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
			system.count();
		}
		else if (operation == 5) //统计
		{
			cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
			system.count();
		}
		else if (operation == 0) //取消操作
		{
			cout << "操作已取消！" << endl;
		}
	}

	return 0;
}