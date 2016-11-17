#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct Leaf {      //树的节点
	int digit;             //数据
	Leaf* left;            //左子节点
	Leaf* right;           //右子节点
}Leaf;

class Bsort_Tree {   
	//二叉排序树
	//大的在右边
	//小的在左边
private:
	Leaf* _First;                             //树的顶点
	Leaf*& compare(Leaf*& leaf,const int& x); //树里面的元素比较大小并返回此值应该在的位置
	void show(Leaf* leaf);                    //输入二叉排序树
public:
	Bsort_Tree() { _First = NULL; };
	bool Createtree();                        //创建二叉排序树
	bool Insert(const int& digit);            //插入元素
	bool Search(const int& digit);            //查找元素
	void ShowTree();                          //输出二叉排序树
	bool Isempty();                           //是否为空
};