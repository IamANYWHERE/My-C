#include"Expression.h"

int main(void) {
	Expression expression;   //创建表达式类的实例
	string exp;         
	cout << "请输入表达式：";
	getline(cin,exp);        //得到表达式
	string str = exp;
	if (!expression.InfixToSuffix(exp))
	{
		//中缀表达式到后缀表达式，失败则报错
		cout << "wrong expression!" << endl;
		return 1;
	}
	if (expression.CreateTree())
	{
		//创建表达式树
		cout << endl;
		cout << "波兰表达式：";
		expression.ShowPrefix(expression.GetTop());//输出前缀表达式
		cout << endl;
		cout << endl;
		cout << "中缀表达式：";
		expression.ShowInfix(str);                 //输出中缀表达式
		cout << endl;
		cout << endl;
		cout << "逆波兰表达式：";
		expression.ShowSuffix(expression.GetTop());//输出后缀表达式
		cout << endl;
	}
	else
	{
		//创建表达式树失败报错
		cout << "fault to create expression tree!!" << endl;
		return 1;
	}
	return 0;
}