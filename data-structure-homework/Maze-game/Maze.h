#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Maze {
	//����һ���Թ���Ϸ���Թ��Ĵ�С���Թ���ͼ��Ҫ���������
	//��Ĭ�����Ϊ��1��1������Ϊ��n-1,n-1)
private:
	vector<string> _map;          //�����洢�Թ���ͼ
	vector<int*> _mark;           //������ǵ�ͼ���ڵ���ڵ�·��
	vector<int*> _path;           //������¼Ҫ�����㣨���ӳ��ڵ���ڣ�
	void Find(int x,int y);       //�Եݹ�ķ�ʽ�ҵ�ͨ�����ڵ�·��
	bool _judge;                  //�������·�����ҵ�
public:
	Maze();
	~Maze();
	bool CreateMaze(const int& mapSize);  //�����Թ�
	bool FindPath();                      //�ҵ�·��
	void Show();                          //�����ҵ�·������Թ�
};
