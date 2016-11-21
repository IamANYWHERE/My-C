#include"Game.h"

bool Game::Createcircle() {
	//������Ϸ���ݴ���ѭ������
	//����ע�˵�λ��
	Person* first = new Person;
	if (first == NULL)
		return false;
	first->_position = 1;
	Person* present = first;
	Person* person=NULL;
	for (int i = 2;i<=_whole_number; i++)
	{
		person = new Person;
		if (person == NULL)
			return false;
		person->_next = NULL;
		person->_position = i;
		present->_next = person;
		present = person;
	}
	_last = person;
	person->_next = first;
	return true;
}

bool Game::Inputgamedata() {
	cout << "������������Ϸ��������N��";
	cin >> _whole_number;
	if (_whole_number <= 0)
	{
		//����С��0����
		cerr << "�������������0����" << endl;
		return false;
	}
	cout << "��������Ϸ��ʼ��λ��S��  ";
	cin >> _start_position;
	if (_start_position <= 0 || _start_position > _whole_number)
	{
		//��ʼ��λ�ò���0��������֮�䱨��
		cerr << "��Ϸ��ʼλ�ñ�����1��" << _whole_number << "֮�䣡��" << endl;
		return false;
	}
	cout << "��������������M��        ";
	cin >> _death_digit;
	if (_death_digit <= 0)
	{
		//��������С�ڵ���0����
		cerr << "�������ֱ������0"<< endl;
		return false;
	}
	cout << "������ʣ�����������K��  ";
	cin >> _survive_number;
	if (_survive_number < 0 || _survive_number>_whole_number)
	{
		//������������0��������֮�䱨��
		cerr << "��������������0��" << _whole_number << "֮�䣡��" << endl;
		return false;
	}
	return true;
}
bool Game::Outperson() {
	//������̭��
	int deathnumber;   //��ȥ������=������-��������
	deathnumber = _whole_number - _survive_number;
	Person* person = _last;
	if (person == NULL)
	{
		return false;
	}
	while (person->_next->_position != _start_position)//�ҵ����ֵ�λ��
	{
		person = person->_next;
	}
	
	Person* transition = NULL;              //һ�����ɱ���
	for (int i = 1; i <= deathnumber; i++)
	{
		for (int j = 1; j <= _death_digit; j++)
		{
			if (j!=1)
			{
				person = person->_next;
			}
		}
		transition = person->_next;
		person->_next = transition->_next;
		cout << "��" <<setw(3)<< i << "�����ߵ�λ���ǣ�      ";
		cout.width(-10);
		cout<<" "<< transition->_position << endl;
		if (_last != transition)
		{
			delete transition;
		}
		else
		{
			_last = _last->_next;
			delete transition;
		}
	}
	return true;
}

bool Game::Showsurvivor() {
	//������λ�����
	if (_last == NULL)
		return false;
	Person* person1 = NULL;
	Person* person2 = NULL;
	person1 = _last;
	person2 = _last->_next;
	for (int i = 1; i <= _survive_number; i++)
	{
		if (person2->_position < person1->_position)
		{
			person1 = person2;
			person2 = person2->_next;
		}
	}

	cout << "���ʣ�£�       " << _survive_number << "��" << endl;
	cout << "ʣ�������λ��Ϊ��"<<endl;
	for (int i = 1; i <= _survive_number; i++)
	{
		cout << "   " <<setw(5)<< person1->_position << endl;
		person1 = person1->_next;
	}

}