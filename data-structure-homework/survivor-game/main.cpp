#include"Game.h"

int main(void) {
	cout << "������N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ" << endl;
	cout << endl;
	Game game;
	bool jugle=false;
	while (jugle == false)
	{
		//������Ϸ���ݣ�������ݴ���ϵͳ����Ҫ���������
		jugle = game.Inputgamedata();
		if(jugle==false)
			cout << "�����������ݣ���" << endl;
	}

	jugle=game.Createcircle();
	if (jugle == false)
	{
		//�����ϷȦ����ʧ�ܣ����ش���
		cout << "��Ϸ����ʧ�ܣ�����" << endl;
		return 0;
	}
	cout << endl;
	jugle=game.Outperson();
	if (jugle == false)
	{
		//�����̭�˷������󣬷��ش���
		cout << "��Ϸ����ʱ�������󣡣�" << endl;
		return 0;
	}
	cout << endl;
	jugle=game.Showsurvivor();
	if (jugle == false)//����������ʧ�ܣ����ش���
		cout << "�Ҵ���λ������ʧ�ܣ�����" << endl;
	return 0;
}