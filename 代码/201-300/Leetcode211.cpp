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




class WordDictionary {
	class Node {
	public:
		bool isWord;
		map<char, Node*>* next;
		Node() {
			this->isWord = false;
			next = new map<char, Node*>();
		}
	};
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
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
	bool search(string word) {
		Node* cur = root;
		return Match(cur, word, 0);
	}
	bool Match(Node* node, string word, int index) {
		if (index == word.size())
			return node->isWord;
		char c = word.at(index);
		if (c != '.') {
			if (node->next->count(c) == 0) {
				return false;
			}
			return Match(node->next->at(c), word, index + 1);
		}
		else {
			map<char, Node*>::iterator it;
			for (it = node->next->begin(); it != node->next->end(); it++) {
				if (Match(node->next->at(it->first), word, index + 1)) {
					return true;
				}
			}
			return false;
		}
	}
	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */


private:
	Node* root;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/
int main()
{
	return 0;
}
