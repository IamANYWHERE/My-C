#include"Prim.h"

void Prim::Creategraph(const int&x) {
	//�����洢�߳�����Ϣ�ľ���
	//
	int* arr;
	for (int i = 0; i < x; i++)
	{
		arr = new int[x];
		_graph.push_back(arr);
		_lowcost.push_back(-2);
		_mst.push_back(-2);
		for (int j = 0; j < x; j++)
		{
			_graph[i][j] = MAX;
		}
	}
}
void Prim::Inputname(const int& x) {
	//���붥�������
	string str;
	for (int i = 0; i < x; i++)
	{
		cin >> str;
		_name.push_back(str);
	}
}

void Prim::Inputlength(const string& name1,const string& name2,const int& length) {
	//������֮�������
	_graph[nametonum(name1)][nametonum(name2)] = length;
	_graph[nametonum(name2)][nametonum(name1)] = length;
}
void Prim::Createprim(const string&name	) {
	//������С������
	int min, minid;
	int firstid = nametonum(name);           //��С��������ʼ���id
	int size = _mst.size();
	for (int i = 0; i < size; i++)
	{
		//�㵽�Լ�����Ϊ0
		_graph[i][i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		//������firstid����ĵ�
		_lowcost[i] = _graph[firstid][i];
		//�ȼٶ�����㶼��firstid����
		_mst[i] =firstid;
	}
	_mst[firstid] = -1;
	_prim.push_back(firstid);
	for (int i = 0; i < size; i++)
	{
		min = MAX;
		minid = -1;
		//�õ���firstid�����С���ȵĵ�
		for (int j = 0; j < size; j++)
		{
			if (_lowcost[j] < min&&_lowcost[j] != 0)
			{
				min = _lowcost[j];
				minid = j;
			}
		}

		if (minid != -1)
		{
			//��minid����뵽��С��������
			_lowcost[minid] = 0;
			_prim.push_back(minid);
			for (int y = 0; y < size; y++)
			{
				if (_graph[minid][y] < _lowcost[y])
				{
					_lowcost[y] = _graph[minid][y];
					_mst[y] = minid;
				}
			}
		}
	}
}
void Prim::Showprim(const string& name) {
	//�����name��ʼ�ĵ����С������
	int firstid = nametonum(name);
	show(firstid);
}
void Prim::show(const int& x) {
	//�����С������
	for (int i = 0; i < _mst.size(); i++)
	{
		if (_mst[i] == x)
		{
			cout << _name[x] << "-(" << _graph[x][i] << ")-" << _name[i]<<endl;
			show(i);
		}
	}
}

int Prim::nametonum(const string& name){
	//���ص����ı��
	for (int i = 0; i < _name.size(); i++)
	{
		if (name == _name[i])
		{
			return i;
		}
	}
}
bool Prim::Check() {
	//�鿴�Ƿ��й�����
	bool judge;
	for (int i = 0; i < _graph.size(); i++)
	{
		judge = false;
		for (int j = 0; j < _graph.size(); j++)
		{
			if (_graph[i][j] < MAX) {
				judge = true;
			}
		}
	}
	return judge;
}
void Prim::Reset() {
	//�����ڲ����ݣ��Ա�������¿�ʼ
	if (!_graph.empty())
	{
		for (int i = 0; i<_graph.size(); i++)
		{
			delete _graph[i];
		}
		_graph.clear();
	}
	if (!_lowcost.empty())
	{
		_lowcost.clear();
	}
	if (!_mst.empty())
	{
		_mst.clear();
	}
	if (_name.empty())
	{
		_name.clear();
	}
}