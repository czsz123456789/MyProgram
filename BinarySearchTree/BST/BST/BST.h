#pragma once
#include <iostream>

// 根据《算法4》自己实现的二叉搜索树
// 使用了模板等技术，并不熟练，一步步摸着石头走
// 涉及多个函数的实现，包括增删查改、最小值、节点数、排名等
// 代码进行了良好的抽象和保护，外部接口通过调用private函数实现功能
// 所有实现都通过递归，非常精妙简洁
template<class KEY, class VALUE>
struct Node
{
	KEY key;
	VALUE val;
	Node *left;
	Node *right;
	int count;
	Node(KEY k, VALUE v,int n) :key(k), val(v), left(nullptr), right(nullptr),count(n) {}
};

template<class KEY, class VALUE>
class MyBST
{
private:
	Node<KEY,VALUE> *root;
	int size(Node<KEY, VALUE> *node);
	VALUE get(Node<KEY, VALUE> *node, KEY key);
	Node<KEY, VALUE>* put(Node<KEY, VALUE> *node, KEY key, VALUE val);
	Node<KEY, VALUE>* deleteMin(Node<KEY, VALUE>* node);
	Node<KEY, VALUE>* min(Node<KEY, VALUE>*node);
	Node<KEY, VALUE>* del(Node<KEY, VALUE> *node, KEY key);
	Node<KEY, VALUE>* select(Node<KEY, VALUE> *node, int k);
	void travel(Node<KEY, VALUE>* node);
public:
	MyBST(){root = nullptr;}
	~MyBST(){}
	void DeleteAll(Node<KEY, VALUE>* node);
	int size();
	VALUE get(KEY key);
	void put(KEY key, VALUE val);
	void deleteMin();
	KEY min();
	void del(KEY key);
	KEY select(int k); 
	void travel();
};
