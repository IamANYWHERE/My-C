#include"WinnerTree.h"
bool WinnerTree::Initial(int a[], int size) {
	//初始化胜者树
	if (size<=1)return false;
	n = size;   //数组大小
	e = a;      //数据
	int i, s;   //s最远层最左端内部节点的编号
	for (s = 1; 2 * s <= n - 1; s += s);
	lowExt = 2 * (n - s);
	offset = s * 2 - 1;
	for (i = 2; i <= lowExt; i += 2)
	{
		Play((i + offset) / 2, i - 1, i);
	}
	if (n % 2 == 0)i = lowExt + 2;
	else {
		Play((n-1) / 2, t[n-1], lowExt + 1);
		i = lowExt + 3;
	}
	for (; i <= n; i += 2) {
		Play((i - lowExt + n - 1) / 2, i - 1, i);
	}
	return true;
}
void WinnerTree::Play(int k, int lc, int rc) {
	//比赛，决出胜者
	t[k] = Winner(lc, rc);
	number += 1;
	while (k > 1 && k % 2 != 0) {
		number += 1;
		t[k / 2] = Winner(t[k - 1], t[k]);
		k /= 2;
	}
}

bool WinnerTree::rePlay() {
	//重新比赛，决出次胜者
	int i = t[1];
	if (i <= 0 || i > n)return false;
	int k, lc, rc;
	if (i <= lowExt) {
		k = (offset + i) / 2;
		lc = 2 * k - offset;
		rc = lc + 1;
	}
	else {
		k = (i - lowExt + n - 1) / 2;
		if (k * 2 == n - 1) 
		{
			lc = t[k * 2];
			rc = i;
		}
		else { 
			lc = 2 * k + lowExt + 1 - n; 
			rc = lc + 1; 
		}
	}
	t[k] = Winner(lc, rc);
	number += 1;
	for (k /= 2; k >= 1; k /= 2) {
		number += 1;
		if (k * 2 == n - 1) {
			t[k] = Winner(t[k * 2], lowExt + 1);
		}
		else
			t[k] = Winner(t[k * 2], t[k * 2 + 1]);
	}
}