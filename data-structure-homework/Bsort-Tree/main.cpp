#include"Bsort_Tree.h"
#include<iomanip>
int main(void) {
	cout << "**" << setw(30) << "����������" << setw(30) << "**"<<endl;
	cout << "==============================================================" << endl;
	cout << "**" << setw(36) << "1 --- ��������������" << setw(24) << "**" << endl;
	cout << "**" << setw(30) << "2 --- ����Ԫ��" << setw(30) << "**" << endl;
	cout << "**" << setw(30) << "3 --- ��ѯԪ��" << setw(30) << "**" << endl;
	cout << "**" << setw(30) << "4 --- �˳�����" << setw(30) << "**" << endl;
	cout << "==============================================================" << endl;

	Bsort_Tree Tree;    //��������������ϵͳ
	int x = 0;      
	while (x!=4)
	{
		int num1 = 0;
		int num2 = 0;
		cout << "Please select:";
		cin >> x;       //ѡ��Ҫִ�в���
		if (cin.fail()) {
			cin.clear();
			string str;
			cin >> str;
			cout << "����ȷѡ���������" << endl;
			continue;
		}
		switch (x)
		{
		case 1:         //����Ԫ�أ���������������
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
		case 2:   //����Ԫ��
			if (Tree.Isempty())
			{
				cout << "�㻹û�д�������������������" << endl;
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
		case 3:       //����Ԫ��
			if (Tree.Isempty())
			{
				cout << "�㻹û�д�������������������" << endl;
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
		case 4:          //�˳�����
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