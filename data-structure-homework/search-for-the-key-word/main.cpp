#include"Wordsearch.h"

int main(void) {
	Wordsearch wordsearch;                 //��������������
	cout << "�ؼ��ּ���ϵͳ" << endl;
	cout << "�������ļ�����";

	string str;                            
	cin >> str;                            //�����ļ���
	cout << "������һ��Ӣ�ģ�" << endl;
	wordsearch.Inputword();                //��������
	ofstream os(str);                      //���ļ�
	wordsearch.Wordtotxt(os);              //����������ļ�
	cout << "�����ı��ѱ������ı��ļ���" << str << "���С�" << endl;
	wordsearch.Removepunctuation();        //ȥ�����±��
	wordsearch.Lowtheword();               //��ѧ��Сд
	wordsearch.Countword();                //���㵥�ʳ��ִ���

	cout << endl;
	cout << "������Ҫ�����Ĺؼ��֣�";
	string key=" ";
	cin >> key;                            //����ؼ����ʽ���������ִ���
	cout << "��ʾԴ�ļ���" << str << "����" << endl;  //����ļ���
	cout << endl;
	
	wordsearch.Txttocmd();                 //�������

	cout << endl;                         
	cout << "��Դ�ļ��й���������" << wordsearch.Search(key) << "���ؼ��֡�" << key << "��"<<endl;
	return 0;
}