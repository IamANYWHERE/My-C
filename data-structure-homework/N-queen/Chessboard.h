#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Chessboard {
private:
	int _count;               //���ڼ���ڷ�
	int _nqueen;              //�����м����ʺ�
	bool odd;                 //true�����������ʺ�false����ż����
	bool mid;                 //��ʾoddΪtrueʱ�����ҵ�һ�ŵĻʺ�ڷ����м�ʱΪtrue
	vector<char*> _graph;     //��Ϊ����ʺ�ڷ�ʱ�Ĵ洢��
public:
	Chessboard() :_nqueen(0), _count(0),odd(false),mid(false) { };    //��ʼ��Maze
	bool Createboard(const int& x);                                   //����n�ʺ�洢��
	void Backtracking(int x,int y);                                   //����n�ʺ�İڷ�
	int Count();                                                      //���n�ʺ�İڷ���
	void Showboard();                                                 //������n�ʺ�İڷ����
}; 