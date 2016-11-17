#include"Tree.h"

int main(void) {
	cout << "**" << "               家谱管理系统                **" << endl;
	cout << "===============================================" << endl;
	cout << "**               请选择要执行的操作：        **" << endl;
	cout << "**               A --- 完善家谱              **" << endl;
	cout << "**               B --- 添加家庭成员          **" << endl;
	cout << "**               C --- 解散局部家庭成员      **" << endl;
	cout << "**               D --- 更改家庭成员姓名      **" << endl;
	cout << "**               E --- 退出程序              **" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << "(B操作只能一个一个添加，要想添加多个请选A)" << endl;
	cout << "(C操作是把某个人的子孙删除）" << endl;
	cout << endl;
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名：";
	string name;
	cin >> name;            //输入祖先的名字
	cout << "此家谱的祖先是：" << name << endl;
	cout << endl;

	Tree tree;              //创建树类的实例，也就是家谱管理系统
	tree.Addmember(name);   //输入祖先名字

	char ch = ' ';
	while (ch!='E'&&ch!='e')  
	{
		string opname,appname;
		cout << "请选择要执行的操作：";
		while (true)              //请输入正确的操作
		{
			cin >> ch;
			if (ch != 'A' && ch != 'a' && ch != 'B' && ch != 'b' && ch != 'C' && ch != 'c'
				&& ch != 'D' && ch != 'd' && ch != 'E' && ch != 'e')
				cout << "没有这个操作，请重新输入：";
			else
				break;
		}
		switch (ch)                     
		{
		case 'A':case 'a':                         //完善家谱
			cout << "请输入要建立家庭的人的姓名：";
			cin >> opname;
			tree.Changemembers(opname);
			cout << endl;
			cout << endl;
			break;
		case 'B':case 'b':                         //添加家庭成员
			
			cout << "请输入要添加儿子（或女儿）的人的姓名：";
			cin >> opname;
			cout << "请输入" << opname << "新添加的儿子（或女儿）的姓名：";
			cin >> appname;
			tree.Addmember(appname, opname);
			cout << endl;
			cout << endl;
			break;
		case 'C':case 'c':                         //解散局部家庭
			cout << "请输入要解散家庭的人的姓名：";
			cin >> opname;
			cout << "要解散家庭的人是：" << opname << endl;;
			tree.Removefamily(opname);
			cout << endl;
			cout << endl;
			break;
		case 'D':case 'd':                         //更改家庭成员姓名
			cout << "请输入要更改姓名的人的目前姓名：";
			cin >> opname;
			cout << "请输入更改后的姓名：";
			cin >> appname;
			cout << opname << "已更名为" << appname << endl;
			cout << endl;
			cout << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}