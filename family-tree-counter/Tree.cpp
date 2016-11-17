#include"Tree.h"

bool Tree::Addmember(const string& childrenname, const string& parentsname) {
	//加入成员，如果没有先祖就创建先祖
	//否则把成员加入parentname下面
	if (_ancestor == NULL)
	{
		_ancestor = new Person;
		if (_ancestor == NULL)
			return false;
		_ancestor->_name = childrenname;
	}
	else
	{
		if (Findsent(parentsname))            //找到父节点的位置，并传给_operator
		{
			Person* person = new Person;      //创建子节点
			if (person == NULL)
				return false;
			person->_name = childrenname;
			_operator->_children.push_back(person); //放入父节点下面
			cout <<parentsname<<"的第一代子孙是：";
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
	//找到这个人位置
	//把位置传入_operator
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
	//找到这个名字的人把位置传给_operator
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
	//完善家庭成员，如果已经有家庭成员则返回false
	if (_ancestor == NULL)
		return false;
	if (Findsent(name))
	{
		if (_operator->_children.size() != 0)  //判断是否有家庭成员
		{
			cout << _operator->_name << "已经建立家庭！" << endl;
			return false;
		}
		else
		{
			int x = 0;
			cout << "请输入" << _operator->_name << "的儿女人数：";
			cin >> x;
			cout << "请依次输入" << _operator->_name << "的儿女的姓名：";
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
		cout << "没有这个人！！" << endl;
		return false;
	}
	cout << _operator->_name << "的第一代子孙是：";
	for (int i = 0; i < _operator->_children.size(); i++)
	{
		cout << _operator->_children[i]->_name << " ";
	}
	_operator = NULL;
	return true;
}
bool Tree::Removefamily(const string& name) {
	//去除这个人的子孙
	if (_ancestor == NULL)
		return false;
	if (Findsent(name))
	{
		if (_operator->_children.size() != 0)
		{
			cout << name << "的第一代子孙是：";
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
			cout << "无家庭！！" << endl;
			return false;
		}
	}
	else
	{
		cout << "没有这个人！！！" << endl;
		return false;
	}
}
void Tree::Remove(Person* person) {
	//移除这个人的子孙
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
	//改名字
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
		cout << "没有这个人！！！" << endl;
		return false;
	}
}

Tree::~Tree() {
	Remove(_ancestor);
}