#include"Bsort_Tree.h"

Leaf*& Bsort_Tree::compare(Leaf*& leaf,const int& x) {
	//�����е�Ԫ�رȽϴ�С�����ش�ֵӦ���ڵ�λ��
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
	//��������������
	int x = 0;
	vector<int> vec;
	cout << "Please input key to create Bsort_Tree:"<<endl;
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		vec.push_back(x); //�Ƚ�Ԫ�ش洢��vector��
	}
	if (cin.fail()) {
		cin.clear();
		string str;
		cin >> str;
		return false;
	}
	if (vec.size() == 0)
		return false;
	for (int i = 0; i < vec.size(); i++)  //��Ԫ����ӵ�����
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
	//����Ԫ��
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
	//����Ԫ��
	Leaf* &leaf = compare(_First, x);
	if (leaf == NULL)
		return false;
	else
		return true;
}

void Bsort_Tree::show(Leaf* leaf) {
	//��������������ݹ鷽��
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
	//���������������
	if (_First != NULL)
	{
		show(_First);
	}
	else
		cout << "Bsort_Tree is empty!" << endl;
}
bool Bsort_Tree::Isempty()
{
	//�Ƿ�Ϊ��
	if (_First == NULL)
		return true;
	else
		return false;
}