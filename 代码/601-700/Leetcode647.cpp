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
	int countSubstrings(string s) {
		int len = s.size();
		if (len <= 1) {
			return len;
		}
		vector<vector<int> > dp(len , vector<int>(len,0));
		int res = 0;
		for (int i = 0; i < len; ++i) {
			dp[i][i] = 1;
			cout << dp[i][i] << endl;
			if (i+1<len&&s[i] == s[i + 1]) {
				dp[i][i + 1] = 1;
				cout << dp[i][i+1] << endl;
			}
		}
		int i, j;
		for (j = 2; j <len; ++j) {
			for (i = 0; i+j < len; ++i) {
				if (s[i] == s[i+j]) {
					dp[i][i+j] = dp[i + 1][i+j - 1];
				}
			}
		}
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				res += dp[i][j];
			}
		}
		return res;
	}
};




int main(void)
{
	string s = "aaaaa";
	Solution s1;
	int nums = s1.countSubstrings(s);
	cout << nums << endl;
	system("pause");
	return 0;
}