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



class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* cur = root;
		for (char c : word) {
			if (cur->next->count(c) == 0) {
				cur->next->insert(make_pair(c, new Node()));
			}
			cur = cur->next->at(c);
		}
		if (!cur->isWord) {
			cur->isWord = true;
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* cur = root;
		for (char c : word) {
			if (cur->next->count(c) == 0) {
				return false;
			}
			cur = cur->next->at(c);
		}
		return cur->isWord; 
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* cur = root;
		for (char c : prefix) {
			if (cur->next->count(c) == 0) {
				return false;
			}
			cur = cur->next->at(c);
		}
		return true;
	}

	class Node {
	public:
		bool isWord;
		map<char, Node*>* next;
		Node(bool isWord) {
			this->isWord = isWord;
			next = new map<char, Node*>();
		}
		Node() {
			this->isWord = false;
			next = new map<char, Node*>();
		}
	};
private:
	Node* root;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/