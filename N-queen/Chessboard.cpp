#include"Chessboard.h"



void Chessboard::Backtracking(int x,int y) {
	//找n皇后的摆法
	//摆法是关于中间对称的
	//找第一排时，我只需要找一半就行了
	int n = _nqueen / 2;
	if (n * 2 < _nqueen)
	{
		odd = true;      //为奇数个皇后
		n += 1;
	}
	if (x >= 0 && x <= _nqueen&&y >= 0 && y < _nqueen)
	{
		if (x == _nqueen)
		{
			if (odd == true&&mid==true)   //为奇数个皇后，且第一排摆在中间时，摆法数只加一。
			{
				_count += 1;
				Showboard();
			}
			else{                         //否则加二。
				_count += 2;
				Showboard();
			}
		}
		else
		{
			for (; y < _nqueen; y++)
			{
				if (x != 0)
				{
					int n=x-1, m=y-1;
					bool jugle = true;
					if (jugle == true)
					{
						while (n >= 0 && m >= 0)
						{
							if (_graph[n][m] == 'x')
							{
								jugle = false;
								break;
							}
							n -= 1;
							m -=1;
						}
					}
					m = y;
					n = x - 1;
					if (jugle == true)
					{
						while (n >= 0)
						{
							if (_graph[n][m] == 'x')
							{
								jugle = false;
								break;
							}
							n -=1;
						}
					}
					n = x - 1;
					m = y + 1;
					if (jugle == true)
					{
						while (n >= 0 && m < _nqueen)
						{
							if (_graph[n][m] == 'x')
							{
								jugle = false;
								break;
							}
							n-=1;
							m +=1;
						}
					}
					if (jugle == true)
					{
						for (int i = 0; i < _nqueen; i++)
						{
							_graph[x][i] = '0';
						}
						_graph[x][y] = 'x';
						Backtracking(x + 1, 0);
					}
				}
				else
				{
					if (y < n)
					{
						if (odd == true)
							if (y == n - 1)
								mid = true;
						for (int i = 0; i < n; i++)
						{
							_graph[x][i] = '0';
						}
						_graph[x][y] = 'x';
						Backtracking(x + 1, 0);
					}
					else
						break;
				}
			}
		}
	}
}

bool Chessboard::Createboard(const int& x){
	//创建n皇后的存储器
	//计算n皇后时用它来当容器
	if (x <= 0)
		return false;
	_nqueen = x;
	char* chs;
	for (int i = 0; i < x; i++)
	{
		chs = new char[x];
		if (!chs)
			return false;
		for (int j = 0; j < x; j++)
		{
			//初始化n皇后棋盘
			chs[j] = '0';
		}
		_graph.push_back(chs);
	}
	return true;
}

int Chessboard::Count() {
	//输出总摆法数
	return _count;
}

void Chessboard::Showboard() {
	//输出n皇后摆法
	//n皇后摆法是中间对称
	//所以我只需要找第一排的一半就行了
	for (int i = 0; i < _nqueen; i++)
	{
		for (int j = 0; j < _nqueen; j++)
		{
			cout << _graph[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	if (mid == false)//奇数个皇后时，当第一排中间为皇后时，不反向输出
	{
		for (int i = 0; i < _nqueen; i++)
		{
			for (int j = _nqueen - 1; j >= 0; j--)
			{
				cout << _graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
}
