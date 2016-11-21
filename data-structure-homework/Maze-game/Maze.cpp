#include"Maze.h"

Maze::Maze() :_judge(false) {

}
Maze::~Maze() {
	//�������ʱ�������������������Ŀռ�
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
bool Maze::CreateMaze(const int& mapSize) {           //mapSzie�Թ���С
	//�����Թ�
	int* digit = NULL;
	string str;                      
	for(int i=0;i<mapSize;i++)  //¼���Թ�
	{
		cin >> str;
		if (str.size() != mapSize)     //ÿ�д�СҪ����mapSize
			return false;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '#'&&str[i] != '0')
				return false;
		}
		_map.push_back(str);
		str.clear();
		digit = new int[mapSize];      
		if (digit == NULL)
			return false;
		for (int j = 0; j < mapSize; j++)    //����־����ȫ����ʼ��Ϊ0
			digit[j] = 0;
		_mark.push_back(digit);
		digit = NULL;
	}
	
	return true;
}

bool Maze::FindPath() {
	//���Թ�·��
	Find(1, 1);
	if (_judge != true)
		return false;
	return true;
}
void Maze::Find(int x, int y) {
	//�ݹ����Թ�·��
	int size = _map[0].size();      //�Թ���
	int m = size - 2;               //�����Թ����ڵ��±�
	int* num = new int[2];
	num[0] = x;                
	num[1] = y;
	_path.push_back(num);           //��¼·��
	_mark[x][y] = 1;                //����Ѿ��߹��ĵط�
	if (x == m&&y == m)             //�ݹ��������
	{
		_judge = true;
		return;
	}
	if (_judge != true&&_map[x - 1][y] != '#'&&_mark[x - 1][y] != 1)   //����
	{
		
		Find(x -1, y);
	}
	if (_judge != true&&_map[x][y + 1] != '#'&&_mark[x][y+1] != 1 )    //����
	{
		Find(x,y + 1);
	}
	if (_judge != true &&_map[x + 1][y] != '#'&&_mark[x +1][y] != 1)  //����
	{
		Find(x + 1, y);
	}
	if (_judge != true &&_map[x][y - 1] != '#'&&_mark[x][y-1] != 1)   //����
	{
		Find(x, y - 1);
	}
	if (_judge != true)
	{
		delete _path.back();
		_path.pop_back();
	}
}

void Maze::Show() {
	//�������·�����Թ�
	for (int i = 0; i < _path.size(); i++)
	{
		_map[_path[i][0]][_path[i][1]]='x';    //��־·��
	}

	cout << "�Թ���ͼ��" << endl;
	cout << endl;
	int size = _map[0].size();
	cout << "     ";
	for (int i = 0; i < size; i++)
	{
		cout << i << "��" << "   ";
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << "��   ";
		for (int j = 0; j < size; j++)
		{
			cout << _map[i][j] << "     ";
		}
		cout << endl;
		cout << endl;
	}
	cout << "�Թ�·����" << endl;
	for (int i = 0; i < _path.size(); i++)
	{
		cout << "(" << _path[i][0] << "," << _path[i][1] << ")";
		if (i != _path.size() - 1)
			cout << " ---> ";
	}
}