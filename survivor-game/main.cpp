#include"Game.h"

int main(void) {
	cout << "现在有N人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一个人开始报数，如此循环，直至剩下K个人为止" << endl;
	cout << endl;
	Game game;
	bool jugle=false;
	while (jugle == false)
	{
		//输入游戏数据，如果数据错误，系统将会要求从新输入
		jugle = game.Inputgamedata();
		if(jugle==false)
			cout << "重新输入数据！！" << endl;
	}

	jugle=game.Createcircle();
	if (jugle == false)
	{
		//如果游戏圈创建失败，返回错误
		cout << "游戏建立失败！！！" << endl;
		return 0;
	}
	cout << endl;
	jugle=game.Outperson();
	if (jugle == false)
	{
		//如果淘汰人发生错误，返回错误
		cout << "游戏进行时发生错误！！" << endl;
		return 0;
	}
	cout << endl;
	jugle=game.Showsurvivor();
	if (jugle == false)//如果输出生者失败，返回错误
		cout << "幸存者位置生成失败！！！" << endl;
	return 0;
}