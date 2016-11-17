#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cctype>
using namespace std;
#define MAX 0x7ffffff   //两个点的最大长度
class Prim {
	//若两个点没有
private:
	vector<int*> _graph;                 //记录两个顶点的长度
	vector<int> _lowcost;                //记录到已经进入最小生成树的点距离的最短的点
	vector<int> _mst;                    //记录点与哪个点相连
	vector<string> _name;                //记录点的名字
	int nametonum(const string& name);   //输出点的编号
	vector<int> _prim;                   //记录已进入最小生成树的点
	void show(const int& x);             //输出最小生成树
public:
	void Creategraph(const int& x);      //创建电网
	void Inputname(const int& x);        //输入点的名字
	void Inputlength(const string&name1,const string&name2,const int& length);//输入点与点之间的距离
	void Createprim(const string& name); //创建最小生成树
	void Showprim(const string & name);  //输出最小生成树
	bool Check();                        //检查是否有孤立点
	void Reset();                        //重置内部数据以便重新开始

};
