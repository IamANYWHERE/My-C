#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Maze {
	//这是一个迷宫游戏，迷宫的大小和迷宫地图需要玩家来输入
	//且默认入口为（1，1）出口为（n-1,n-1)
private:
	vector<string> _map;          //用来存储迷宫地图
	vector<int*> _mark;           //用来标记地图出口到入口的路径
	vector<int*> _path;           //用来记录要经过点（按从出口到入口）
	void Find(int x,int y,int const& outx,int const& outy);       //以递归的方式找到通往出口的路径
	bool _judge;                  //用来标记路径已找到
public:
	Maze();
	~Maze();
	bool CreateMaze(const int& y,const int& x);  //创建迷宫
	bool FindPath(int const& inx,int const& iny,int const& outx,int const& outy);                      //找到路径
	void Show();                          //输入找到路径后的迷宫
};
