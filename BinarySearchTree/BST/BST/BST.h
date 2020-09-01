#pragma once
#include <iostream>

// ���ݡ��㷨4���Լ�ʵ�ֵĶ���������
// ʹ����ģ��ȼ���������������һ��������ʯͷ��
// �漰���������ʵ�֣�������ɾ��ġ���Сֵ���ڵ�����������
// ������������õĳ���ͱ������ⲿ�ӿ�ͨ������private����ʵ�ֹ���
// ����ʵ�ֶ�ͨ���ݹ飬�ǳ�������
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
