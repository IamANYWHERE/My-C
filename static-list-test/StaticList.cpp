#include "StaticList.h"



StaticList::StaticList(int x) {
	_emptytop = 1;
	_totallength = x;
	_staticlist = new Node[x];
	_staticlist[0].index = -1;
	_staticlist[0].str = "#";
	for (int i = 1; i < x - 1; i++) {
		_staticlist[i].index = i + 1;
		_staticlist[i].str = "#";
	}
	_staticlist[x - 1].index = -1;
	_staticlist[x - 1].str = "#";
}

StaticList::~StaticList()
{
	delete []_staticlist;
}
void StaticList::CheckIntegrate() {
	if (_emptytop == -1) {
		int length = Length();
		Node* arraylist = new Node[length + 1 + INCREASE];
		_totallength = length + 1 + INCREASE;
		int p = _staticlist[0].index;
		arraylist[0].index = p;
		arraylist[0].str = "#";
		while (p!=-1)
		{
			arraylist[p].str = _staticlist[p].str;
			arraylist[p].index = _staticlist[p].index;
			p = _staticlist[p].index;
		}
		_emptytop = length + 1;
		for (int i = _emptytop; i < length +INCREASE; i++) {
			arraylist[i].index = i + 1;
			arraylist[i].str = "#";
		}
		arraylist[length +INCREASE].index = -1;
		arraylist[length + INCREASE].str = "#";
		Node* q = _staticlist;
		_staticlist = arraylist;
		delete []q;
	}
}
int StaticList::Length() {
	int p = _staticlist[0].index;
	int number = 0;
	while (p != -1) {
		p = _staticlist[p].index;
		number++;
	}
	return number;
}
void StaticList::Append(const string& str) {
	CheckIntegrate();
	int p = _emptytop;
	_emptytop = _staticlist[p].index;
	_staticlist[p].index = -1;
	_staticlist[p].str = str;
	_staticlist[Locate(Length())].index = p;
	for (int i = 0; i <_totallength ; i++) {
		cout << _staticlist[i].str << " ";
	}
	cout << endl;
}
int StaticList::Locate(int num) {
	int p=0;
	if (num == 0)
		return 0;
	for (int i = 1; i <= num; i++)
	{
		p = _staticlist[p].index;
		if (p == -1)
			break;
	}
	return p;
}
bool StaticList::Insert(const string& str, int num) {
	CheckIntegrate();
	int index = Locate(num);
	if (index == -1)
		return false;
	int p = _emptytop;
	_emptytop = _staticlist[p].index;
	_staticlist[p].str = str;
	int q = _staticlist[index].index;
	_staticlist[index].index = p;
	_staticlist[p].index = q;
	return true;
}
bool StaticList::Remove(int num) {
	int index = Locate(num-1);
	if (index == -1)
		return false;
	int p = _staticlist[index].index;
	if (p == -1)
		return false;
	_staticlist[index].index = _staticlist[p].index;
	_staticlist[p].index = _emptytop;
	_emptytop = p;
	return true;
}
void StaticList::Show() {
	int p = _staticlist[0].index;
	while (p != -1) {
		cout << _staticlist[p].str << endl;
		p = _staticlist[p].index;
	}
}