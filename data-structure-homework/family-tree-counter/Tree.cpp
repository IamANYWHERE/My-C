#include"Tree.h"

bool Tree::Addmember(const string& childrenname, const string& parentsname) {
	//�����Ա�����û������ʹ�������
	//����ѳ�Ա����parentname����
	if (_ancestor == NULL)
	{
		_ancestor = new Person;
		if (_ancestor == NULL)
			return false;
		_ancestor->_name = childrenname;
	}
	else
	{
		if (Findsent(parentsname))            //�ҵ����ڵ��λ�ã�������_operator
		{
			Person* person = new Person;      //�����ӽڵ�
			if (person == NULL)
				return false;
			person->_name = childrenname;
			_operator->_children.push_back(person); //���븸�ڵ�����
			cout <<parentsname<<"�ĵ�һ�������ǣ�";
			for (int i = 0; i < _operator->_children.size(); i++)
			{
				cout << _operator->_children[i]->_name << " ";
			}
			_operator = NULL;
		}
		else
			return false;
	}
	return true;
}
bool Tree::Findsent(const string& name) {
	//�ҵ������λ��
	//��λ�ô���_operator
	Person* first = _ancestor;
	if (first == NULL)
		return false;
	Search(first, name);
	if (_operator == NULL)
		return false;
	else
		true;

}
void Tree::Search(Person* person,const string& name) {
	//�ҵ�������ֵ��˰�λ�ô���_operator
	if (person != NULL)
	{
		if (person->_name == name)
		{
			_operator = person;
		}
		else
		{
			if (person->_children.size() != 0)
			{
				for (int i = 0; i < person->_children.size(); i++)
				{
					Search(person->_children[i], name);
					if (_operator != NULL)
						break;
				}
			}
		}
	}
}
bool Tree::Changemembers(const string& name) {
	//���Ƽ�ͥ��Ա������Ѿ��м�ͥ��Ա�򷵻�false
	if (_ancestor == NULL)
		return false;
	if (Findsent(name))
	{
		if (_operator->_children.size() != 0)  //�ж��Ƿ��м�ͥ��Ա
		{
			cout << _operator->_name << "�Ѿ�������ͥ��" << endl;
			return false;
		}
		else
		{
			int x = 0;
			cout << "������" << _operator->_name << "�Ķ�Ů������";
			cin >> x;
			cout << "����������" << _operator->_name << "�Ķ�Ů��������";
			for (int i = 0; i < x; i++)
			{
				Person* person = new Person;
				if (person == NULL)
					return false;
				cin >> person->_name;
				_operator->_children.push_back(person);
			}
		}
	}
	else
	{
		cout << "û������ˣ���" << endl;
		return false;
	}
	cout << _operator->_name << "�ĵ�һ�������ǣ�";
	for (int i = 0; i < _operator->_children.size(); i++)
	{
		cout << _operator->_children[i]->_name << " ";
	}
	_operator = NULL;
	return true;
}
bool Tree::Removefamily(const string& name) {
	//ȥ������˵�����
	if (_ancestor == NULL)
		return false;
	if (Findsent(name))
	{
		if (_operator->_children.size() != 0)
		{
			cout << name << "�ĵ�һ�������ǣ�";
			for (int i = _operator->_children.size() - 1; i >= 0; i--)
			{
				cout << _operator->_children[i]->_name << " ";
				Remove(_operator->_children[i]);
				_operator->_children.pop_back();
			}
			if (_operator->_children.size() == 0)
			{
				_operator = NULL;
				return true;
			}
		}
		else
		{
			cout << "�޼�ͥ����" << endl;
			return false;
		}
	}
	else
	{
		cout << "û������ˣ�����" << endl;
		return false;
	}
}
void Tree::Remove(Person* person) {
	//�Ƴ�����˵�����
	if (person != NULL)
	{
		if (person->_children.size() != 0)
		{
			for (int i = 0; i < person->_children.size(); i++)
			{
				Remove(person->_children[i]);
			}
		}
			delete person;
	}
}
bool Tree::Changename(const string& opname, const string& newname) {
	//������
	if (_ancestor == NULL)
		return false;
	if (Findsent(opname))
	{
		if (_operator == NULL)
			return false;
		_operator->_name = newname;
		_operator = NULL;
		return true;
	}
	else
	{
		cout << "û������ˣ�����" << endl;
		return false;
	}
}

Tree::~Tree() {
	Remove(_ancestor);
}