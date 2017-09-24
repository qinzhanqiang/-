#pragma once

template<typename Key,typename Value>
class binarySearchTree
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
	};

	Node *root;
	int count;

public:
	binarySearchTree() {
		root = NULL;
		count = 0;
	};
	~binarySearchTree() {
	
	};

	int size() {
		return count;
	}

	int isEmpty() {
		return count == 0;
	}

	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}
	
	bool contain(Key key) {
		return contain(root, key);
	}

	Value* search(Key key) {
		return search(root, key);
	}

private:
	//向以node为根的二叉搜索树中插入节点（key,value），返回插入后二叉树的根.
	Node* insert(Node* node, Key key, Value value) {
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}
		
		if (key == node->key)
		{
			node->value = value;
		}
		else if (key < node->key)
		{
			node->left = insert(node->left, key, value);
		}
		else 
		{
			node->right = insert(node->right, key, value);
		}

		return node; 
	}
	//向以node为根的二叉搜索树中判断是否包含key
	bool contain(Node* node, Key key) {
		if (node == NULL)
		{
			return false;
		}
		if (node->key == key)
		{
			return true;
		}
		else if (key < node->key)
		{
			return contain(node->left, key);
		}
		else {
			return contain(node->right, key);
		}
	}
	//向以node为根的二叉搜索树中搜索key对应的value值
	Value* search(Node* node, Key key) {
		if (node == NULL)
		{
			return NULL;
		}
		if (node->key == key)
		{
			return &(node->value);
		}
		else if (key < node->key)
		{
			return search(node->left, key);
		}
		else {
			return search(node->right, key);
		}
	}
};

