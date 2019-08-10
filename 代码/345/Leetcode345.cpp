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
	string reverseVowels(string s) {
		int len = s.size();
		if (len == 0) {
			return "";
		}
		int i = 0, j = len - 1;
		while (i < j) {
			bool temp1=false, temp2=false;
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
				|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				temp1 = true;
			}
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'
				||s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
			{
				temp2 = true;
			}
			if (temp1==true&&temp2==true) {
				swap(s[i], s[j]);
				++i;
				--j;
			}
			else if (temp1 == true && temp2 != true) {
				--j;
			}
			else{
				++i;
			}
		}
		return s;
	}
};




int main(void)
{
	vector<int> nums1 = { 2, 7, 11, 15 };
	string s = "hello";
	Solution s1;
	string nums = s1.reverseVowels(s);
	cout << nums << endl;
	system("pause");
	return 0;
}