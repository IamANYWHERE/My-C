#include"Chessboard.h"

int main(void) {
	//�ʺ�����������̴�С
	cout << "����NxN�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�У��к�ͬһб���ϣ�" << endl;
	cout << endl;
	cout << "������ʺ�ĸ�����";
	int x=0;
	cin >> x;                        //����ʺ����
	cout << endl;
	cout << "�ʺ�ڷ���" << endl;    
	cout << endl;
	Chessboard chess;                //������Ķ���
	chess.Createboard(x);            //��������
	chess.Backtracking(0, 0);        //�Ұڷ�
	cout << "����" << chess.Count() << "�ֽⷨ��";
	return 0;
}