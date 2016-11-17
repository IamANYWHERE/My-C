#include"Wordsearch.h"

Wordsearch::Wordsearch() {

}
Wordsearch::~Wordsearch() {

}
void Wordsearch::Inputword() {
	//输入文章，将其保存
	//用Ctrl+z结束循环
	string str;
	while (cin>>str)
	{
		_vec.push_back(str);
		_first.push_back(str);
	}
	cin.clear();
}

bool Wordsearch::Wordtotxt(ofstream& os) {
	//把文章输入到txt文章
	if (!os)
		return false;
	string str;
	for (int i = 0; i < _vec.size(); i++)
	{
		os << _vec[i] << " ";
		if (i % 15 == 14)
			cout << endl;
	}
	return true;
}

void Wordsearch::Countword() {
	//计算单词个数
	for (int i = 0; i < _vec.size(); i++)
	{
		_map[_vec[i]] += 1;
	}
}
void Wordsearch::Removepunctuation() {
	//移除标点
	for (int i = 0; i < _vec.size(); i++)
	{
		int j = _vec[i].size() - 1;
		if (!((_vec[i][j] >= 'a'&&_vec[i][j] <= 'z') || (_vec[i][j] >= 'A'&&_vec[i][j] <= 'Z')))
		{
			_vec[i].erase(_vec[i].size()-1 );
		}
	}

}
void Wordsearch::Lowtheword() {
	//把大写字母变小写
	for (int i = 0; i < _vec.size(); i++)
	{
		if (_vec[i][0] <= 'Z')
			_vec[i][0] += ' ';
	}
}
int Wordsearch::Search(string str) {
	//查找单词并返回其出现次数
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] <= 'Z')
			str[i] += ' ';
	}
	if (_map.find(str) != _map.end())
		return _map[str];
	else
		return 0;
}
void Wordsearch::Txttocmd()
{
	//输出文章
	for (int i = 0; i < _first.size(); i++)
	{
		cout << _first[i] << " ";
		if (i % 15 == 14)
			cout << endl;
	}
	cout << endl;
}
