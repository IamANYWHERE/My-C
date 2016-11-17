#include"Prim.h"

int main(void) {
	cout << "**" << "          " << "电网造价模拟系统" << "          " << "**" << endl;
	cout << "========================================" << endl;
	cout<< "**" << "          " << "A--- 创建电网顶点" << "         " << "**" << endl;
	cout<< "**" << "          " << "B--- 添加电网的边" << "         " << "**" << endl;
	cout<< "**" << "          " << "C--- 构造最小生成树" << "       " << "**" << endl;
	cout<< "**" << "          " << "D--- 显示最小生成树" << "       " << "**" << endl;
	cout<< "**" << "          " << "E--- 退出   程序" << "          " << "**" << endl;
	cout << "========================================" << endl;

	Prim prim;       //创建最小生成树
	char ch;         
	int x=0;
	string name=" ";
	while (1)
	{
		cout << "请选择操作：";
		cin >> ch;                   //选择操作
		if (ch == 'a' || ch == 'A')  //创建电网
		{
			prim.Reset();            //重置数据
			cout << "请输入顶点的个数：";
			
			cin >> x;                //输入点的个数
			if (cin.fail()) {
				cout << "请输入正确的数字！！" << endl;
				cin.clear();
				string str;
				cin >> str;
				continue;
			}
			if (x <= 1)              //小于等于一无法生成电网
			{
				cout << "对不起，顶点太少，不能生成电网。" << endl;
				x = 0;
				continue;
			}
			prim.Creategraph(x);     //创建电网
			cout << "请依次输入各项顶点的名称：";
			prim.Inputname(x);       //输入电网上的点的名称
			cout << endl;
		}
		else if (ch == 'b' || ch == 'B')  //输入点与点的距离
		{
			if (x == 0)
			{
				cout << "还没有创建电网！" << endl;
				continue;
			}
			int i = 0;
			string name1=" ", name2=" ";
			int length = MAX;
			while (name1 != "?"||name2 != "?"||length != 0)
			{
				cout << "请输入两个顶点及边：";
				cin >> name1 >> name2 >> length;
				if(name1 != "?" || name2 != "?" || length != 0)
					prim.Inputlength(name1, name2, length);
			}
			if (!prim.Check()) {
				cout << "不能有孤立点！！本次操作无效！\n请重新创建电网" << endl;
				x = 0;
			}
			cout << endl;
		}
		else if (ch == 'c' || ch == 'C')  //生成最小生成树
		{
			if (x == 0)
			{
				cout << "还没有创建电网！" << endl;
				continue;
			}
			cout << "请输入起始顶点：";
			cin >> name;
			cout << "生成Prim最小生成树！" << endl;
			prim.Createprim(name);
			cout << endl;
		}
		else if (ch == 'd' || ch == 'D')   //输出最小生成树
		{
			if (x == 0)
			{
				cout << "还没有创建电网！" << endl;
				continue;
			}
			cout << "最小生成树的顶点及边为：" << endl;
			cout << endl;
			if (name == " ")
			{
				cout << "还没有构造最小生成树！" << endl;
				continue;
			}
			prim.Showprim(name);
		}
		else if (ch == 'e' || ch == 'E')  //退出操作
			break;
		else
		{
			cout << "对不起，没有这些操作！" << endl;
		}
	}
	return 0;
}