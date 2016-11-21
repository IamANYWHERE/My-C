#include"Chessboard.h"



void Chessboard::Backtracking(int x,int y) {
	//��n�ʺ�İڷ�
	//�ڷ��ǹ����м�ԳƵ�
	//�ҵ�һ��ʱ����ֻ��Ҫ��һ�������
	int n = _nqueen / 2;
	if (n * 2 < _nqueen)
	{
		odd = true;      //Ϊ�������ʺ�
		n += 1;
	}
	if (x >= 0 && x <= _nqueen&&y >= 0 && y < _nqueen)
	{
		if (x == _nqueen)
		{
			if (odd == true&&mid==true)   //Ϊ�������ʺ��ҵ�һ�Ű����м�ʱ���ڷ���ֻ��һ��
			{
				_count += 1;
				Showboard();
			}
			else{                         //����Ӷ���
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
	//����n�ʺ�Ĵ洢��
	//����n�ʺ�ʱ������������
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
			//��ʼ��n�ʺ�����
			chs[j] = '0';
		}
		_graph.push_back(chs);
	}
	return true;
}

int Chessboard::Count() {
	//����ܰڷ���
	return _count;
}

void Chessboard::Showboard() {
	//���n�ʺ�ڷ�
	//n�ʺ�ڷ����м�Գ�
	//������ֻ��Ҫ�ҵ�һ�ŵ�һ�������
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
	if (mid == false)//�������ʺ�ʱ������һ���м�Ϊ�ʺ�ʱ�����������
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
