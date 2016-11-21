#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Chessboard {
private:
	int _count;               //用于计算摆法
	int _nqueen;              //设置有几个皇后
	bool odd;                 //true则有奇数个皇后，false则有偶数个
	bool mid;                 //表示odd为true时，当我第一排的皇后摆放在中间时为true
	vector<char*> _graph;     //用为计算皇后摆法时的存储器
public:
	Chessboard() :_nqueen(0), _count(0),odd(false),mid(false) { };    //初始化Maze
	bool Createboard(const int& x);                                   //创建n皇后存储器
	void Backtracking(int x,int y);                                   //计算n皇后的摆法
	int Count();                                                      //输出n皇后的摆法数
	void Showboard();                                                 //将所有n皇后的摆法输出
}; 