#include"Prim.h"

void Prim::Creategraph(const int&x) {
	//创建存储边长度信息的矩阵
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
	//输入顶点的名字
	string str;
	for (int i = 0; i < x; i++)
	{
		cin >> str;
		_name.push_back(str);
	}
}

void Prim::Inputlength(const string& name1,const string& name2,const int& length) {
	//两个点之间的名字
	_graph[nametonum(name1)][nametonum(name2)] = length;
	_graph[nametonum(name2)][nametonum(name1)] = length;
}
void Prim::Createprim(const string&name	) {
	//生成最小生成树
	int min, minid;
	int firstid = nametonum(name);           //最小生成树起始点的id
	int size = _mst.size();
	for (int i = 0; i < size; i++)
	{
		//点到自己长度为0
		_graph[i][i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		//先找离firstid最近的点
		_lowcost[i] = _graph[firstid][i];
		//先假定其余点都与firstid相连
		_mst[i] =firstid;
	}
	_mst[firstid] = -1;
	_prim.push_back(firstid);
	for (int i = 0; i < size; i++)
	{
		min = MAX;
		minid = -1;
		//得到离firstid点的最小长度的点
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
			//将minid点加入到最小生成树中
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
	//输出从name开始的点的最小生成树
	int firstid = nametonum(name);
	show(firstid);
}
void Prim::show(const int& x) {
	//输出最小生成树
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
	//返回点代表的编号
	for (int i = 0; i < _name.size(); i++)
	{
		if (name == _name[i])
		{
			return i;
		}
	}
}
bool Prim::Check() {
	//查看是否有孤立点
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
	//重置内部数据，以便可以重新开始
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