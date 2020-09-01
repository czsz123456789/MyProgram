#include "stdafx.h"
#include "BST.hpp"
using namespace std;

int main()
{
	MyBST<int, int> a;
	a.put(3, 5);
	a.put(1, 2);
	a.put(8, 99);
	//a.travel();
	//cout << a.size() << endl;
	cout << a.select(3) << endl;
	//cout << a.min() << endl;

	system("pause");
}