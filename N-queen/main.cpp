#include"Chessboard.h"

int main(void) {
	//皇后个数代表棋盘大小
	cout << "现有NxN的棋盘，放入N个皇后，要求所有皇后不再同一行，列和同一斜线上！" << endl;
	cout << endl;
	cout << "请输入皇后的个数：";
	int x=0;
	cin >> x;                        //输入皇后个数
	cout << endl;
	cout << "皇后摆法：" << endl;    
	cout << endl;
	Chessboard chess;                //创建棋的对象
	chess.Createboard(x);            //创建棋盘
	chess.Backtracking(0, 0);        //找摆法
	cout << "共有" << chess.Count() << "种解法！";
	return 0;
}