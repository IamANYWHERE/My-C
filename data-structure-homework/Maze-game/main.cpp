#include"Maze.h"

int main(void) {
	cout << "������һ������Ϊn�Թ���#Ϊǽ�ڣ�0Ϊͨ·��" << endl;
	cout << "����ʱ�뽫��1��1����Ϊ��ڣ���n-1,n-1����Ϊ���ڣ�" << endl;
	cout << "�������Թ��Ĵ�Сn:";
	int n = 0;
	cin >> n;
	Maze maze;
	cout << "�Թ���ǽ��#��ʾ��ͨ·��0��ʾ��������\n��ͼֻ��#��0��ɣ�û�пո񣡣�" << endl;
	cout << "�Թ���Ȧ������Χǽ������" << endl;
	cout << "�����Թ���" << endl;
	if (!maze.CreateMaze(n))     //�����Թ��������
	{
		cout << "�Բ����Թ�������Ҫ�󣡣�" << endl;
		return 0;
	}
	if (!maze.FindPath())       //�Ҳ���·������
	{
		cout << "�Բ��������Թ�û��ͨ·������ڣ���" << endl;
		return 0;
	}
	maze.Show();
	return 0;
}