//
// Created by ogier on 2023/11/9.
// 559.N叉树的最大深度
#include<queue>
using namespace std;

class Node {
 public:
	int val;
	vector<Node *> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};

class BFS {
 public:
	int maxDepth(Node *root) {
		int res = 0;
		queue<Node *> que;
		if (root != nullptr) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			res++;
			for (int i = 0; i < size; ++i) {
				Node *cur = que.front();
				que.pop();
				for (auto n : cur->children) {
					if (n != nullptr) que.push(n);
				}
			}
		}
		return res;
	}
};