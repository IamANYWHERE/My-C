#include"StaticList.h"
int main(void) {
	cout << "A为添加" << endl;
	cout << "B为插入" << endl;
	cout << "C为删除" << endl;
	cout << "D为长度" << endl;
	cout << "F输出" << endl;
	cout << "E为结束" << endl;
	StaticList staticlist;
	string str;
	while (true) {
		cin >> str;
		if (str == "over")
			break;
		staticlist.Append(str);
	}
	char ch = ' ';
	int number;
	while (ch != 'e' && ch != 'E')
	{
		cout << "选择操作！！" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'A':case 'a':
			cin >> str;
			staticlist.Append(str);
			cout << endl;
			break;
		case 'B':case 'b':
			cout << "输入数据和插入的位数" << endl;
			cin >> str;
			cin >> number;
			staticlist.Insert(str, number);
			cout << endl;
			break;
		case 'C':case 'c':
			cout << "请输入要删除的位置" << endl;
			cin >> number;
			staticlist.Remove(number);
			cout << endl;
			break;
		case 'D':case 'd':
			cout << staticlist.Length();
			cout << endl;
			break;
		case 'F':case 'f':
			staticlist.Show();
			cout << endl;
			break;
		case'e':case'E':
			break;
		default:
			cout << "没有" << endl;
			break;
		}
	}
	return 0;
}