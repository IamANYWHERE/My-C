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
	vector<string> _vec;       //�������£������ڼ��㵥�ʸ���
	vector<string> _first;     //�������£�����ԭ��
	map<string, int> _map;     //���뵥�ʺ�����ִ���
public:
	Wordsearch();
	~Wordsearch();
	void Inputword();             //��������
	bool Wordtotxt(ofstream& os); //�����´���txt�ļ�
	void Countword();             //���㵥�ʳ��ִ���
	void Lowtheword();            //�ѵ����еĴ�д��Сд
	void Removepunctuation();     //ȥ�����
	int Search(string str);       //���ҵ���
	void Txttocmd();              //�������
};
