#include"Sorting.h"
#include"MaxHeap.h"
#include<string>
#include<iomanip>
int main(void)
{
	cout << "**" << setw(10)<<" "<< "�����㷨�Ƚ�" << setw(12) << "**" << endl;
	cout << "====================================" << endl;
	cout << "**" << setw(10) << "1" << " --- ð������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"2"<< " --- ѡ������" <<setw(11)<< "**" << endl;
	cout << "**" << setw(10) <<"3"<< " --- ֱ�Ӳ�������" << setw(7) << "**" << endl;
	cout << "**" << setw(10) <<"4"<< " --- ϣ������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"5"<< " --- ��������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"6"<< " --- ������" << setw(13) << "**" << endl;
	cout << "**" << setw(10) <<"7"<< " --- �鲢����" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"8"<< " --- ��������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) << "9" << " --- �۰��������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) << "10" << " --- ����������" << setw(11) << "**" << endl;
	cout << "**" << setw(10) <<"11"<< " --- �˳�����" << setw(11) << "**" << endl;
	Sort sort;
	unsigned int number = 0;
	while (true) {
		cout << "������Ҫ������������ĸ�����";
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			string str;
			cin >> str;
			cout << "�Ƿ����룬����������������" << endl;
		}
		else
			break;
	}//�������������
	sort.random_number(number); //���������
	if (sort.getVector().size() == 0) {
		cout << "���ݸ�������С�ڵ���0" << endl;
		return 0;
	}                           
	time_t t_start, t_end;       //����ʱ���
	cout << endl;
	int switch_on;
	int translate=0;
	bool judge = true;
	while (judge)           
	{
		while (true) {
			cout << "��ѡ�������㷨��      ";
			cin >> switch_on;
			if (cin.fail()) {
				cin.clear();
				string str;
				cin >> str;
				cout << "û�д˲�������" << endl;
			}
			else
				break;
		}   //�������
		vector<unsigned int> vec, vec2;
		int size = 0;
		int i = 0, d = 0;
		Quick quickdata;
		MaxHeap maxheap;
		switch (switch_on)
		{
		case 1:
			//ð������
			vec = sort.getVector();
			t_start = time(NULL);
			translate=sort.Bubble(vec);
			t_end = time(NULL);
				cout << "ð����������ʱ�䣺    " << t_end - t_start << endl;
				cout << "ð�����򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 2:
			//ѡ������
			vec = sort.getVector();
			size = vec.size();
			t_start = time(NULL);
			translate = sort.Selectsort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "ѡ����������ʱ�䣺    " << t_end - t_start << endl;
				cout << "ѡ�����򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 3:
			//��������
			vec = sort.getVector();
			t_start = time(NULL);
			translate = sort.Insertsort(vec);
			t_end = time(NULL);
				cout << "ֱ�Ӳ�����������ʱ�䣺    " << t_end - t_start << endl;
				cout << "ֱ�Ӳ������򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 4:
			//ϣ������
			vec = sort.getVector();
			t_start = time(NULL);
			translate = sort.Shellsort(vec);
			t_end = time(NULL);
				cout << "ϣ����������ʱ�䣺    " << t_end - t_start << endl;
				cout << "ϣ�����򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 5:
			//��������
			quickdata.setVec(sort.getVector());
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.Quicksort(quickdata, 0, size - 1);
			t_end = time(NULL);
				cout << "������������ʱ�䣺    " << t_end - t_start << endl;
				cout << "�������򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 6:
			//������
			vec = sort.getVector();
			maxheap.set(vec);
			t_start = time(NULL);
			translate = MaxHeap::HeapSort(maxheap);
			t_end = time(NULL);
				cout << "����������ʱ�䣺    " << t_end - t_start << endl;
				cout << "�����򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 7:
			//�鲢����
			vec = sort.getVector();
			vec2 = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.mergeSort(vec, vec2, 0, size - 1);
			t_end = time(NULL);
				cout << "�鲢��������ʱ�䣺    " << t_end - t_start << endl;
				cout << "�鲢���򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 8:
			//��������
			vec = sort.getVector();
			size = sort.getVector().size();
			i = size;
			while (true) {
				if (i == 0)
					break;
				i /= 10;
				d++;
			}
			t_start = time(NULL);
			translate = sort.RadixSort(vec, 0, size - 1, d);
			t_end = time(NULL);
				cout << "������������ʱ�䣺    " << t_end - t_start << endl;
				cout << "�������򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 9:
			//�۰��������
			vec = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.BinaryInsertSort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "�۰������������ʱ�䣺    " << t_end - t_start << endl;
				cout << "�۰�������򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 10:
			//����������
			vec = sort.getVector();
			size = sort.getVector().size();
			t_start = time(NULL);
			translate = sort.TournamentSort(vec, 0, size - 1);
			t_end = time(NULL);
				cout << "��������������ʱ�䣺    " << t_end - t_start << endl;
				cout << "���������򽻻�������    " << translate << endl;
				cout << endl;
			break;
		case 11:
			//��������
			cout << endl;
			judge = false;
			break;
		default:
			cout << "û�д˲�������" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}
