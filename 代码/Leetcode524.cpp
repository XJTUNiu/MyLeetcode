#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;




class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		int len = d.size(), lens = s.size();
		if (len == 0 || lens == 0) return "";
		string res = "";
		//��������
		for (string word : d) {
			//˫ָ�룬����С����
			int i = 0, j = 0;
			for (i = 0; i < lens&&word.size() >= res.size(); ) {
				while (j < word.size() && s[i] == word[j]) {
					++i;
					++j;                   //�������
				}
				++i;                       //���������
				if (j == word.size()) {      //ѭ����ֹ
					if (word.size() == res.size()) {
						res = min(res, word);
					}
					else res = word;     
					break;
				}
			}
		}
		return res;
	}
};



int main(void)
{
	vector<string> nums1 = { "ale","apple","monkey","plea" };
	string s = "abpcplea", sout;
	Solution s1;
	vector<int>::iterator it;
	sout=s1.findLongestWord(s, nums1);
	cout << sout << endl;
	system("pause");
	return 0;
}