#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

typedef struct Person
{
	//以人为个体创建结构体为结点
	int _position;  //人的位置
	Person* _next;  //下一个人
}Person;

class Game {
private:
	Person* _last;        //指向最后一个节点的指针
	int _whole_number;    //游戏的总人数N
	int _start_position;  //游戏开始的位置S
	int _death_digit;     //死亡数字M
	int _survive_number;  //剩余的生者人数K
public:
	Game():_whole_number(0),_start_position(0),_death_digit(0),_survive_number(0) 
	{
		_last = NULL;
	}
	~Game()
	{
		Person* person=NULL;
		for (int i = 1; i <= _survive_number; i++)
		{
			person = _last;
			_last = _last->_next;
			delete person;
		}
	}
	bool Inputgamedata();      //输入游戏数据
	bool Createcircle();       //根据游戏数据创建循环链表
	bool Outperson();          //将代表要出局的人的节点删除
	bool Showsurvivor();       //将剩余生者的位置输出
};