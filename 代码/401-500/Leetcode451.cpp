#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> m1;
		for (char i : s) {
			m1[i]++;       //统计<词，频次>
		}
		multimap<int, char> m2;
		for (auto it = m1.begin(); it != m1.end(); ++it) {
			m2.insert({ it->second,it->first });     //反转储存<频次，词>，自动排序
		}
		string s1(s);
		int i = 0;                 //输出
		for (auto it2 = m2.rbegin(); i < s.size()&&it2 != m2.rend(); ++it2) {
			int temp = it2->first;
			while (temp != 0) {
				s1[i]=(it2->second);
				++i;
				--temp;
			}
		}
		return s1;
	}
};




int main(void)
{
	vector<int> nums1 = { 3,2,3,1,2,4,5,5,6 };
	int sout;
	Solution s1;
	sout = s1.findKthLargest(nums1, 4);
	cout << sout << endl;
	system("pause");
	return 0;
}