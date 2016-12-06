#pragma once
#include<iostream>

using namespace std;

class WinnerTree
{
	//胜者数的类
public:
	const int maxValue = 0x7ffffff;    //最大数不会超过maxValue的值
	WinnerTree(int TreeSize = 20) :n(0),number(0) { t = new int[TreeSize]; };
	~WinnerTree() { delete[]t; };
	bool Initial(int a[], int size);                              //初始化胜者树
	bool rePlay();                                                //重新比赛，比胜者
	void Update() { e[t[1]] = maxValue; };                        //将原本最小的值设为最大，以便重新比赛
	int Winner()const { return(n != 0) ? e[t[1]] : 0; };          //输出胜者的编号
	int Winner(int a, int b) { return (e[a] <= e[b]) ? a : b; };  //输出a，b之中的胜者
	int number;                                                   //用于计算交换次数
private:
	int* t;                                                       //胜指树，用数组来代替树
	int* e;                                                       //随机数的数组
	int n;                                                        //数组大小
	int lowExt;                                                   //树最外层数据个数
	int offset;                                                   //树去掉最外层数据后的个数
	void Play(int k, int lc, int rc);                             //比赛
};

