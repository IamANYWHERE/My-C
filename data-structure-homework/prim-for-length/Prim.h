#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cctype>
using namespace std;
#define MAX 0x7ffffff   //���������󳤶�
class Prim {
	//��������û��
private:
	vector<int*> _graph;                 //��¼��������ĳ���
	vector<int> _lowcost;                //��¼���Ѿ�������С�������ĵ�������̵ĵ�
	vector<int> _mst;                    //��¼�����ĸ�������
	vector<string> _name;                //��¼�������
	int nametonum(const string& name);   //�����ı��
	vector<int> _prim;                   //��¼�ѽ�����С�������ĵ�
	void show(const int& x);             //�����С������
public:
	void Creategraph(const int& x);      //��������
	void Inputname(const int& x);        //����������
	void Inputlength(const string&name1,const string&name2,const int& length);//��������֮��ľ���
	void Createprim(const string& name); //������С������
	void Showprim(const string & name);  //�����С������
	bool Check();                        //����Ƿ��й�����
	void Reset();                        //�����ڲ������Ա����¿�ʼ

};
