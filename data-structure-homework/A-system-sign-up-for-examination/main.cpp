#include"System.h"

int main(void) {
	cout << "�����뽨��������Ϣϵͳ��" << endl;
	cout << "�����뿼��������";
	int x = 0;
	cin >> x;

	System system;
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������" << endl;
	for (int i = 0; i < x; i++)
	{
		system.insert();
	}
	cout << endl;
	cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
	system.count();
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << endl;
	cout << endl;

	int operation = 6;
	while (operation != 0)
	{
		cout << "����ѡ��Ҫ���еĲ�����";
		cin >> operation;
		if (operation == 1)     //����
		{
			cout << "��������Ҫ����Ŀ���λ�ã�";
			int x;
			cin >> x;
			if (!system.insert(x))
			{
				cout << endl;
				cout << "�Բ��𣬲��ܲ����λ�ã�" << endl;
			}
			cout << endl;
			cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
			system.count();
		}
		else if (operation == 2) //ɾ��
		{
			cout << "������Ҫɾ���Ŀ����Ŀ��ţ�";
			int x;
			cin >> x;
			if (!system.cutoff(x))
			{
				cout << "�Բ���û�д˿�����" << endl;
			}
			cout << endl;
			cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
			system.count();
		}
		else if (operation == 3) //����
		{
			cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
			int x;
			cin >> x;
			if (!system.search(x))
			{
				cout << "�Բ���û�д˿�����" << endl;
			}
		}
		else if (operation == 4) //�޸�
		{
			cout << "������Ҫ�޸ĵĿ����Ŀ��ţ�";
			int x;
			cin >> x;
			if (!system.modify(x))
			{
				cout << "�Բ���û�д˿�����" << endl;
			}
			cout << endl;
			cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
			system.count();
		}
		else if (operation == 5) //ͳ��
		{
			cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
			system.count();
		}
		else if (operation == 0) //ȡ������
		{
			cout << "������ȡ����" << endl;
		}
	}

	return 0;
}