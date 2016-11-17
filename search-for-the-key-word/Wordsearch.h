#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Wordsearch {
private:
	vector<string> _vec;       //存入文章，并用于计算单词个数
	vector<string> _first;     //存入文章，保存原文
	map<string, int> _map;     //存入单词和其出现次数
public:
	Wordsearch();
	~Wordsearch();
	void Inputword();             //输入文章
	bool Wordtotxt(ofstream& os); //把文章存入txt文件
	void Countword();             //计算单词出现次数
	void Lowtheword();            //把单词中的大写变小写
	void Removepunctuation();     //去除标点
	int Search(string str);       //查找单词
	void Txttocmd();              //输出文章
};
