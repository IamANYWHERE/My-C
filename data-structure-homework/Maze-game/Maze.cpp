#include"Maze.h"

Maze::Maze() :_judge(false) {

}
Maze::~Maze() {
	//程序结束时调用析构函数清除构造的空间
	for (int i = _map.size()-1; i>=0; i--)
	{
		delete _mark[i];
		_mark.pop_back();
	}
	int size = _path.size();
	for (int i = size - 1; i >= 0; i--)
	{
		delete _path[i];
		_path.pop_back();
	}
}
bool Maze::CreateMaze(const int& y,const int&x) {           //mapSzie迷宫大小
	//建立迷宫
	int* digit = NULL;
	string str;                      
	for(int i=0;i<y;i++)  //录入迷宫
	{
		cin >> str;
		if (str.size() != x)     //每行大小要等于mapSize
			return false;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '#'&&str[i] != '0')
				return false;
		}
		_map.push_back(str);
		str.clear();
		digit = new int[x];      
		if (digit == NULL)
			return false;
		for (int j = 0; j < x; j++)    //给标志矩阵全部初始化为0
			digit[j] = 0;
		_mark.push_back(digit);
		digit = NULL;
	}
	
	return true;
}

bool Maze::FindPath(int const&inx,int const& iny,int const& outx,int const& outy) {
	//找迷宫路径
	Find(inx-1,iny-1,outx-1,outy-1);
	if (_judge != true)
		return false;
	return true;
}
void Maze::Find(int x, int y,int const& outx,int const& outy) {
	//递归找迷宫路径
	int sizey = _map[0].size();//迷宫长
	int sizex = _map.size();   //迷宫列长
	int* num = new int[2];
	num[0] = x;                
	num[1] = y;
	_path.push_back(num);           //记录路径
	_mark[x][y] = 1;                //标记已经走过的地方
	if (x == outx&&y == outy)             //递归结束条件
	{
		_judge = true;
		return;
	}
	if (_judge != true&& x-1>=0 &&_map[x - 1][y] != '#'&&_mark[x - 1][y] != 1)   //向上
	{
		
		Find(x -1, y,outx,outy);
	}
	if (_judge != true&& y+1<=sizey-1 &&_map[x][y + 1] != '#'&&_mark[x][y+1] != 1 )    //向右
	{
		Find(x,y + 1, outx, outy);
	}
	if (_judge != true&& x+1<=sizex-1 &&_map[x + 1][y] != '#'&&_mark[x +1][y] != 1)  //向下
	{
		Find(x + 1, y, outx, outy);
	}
	if (_judge != true&& y-1>=0 &&_map[x][y - 1] != '#'&&_mark[x][y-1] != 1)   //向左
	{
		Find(x, y - 1, outx, outy);
	}
	if (_judge != true)
	{
		delete _path.back();
		_path.pop_back();
	}
}

void Maze::Show() {
	//输出带有路径的迷宫
	for (int i = 0; i < _path.size(); i++)
	{
		_map[_path[i][0]][_path[i][1]]='x';    //标志路径
	}

	cout << "迷宫地图：" << endl;
	cout << endl;
	int size = _map[0].size();
	cout << "     ";
	for (int i = 0; i < size; i++)
	{
		cout << i << "列" << "   ";
	}
	cout << endl;
	cout << endl;
	int row = _map.size();
	for (int i = 0; i < row; i++)
	{
		cout << i << "行   ";
		for (int j = 0; j < size; j++)
		{
			cout << _map[i][j] << "     ";
		}
		cout << endl;
		cout << endl;
	}
	cout << "迷宫路径：" << endl;
	for (int i = 0; i < _path.size(); i++)
	{
		cout << "(" << _path[i][0] << "," << _path[i][1] << ")";
		if (i != _path.size() - 1)
			cout << " ---> ";
	}
}