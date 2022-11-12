//通过层序遍历序列构造二叉树,方便做题所以采用层序遍历.因为层序遍历更直观一些

//如果层序遍历，需要删除多余的节点，所以需要添加父节点
#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <exception>
#include <memory>
#include <math.h>

//模板类声明
template <class Elem>
class MyTree;

template <class Elem>
struct TreeNode
{
	friend class MyTree<Elem>;

private:
	TreeNode *parent;
	bool flag = false;

public:
	Elem val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(Elem _val)
	{
		val = _val;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	TreeNode()
	{
		val = -1;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

class TreeError : public std::exception //自己的异常类继承标准库中的异常类
{
public: //父类中为char*类型,把string转换为char*
	TreeError(std::string str) : std::exception()
	{
		std::cout << str << std::endl;
	}
};

template <class Elem>
class MyTree
{
	typedef TreeNode<Elem> Node;

public:
	Node *root;

public:
	MyTree(const std::vector<int> &buff)
	{
		if (buff.empty())
		{
			throw new TreeError("数组大小有误"); //可能由于抛异常导致内存泄漏
		}
		std::queue<Node *> Queue;
		root = new TreeNode<Elem>(buff[0]);
		Queue.push(root);
		for (int i = 0; i < buff.size(); i++)
		{
			Node *node = Queue.front();
			Queue.pop();
			node->val = buff[i];
			node->left = new TreeNode<Elem>();
			node->left->parent = node;
			node->left->flag = false; //父节点的左边
			node->right = new TreeNode<Elem>();
			node->right->parent = node;
			node->right->flag = true;
			Queue.push(node->left);
			Queue.push(node->right);
		}
		while (!Queue.empty())
		{ //删除多创建的节点
			Node *node = Queue.front();
			Queue.pop();
			if (node->flag == true)
			{
				node->parent->right = nullptr;
			}
			else
			{
				node->parent->left = nullptr;
			}
			delete node;
			node = nullptr;
		}
	}

private:
	void _delNode(Node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		_delNode(node->left);
		_delNode(node->right);
		delete node;
	}

public:
	~MyTree()
	{
		_delNode(root);
	}

private:
	void _PreDisplay(Node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		std::cout << node->val << " ";
		_PreDisplay(node->left);
		_PreDisplay(node->right);
	}

public:
	//前序遍历
	void PreDisplay()
	{
		if (root == nullptr)
		{
			throw new TreeError("树节点为空");
		}
		_PreDisplay(root);
		std::cout << "\n";
	}
	//层序打印,为例打印效果,选择二维数组保存结果后一起打印,让打印结果尽可能接近树
	void Print()
	{
		if (this->root == nullptr)
		{
			return;
		}
		std::vector<std::vector<Elem>> msg;
		int level = 1; //层数
		std::queue<Node *> queue;
		queue.push(root);
		while (!queue.empty())
		{
			std::vector<Elem> vet;
			for (int i = 0; !queue.empty() && i < pow(2, level - 1); i++)
			{
				Node *node = queue.front();
				vet.push_back(node->val);
				queue.pop();
				if (node->left != nullptr)
					queue.push(node->left);
				if (node->right != nullptr)
					queue.push(node->right);
			}
			msg.push_back(vet);
			level++;
		}
		//打印二维数组
		//计算要先打印集合空格
		int space = pow(2, level - 1) / 2 - 1;
		for (int i = 0; i < msg.size(); i++)
		{
			for (int k = 0; k < space; k++)
			{
				std::cout << " ";
			}
			for (int j = 0; j < msg[i].size(); j++)
			{
				std::cout << msg[i][j] << " ";
			}
			std::cout << std::endl;
			space--;
		}
	}
	//获取二叉树第k层节点个数
private:
	int _getKSize(Node *root, int K)
	{
		if (root == nullptr || K <= 0)
		{
			return 0;
		}
		if (K == 1)
		{
			return 1;
		}
		return _getKSize(root->left, K - 1) + _getKSize(root->right, K - 1);
	}

public:
	int getKSize(int K)
	{
		if (root == nullptr)
		{
			throw new TreeError("树节点为空");
		}
		return _getKSize(root, K);
	}
};
