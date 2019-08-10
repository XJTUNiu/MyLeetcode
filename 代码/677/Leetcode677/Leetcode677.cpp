#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;



class MapSum {
	class Node {
	public:
		int value;
		map<char, Node*>* next;
		Node() {
			this->value = 0;
			next = new map<char, Node*>();
		}
	};
public:
	/** Initialize your data structure here. */
	MapSum() {
		root = new Node();
	}

	void insert(string key, int val) {
		Node* cur = root;
		for (char c : key) {
			if (cur->next->count(c) == 0) {
				cur->next->insert(make_pair(c, new Node()));
			}
			cur = cur->next->at(c);
		}
		cur->value = val;
	}

	int sum(string prefix) {
		Node* cur = root;
		for (char c : prefix) {
			if (cur->next->count(c) == 0) {
				return 0;
			}
			cur = cur->next->at(c);
		}
		return sum(cur);
	}
	int sum(Node* node) {
		if (node->next->size() == 0) {
			return node->value;
		}
		int res = node->value;
		map<char, Node*>::iterator it;
		for (it = node->next->begin(); it != node->next->end(); it++) {
			res += sum(node->next->at(it->first));
		}
		return res;
	}
private:
	Node* root;
};




int main()
{
	return 0;
}
