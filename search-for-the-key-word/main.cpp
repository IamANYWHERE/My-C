#include"Wordsearch.h"

int main(void) {
	Wordsearch wordsearch;                 //创建单词搜索类
	cout << "关键字检索系统" << endl;
	cout << "请输入文件名：";

	string str;                            
	cin >> str;                            //输入文件名
	cout << "请输入一段英文：" << endl;
	wordsearch.Inputword();                //输入文章
	ofstream os(str);                      //绑定文件
	wordsearch.Wordtotxt(os);              //文章输出到文件
	cout << "本段文本已保存在文本文件“" << str << "”中。" << endl;
	wordsearch.Removepunctuation();        //去除文章标点
	wordsearch.Lowtheword();               //大学变小写
	wordsearch.Countword();                //计算单词出现次数

	cout << endl;
	cout << "请输入要检索的关键字：";
	string key=" ";
	cin >> key;                            //输入关键单词进行输出出现次数
	cout << "显示源文件“" << str << "”：" << endl;  //输出文件名
	cout << endl;
	
	wordsearch.Txttocmd();                 //输出文章

	cout << endl;                         
	cout << "在源文件中共检索到：" << wordsearch.Search(key) << "个关键字“" << key << "”"<<endl;
	return 0;
}