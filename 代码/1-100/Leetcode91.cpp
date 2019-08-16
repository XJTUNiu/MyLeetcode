#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') {
			return 0;
		}
		int len = s.size();
		if (len <= 1) {
			return len;
		}
		vector<int>dp(len, 0);
		dp[0] = 1;
		if (s[1] != '0'&&((s[0] == '2'&&s[1] <= '6')|| (s[0] == '1'))) {
			dp[1] = 2;
		}
		else if(s[0]>'2'&&s[1]=='0'){
			dp[1] = 0;
		}
		else {
			dp[1] = 1;
		}
		for (int i = 2; i < len; i++) {
			if (s[i] != '0') {
				dp[i] = dp[i] + dp[i - 1];
			}
			if ((s[i - 1] == '2'&&s[i] <= '6')|| (s[i-1] == '1')) {
				dp[i] = dp[i] + dp[i - 2];
			}
		}
		return dp[len-1];
	}
};

int main(void)
{
	string s= "17";
	Solution s1;
	int ret = s1.numDecodings(s);
	cout << ret << endl;

	system("pause");
	return 0;
}