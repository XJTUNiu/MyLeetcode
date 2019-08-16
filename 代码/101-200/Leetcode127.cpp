#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


//BFS
class Solution {
public:
	bool cmp(string s1, string s2) {
		int i = 0, flag = 0;
		for (; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) {
				++flag;
			}
		}
		return flag<=1;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		set<string> myset(wordList.begin(), wordList.end());
		if (myset.count(endWord) == 0) {
			return 0;
		}
		queue<string> myq;
		list<string> mylist(wordList.begin(), wordList.end());
		int level = 0;
		myq.push(beginWord);
		while (!myq.empty()) {
			int size = myq.size();
			++level;
			while (size-- != 0) {
				string temp1 = myq.front();
				if (temp1 == endWord) {
					return level;
				}
				myq.pop();
				for (auto it = mylist.begin(); it != mylist.end();) {
					if (cmp(temp1, *it)) {
						if (*it == endWord) {
							return ++level;
						}
						myq.push(*it);
						mylist.erase(it++);
					}
					else {
						++it;
					}
				}
			}
		}
		return 0;
	}
};



int main(void)
{
	vector<string> wordList{ "hot","dot","dog" };
	string beginWord = "hot", endWord = "dot";
	Solution s1;
	int ret = s1.ladderLength(beginWord, endWord, wordList);
	cout << ret << endl;


	system("pause");
	return 0;
}