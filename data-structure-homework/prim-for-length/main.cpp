#include"Prim.h"

int main(void) {
	cout << "**" << "          " << "�������ģ��ϵͳ" << "          " << "**" << endl;
	cout << "========================================" << endl;
	cout<< "**" << "          " << "A--- ������������" << "         " << "**" << endl;
	cout<< "**" << "          " << "B--- ��ӵ����ı�" << "         " << "**" << endl;
	cout<< "**" << "          " << "C--- ������С������" << "       " << "**" << endl;
	cout<< "**" << "          " << "D--- ��ʾ��С������" << "       " << "**" << endl;
	cout<< "**" << "          " << "E--- �˳�   ����" << "          " << "**" << endl;
	cout << "========================================" << endl;

	Prim prim;       //������С������
	char ch;         
	int x=0;
	string name=" ";
	while (1)
	{
		cout << "��ѡ�������";
		cin >> ch;                   //ѡ�����
		if (ch == 'a' || ch == 'A')  //��������
		{
			prim.Reset();            //��������
			cout << "�����붥��ĸ�����";
			
			cin >> x;                //�����ĸ���
			if (cin.fail()) {
				cout << "��������ȷ�����֣���" << endl;
				cin.clear();
				string str;
				cin >> str;
				continue;
			}
			if (x <= 1)              //С�ڵ���һ�޷����ɵ���
			{
				cout << "�Բ��𣬶���̫�٣��������ɵ�����" << endl;
				x = 0;
				continue;
			}
			prim.Creategraph(x);     //��������
			cout << "������������������ƣ�";
			prim.Inputname(x);       //��������ϵĵ������
			cout << endl;
		}
		else if (ch == 'b' || ch == 'B')  //��������ľ���
		{
			if (x == 0)
			{
				cout << "��û�д���������" << endl;
				continue;
			}
			int i = 0;
			string name1=" ", name2=" ";
			int length = MAX;
			while (name1 != "?"||name2 != "?"||length != 0)
			{
				cout << "�������������㼰�ߣ�";
				cin >> name1 >> name2 >> length;
				if(name1 != "?" || name2 != "?" || length != 0)
					prim.Inputlength(name1, name2, length);
			}
			if (!prim.Check()) {
				cout << "�����й����㣡�����β�����Ч��\n�����´�������" << endl;
				x = 0;
			}
			cout << endl;
		}
		else if (ch == 'c' || ch == 'C')  //������С������
		{
			if (x == 0)
			{
				cout << "��û�д���������" << endl;
				continue;
			}
			cout << "��������ʼ���㣺";
			cin >> name;
			cout << "����Prim��С��������" << endl;
			prim.Createprim(name);
			cout << endl;
		}
		else if (ch == 'd' || ch == 'D')   //�����С������
		{
			if (x == 0)
			{
				cout << "��û�д���������" << endl;
				continue;
			}
			cout << "��С�������Ķ��㼰��Ϊ��" << endl;
			cout << endl;
			if (name == " ")
			{
				cout << "��û�й�����С��������" << endl;
				continue;
			}
			prim.Showprim(name);
		}
		else if (ch == 'e' || ch == 'E')  //�˳�����
			break;
		else
		{
			cout << "�Բ���û����Щ������" << endl;
		}
	}
	return 0;
}