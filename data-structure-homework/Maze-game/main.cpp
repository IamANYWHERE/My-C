#include"Maze.h"

int main(void) {
	cout << "������һ��y��x�е��Թ���#Ϊǽ�ڣ�0Ϊͨ·��" << endl;
	cout << "����ʱ�뽫��ڳ��ڷ����������ǽ�ϣ�" << endl;
	cout << "�������Թ��Ĵ�С������:";
	int y = 0, x = 0;
	cin >> y >> x;
	Maze maze;
	cout << "�Թ���ǽ��#��ʾ��ͨ·��0��ʾ��������\n��ͼֻ��#��0��ɣ�û�пո񣡣�" << endl;
	cout << "�Թ���Ȧ������Χǽ����ڳ��ڣ�����" << endl;
	cout << "���磺��һ�ŵ�һ������ڣ����� 1 1 " << endl;
	cout << "�����Թ���" << endl;
	if (!maze.CreateMaze(y,x))     //�����Թ��������
	{
		cout << "�Բ����Թ�������Ҫ�󣡣�" << endl;
		return 0;
	}
	int inx = 0, iny = 0;
	int outx = 0, outy = 0;
	cout << "��������ںͳ��ڵ�λ�ã�" << endl;
	cout << "��ڣ�";
	cin >> inx >> iny;
	cout << "���ڣ�";
	cin >> outx >> outy;
	if (!maze.FindPath(inx,iny,outx,outy))       //�Ҳ���·������
	{
		cout << "�Բ��������Թ�û��ͨ·������ڣ���" << endl;
		return 0;
	}
	maze.Show();
	return 0;
}