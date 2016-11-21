#include"Game.h"

bool Game::Createcircle() {
	//根据游戏数据创建循环链表
	//并标注人的位置
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
	cout << "请输入生死游戏的总人数N：";
	cin >> _whole_number;
	if (_whole_number <= 0)
	{
		//人数小于0报错
		cerr << "总人数必须大于0！！" << endl;
		return false;
	}
	cout << "请输入游戏开始的位置S：  ";
	cin >> _start_position;
	if (_start_position <= 0 || _start_position > _whole_number)
	{
		//开始的位置不在0到总人数之间报错
		cerr << "游戏开始位置必须在1到" << _whole_number << "之间！！" << endl;
		return false;
	}
	cout << "请输入死亡数字M：        ";
	cin >> _death_digit;
	if (_death_digit <= 0)
	{
		//死亡数字小于等于0报错
		cerr << "死亡数字必须大于0"<< endl;
		return false;
	}
	cout << "请输入剩余的生者人数K：  ";
	cin >> _survive_number;
	if (_survive_number < 0 || _survive_number>_whole_number)
	{
		//生者人数不在0到总人数之间报错
		cerr << "生存人数必须在0到" << _whole_number << "之间！！" << endl;
		return false;
	}
	return true;
}
bool Game::Outperson() {
	//用于淘汰人
	int deathnumber;   //死去的人数=总人数-生者人数
	deathnumber = _whole_number - _survive_number;
	Person* person = _last;
	if (person == NULL)
	{
		return false;
	}
	while (person->_next->_position != _start_position)//找到出局的位置
	{
		person = person->_next;
	}
	
	Person* transition = NULL;              //一个过渡变量
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
		cout << "第" <<setw(3)<< i << "个死者的位置是：      ";
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
	//将生者位置输出
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

	cout << "最后剩下：       " << _survive_number << "人" << endl;
	cout << "剩余的生者位置为："<<endl;
	for (int i = 1; i <= _survive_number; i++)
	{
		cout << "   " <<setw(5)<< person1->_position << endl;
		person1 = person1->_next;
	}

}