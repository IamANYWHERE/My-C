#include"Maze.h"

int main(void) {
	cout << "请输入一个长宽为n迷宫，#为墙壁，0为通路。" << endl;
	cout << "输入时请将（1，1）作为入口，（n-1,n-1）作为出口！" << endl;
	cout << "请输入迷宫的大小n:";
	int n = 0;
	cin >> n;
	Maze maze;
	cout << "迷宫的墙用#表示，通路用0表示！！！！\n地图只有#和0组成，没有空格！！" << endl;
	cout << "迷宫外圈必须是围墙！！！" << endl;
	cout << "输入迷宫：" << endl;
	if (!maze.CreateMaze(n))     //输入迷宫错误结束
	{
		cout << "对不起迷宫不符合要求！！" << endl;
		return 0;
	}
	if (!maze.FindPath())       //找不到路径结束
	{
		cout << "对不起您的迷宫没有通路到达出口！！" << endl;
		return 0;
	}
	maze.Show();
	return 0;
}