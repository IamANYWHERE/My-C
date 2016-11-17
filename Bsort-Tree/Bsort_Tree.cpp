#include"Bsort_Tree.h"

Leaf*& Bsort_Tree::compare(Leaf*& leaf,const int& x) {
	//与树中的元素比较大小，返回此值应该在的位置
	if (leaf == NULL)
	{
		return leaf;
	}
	else
	{
		if (x < leaf->digit)
		{
			return compare(leaf->left, x);
		}
		else if (x == leaf->digit)
		{
			return leaf;
		}
		else if(x > leaf->digit)
		{
			return compare(leaf->right, x);
		}
	}
}

bool Bsort_Tree::Createtree() {
	//创建二叉排序树
	int x = 0;
	vector<int> vec;
	cout << "Please input key to create Bsort_Tree:"<<endl;
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		vec.push_back(x); //先将元素存储在vector中
	}
	if (cin.fail()) {
		cin.clear();
		string str;
		cin >> str;
		return false;
	}
	if (vec.size() == 0)
		return false;
	for (int i = 0; i < vec.size(); i++)  //将元素添加到树中
	{
		Leaf* &leaf=compare(_First, vec[i]);
		if (leaf == NULL)
		{
			leaf = new Leaf;
			if (leaf == NULL)
				return false;
			leaf->digit = vec[i];
			leaf->left = NULL;
			leaf->right = NULL;
		}
		else
		{
			cout << "The input key(" << vec[i] << ")is have in!" << endl;
		}
	}
	return true;
}

bool Bsort_Tree::Insert(const int& x) {
	//插入元素
	Leaf* &leaf = compare(_First, x);
	if (leaf == NULL)
	{
		leaf = new Leaf;
		if (leaf == NULL)
			return false;
		leaf->digit = x;
		leaf->left = NULL;
		leaf->right = NULL;
	}
	else
	{
		cout << "The input key(" << x << ")is have in!" << endl;
		return false;
	}
	return true;
}

bool Bsort_Tree::Search(const int& x) {
	//查找元素
	Leaf* &leaf = compare(_First, x);
	if (leaf == NULL)
		return false;
	else
		return true;
}

void Bsort_Tree::show(Leaf* leaf) {
	//输出二叉排序树递归方法
	if (leaf->left != NULL)
	{
		show(leaf->left);
	}
	cout << leaf->digit << "->";
	if (leaf->right != NULL)
	{
		show(leaf->right);
	}
}
void Bsort_Tree::ShowTree() {
	//调用输出二叉排序
	if (_First != NULL)
	{
		show(_First);
	}
	else
		cout << "Bsort_Tree is empty!" << endl;
}
bool Bsort_Tree::Isempty()
{
	//是否为空
	if (_First == NULL)
		return true;
	else
		return false;
}