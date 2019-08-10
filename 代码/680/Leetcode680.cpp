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
	bool fun(string s) {
		int len = s.size();
		int i = 0, j = len - 1;
		while (i <= j) {
			if (s[i++] != s[j--]) {
				return false;
			}
		}
		return true;
	}
	bool validPalindrome(string s) {
		int len = s.size();
		int i = 0, j = len - 1;
		while (i <= j) {
			//cout << s[i] << s[j] << endl;
			if (s[i] != s[j]) {
				++i;
				if (fun(s.substr(i, j - i + 1)) == true) {
					return true;
				}
				--i;
				--j;
				if (fun(s.substr(i, j - i + 1)) == true) {
					return true;
				}
				return false;
			}
			else {
				++i;
				--j;
			}
		}
		return true;
	}
};




int main(void)
{
	vector<int> nums1 = { 2, 7, 11, 15 };
	string s = "aydmda";
	Solution s1;
	bool nums = s1.validPalindrome(s);
	cout << nums << endl;
	system("pause");
	return 0;
}