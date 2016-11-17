#pragma once
#include<iostream>
#include<string>
using namespace std;

const int INCREASE = 10;
typedef struct Node
{
	string str;
	int index;
}Node;
class StaticList
{
private:
	Node* _staticlist;
	int _emptytop;
	int _totallength;
	void CheckIntegrate();
public:
	StaticList(int x=10);
	~StaticList();
	int Length();
	void Append(const string& str);
	int Locate(int num);
	bool Insert(const string& str, int num);
	bool Remove(int num);
	void Show();
};

