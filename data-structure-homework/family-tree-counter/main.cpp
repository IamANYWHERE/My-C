#include"Tree.h"

int main(void) {
	cout << "**" << "               ���׹���ϵͳ                **" << endl;
	cout << "===============================================" << endl;
	cout << "**               ��ѡ��Ҫִ�еĲ�����        **" << endl;
	cout << "**               A --- ���Ƽ���              **" << endl;
	cout << "**               B --- ��Ӽ�ͥ��Ա          **" << endl;
	cout << "**               C --- ��ɢ�ֲ���ͥ��Ա      **" << endl;
	cout << "**               D --- ���ļ�ͥ��Ա����      **" << endl;
	cout << "**               E --- �˳�����              **" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << "(B����ֻ��һ��һ����ӣ�Ҫ����Ӷ����ѡA)" << endl;
	cout << "(C�����ǰ�ĳ���˵�����ɾ����" << endl;
	cout << endl;
	cout << "���Ƚ���һ�����ף�" << endl;
	cout << "���������ȵ�������";
	string name;
	cin >> name;            //�������ȵ�����
	cout << "�˼��׵������ǣ�" << name << endl;
	cout << endl;

	Tree tree;              //���������ʵ����Ҳ���Ǽ��׹���ϵͳ
	tree.Addmember(name);   //������������

	char ch = ' ';
	while (ch!='E'&&ch!='e')  
	{
		string opname,appname;
		cout << "��ѡ��Ҫִ�еĲ�����";
		while (true)              //��������ȷ�Ĳ���
		{
			cin >> ch;
			if (ch != 'A' && ch != 'a' && ch != 'B' && ch != 'b' && ch != 'C' && ch != 'c'
				&& ch != 'D' && ch != 'd' && ch != 'E' && ch != 'e')
				cout << "û��������������������룺";
			else
				break;
		}
		switch (ch)                     
		{
		case 'A':case 'a':                         //���Ƽ���
			cout << "������Ҫ������ͥ���˵�������";
			cin >> opname;
			tree.Changemembers(opname);
			cout << endl;
			cout << endl;
			break;
		case 'B':case 'b':                         //��Ӽ�ͥ��Ա
			
			cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
			cin >> opname;
			cout << "������" << opname << "����ӵĶ��ӣ���Ů������������";
			cin >> appname;
			tree.Addmember(appname, opname);
			cout << endl;
			cout << endl;
			break;
		case 'C':case 'c':                         //��ɢ�ֲ���ͥ
			cout << "������Ҫ��ɢ��ͥ���˵�������";
			cin >> opname;
			cout << "Ҫ��ɢ��ͥ�����ǣ�" << opname << endl;;
			tree.Removefamily(opname);
			cout << endl;
			cout << endl;
			break;
		case 'D':case 'd':                         //���ļ�ͥ��Ա����
			cout << "������Ҫ�����������˵�Ŀǰ������";
			cin >> opname;
			cout << "��������ĺ��������";
			cin >> appname;
			cout << opname << "�Ѹ���Ϊ" << appname << endl;
			cout << endl;
			cout << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}