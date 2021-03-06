// BST.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "BST.h"
// 删除整个树
template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::DeleteAll(Node<KEY, VALUE>* node)
{
	if (node == nullptr)
		return;
	auto left = node->left;
	auto right = node->right;
	delete node;
	DeleteAll(left);
	DeleteAll(right);
}

// 求以node为根节点的子树总共的节点数量
template<class KEY,class VALUE>
inline int MyBST<KEY, VALUE>::size(Node<KEY, VALUE> *node)
{
	if (node == nullptr)
		return 0;
	return node->count;
}

// 求整个数的节点数量
template<class KEY, class VALUE>
inline int MyBST<KEY, VALUE>::size()
{
	return size(root);
}

// 求key节点的值
template<class KEY, class VALUE>
VALUE MyBST<KEY, VALUE>::get(KEY key)
{
	return get(root, key);
}

// 求以node为根节点的子树中key节点的值
template<class KEY, class VALUE>
VALUE MyBST<KEY, VALUE>::get(Node<KEY, VALUE> * node, KEY key)
{
	if (node == nullptr)
		return VALUE();
	if (key < node->key)
		return get(node->left, key);
	else if (key > node->key)
		return get(node->right, key);
	else
		return node->val;
}

// 将新节点插入到树中
template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::put(KEY key, VALUE val)
{
	root = put(root, key, val);
}

// 将新节点插入到以node为根节点的子树中
template<class KEY, class VALUE>
Node<KEY,VALUE>* MyBST<KEY, VALUE>::put(Node<KEY, VALUE> * node, KEY key, VALUE val)
{
	if (node == nullptr)
		return new Node<KEY, VALUE>(key, val,1);
	if (node->key > key)
		node->left = put(node->left, key, val);
	else if (node->key < key)
		node->right = put(node->right, key, val);
	else // key已经存在时更新val值
		node->val = val;
	node->count = size(node->left) + size(node->right) + 1;
	return node;
}

// 求树中子最小key
template<class KEY, class VALUE>
KEY MyBST<KEY, VALUE>::min()
{
	return min(root)->key;
}

// 求以node为根节点的子树中最小节点
template<class KEY, class VALUE>
Node<KEY, VALUE>* MyBST<KEY, VALUE>::min(Node<KEY, VALUE>* node)
{
	if(node == nullptr)
		return nullptr;
	// 一直向左找 找到最左的节点
	if (node->left == nullptr)
		return node;
	return min(node->left);
}

// 删除树中最小节点
template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::deleteMin()
{
	root = deleteMin(root);
}

// 删除以node为根节点的子树中最小节点
// 返回值为当前节点
template<class KEY,class VALUE> 
Node<KEY, VALUE>* MyBST<KEY, VALUE>::deleteMin(Node<KEY, VALUE> *node)
{
	if (node->left == nullptr)
	{
		auto temp = node->right;
		delete node;
		return temp;
	}
	node->left = deleteMin(node->left);
	node->count = size(node->left) + size(node->right) + 1;
	return node;
}

// 删除目标节点
template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::del(KEY key)
{
	root = del(root, key);
}

// 在以根节点为node的子树中删除key节点
// 返回值是当前节点
template<class KEY, class VALUE>
Node<KEY, VALUE>* MyBST<KEY, VALUE>::del(Node<KEY, VALUE>* node, KEY key)
{
	if (node == nullptr)
		return nullptr;
	if (node->key < key)
		node->left = del(node->left, key);
	else if (node->key > key)
		node->right = del(node->right, key);
	else // 删除当前节点
	{
		// 如果只有一边子树
		if (node->left == nullptr)
			return node->right;
		if (node->right == nullptr)
			return node->left;
		// 如果左右子树都有
		// 用当前节点右子树最小的节点替代被删除的节点
		auto maxnode = min(node);
		node->key = maxnode->key;
		node->val = maxnode->key;
		node->right = deleteMin(node->right);
	}
	node->count = size(node->left) + size(node->right) + 1;
	return node;
}

// 查找排名为k的节点
template<class KEY, class VALUE>
KEY MyBST<KEY, VALUE>::select(int k)
{
	auto tt = select(root, k);
	if (tt)
		return tt->key;
	return KEY(-1); // 找不到排名为k的节点
}

// 在根节点为node的子树中查找排名为k的节点
template<class KEY, class VALUE>
Node<KEY, VALUE>* MyBST<KEY, VALUE>::select(Node<KEY, VALUE>* node, int k)
{
	if (node == nullptr)
		return nullptr;
	
	if (k > node->count || k < 1)
		return nullptr;
	
	int t = size(node->left);
	if (t < k - 1)
		return select(node->right, k - t - 1);
	else if (t > k - 1)
		return select(node->left, k);
	else
		return node;
}

template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::travel()
{
	travel(root);
}

template<class KEY, class VALUE>
void MyBST<KEY, VALUE>::travel(Node<KEY, VALUE>* node)
{
	if (node == nullptr)
		return;
	travel(node->left);
	std::cout << node->val << std::endl;
	travel(node->right);
}