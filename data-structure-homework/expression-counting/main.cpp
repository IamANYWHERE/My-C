#include"Expression.h"

int main(void) {
	Expression expression;   //�������ʽ���ʵ��
	string exp;         
	cout << "��������ʽ��";
	getline(cin,exp);        //�õ����ʽ
	string str = exp;
	if (!expression.InfixToSuffix(exp))
	{
		//��׺���ʽ����׺���ʽ��ʧ���򱨴�
		cout << "wrong expression!" << endl;
		return 1;
	}
	if (expression.CreateTree())
	{
		//�������ʽ��
		cout << endl;
		cout << "�������ʽ��";
		expression.ShowPrefix(expression.GetTop());//���ǰ׺���ʽ
		cout << endl;
		cout << endl;
		cout << "��׺���ʽ��";
		expression.ShowInfix(str);                 //�����׺���ʽ
		cout << endl;
		cout << endl;
		cout << "�沨�����ʽ��";
		expression.ShowSuffix(expression.GetTop());//�����׺���ʽ
		cout << endl;
	}
	else
	{
		//�������ʽ��ʧ�ܱ���
		cout << "fault to create expression tree!!" << endl;
		return 1;
	}
	return 0;
}