#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

typedef struct Person
{
	//����Ϊ���崴���ṹ��Ϊ���
	int _position;  //�˵�λ��
	Person* _next;  //��һ����
}Person;

class Game {
private:
	Person* _last;        //ָ�����һ���ڵ��ָ��
	int _whole_number;    //��Ϸ��������N
	int _start_position;  //��Ϸ��ʼ��λ��S
	int _death_digit;     //��������M
	int _survive_number;  //ʣ�����������K
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
	bool Inputgamedata();      //������Ϸ����
	bool Createcircle();       //������Ϸ���ݴ���ѭ������
	bool Outperson();          //������Ҫ���ֵ��˵Ľڵ�ɾ��
	bool Showsurvivor();       //��ʣ�����ߵ�λ�����
};