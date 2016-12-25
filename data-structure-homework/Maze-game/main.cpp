#include"Maze.h"

int main(void) {
	cout << "请输入一个y行x列的迷宫，#为墙壁，0为通路。" << endl;
	cout << "输入时请将入口出口放在最外面的墙上！" << endl;
	cout << "请输入迷宫的大小行与列:";
	int y = 0, x = 0;
	cin >> y >> x;
	Maze maze;
	cout << "迷宫的墙用#表示，通路用0表示！！！！\n地图只有#和0组成，没有空格！！" << endl;
	cout << "迷宫外圈必须是围墙和入口出口！！！" << endl;
	cout << "例如：第一排第一个是入口，输入 1 1 " << endl;
	cout << "输入迷宫：" << endl;
	if (!maze.CreateMaze(y,x))     //输入迷宫错误结束
	{
		cout << "对不起迷宫不符合要求！！" << endl;
		return 0;
	}
	int inx = 0, iny = 0;
	int outx = 0, outy = 0;
	cout << "请输入入口和出口的位置！" << endl;
	cout << "入口：";
	cin >> inx >> iny;
	cout << "出口：";
	cin >> outx >> outy;
	if (!maze.FindPath(inx,iny,outx,outy))       //找不到路径结束
	{
		cout << "对不起您的迷宫没有通路到达出口！！" << endl;
		return 0;
	}
	maze.Show();
	return 0;
}