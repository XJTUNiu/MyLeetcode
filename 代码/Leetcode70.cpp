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
	int climbStairs(int n) {
		if (n <= 2) {
			return n;
		}
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};


int main(void)
{
	int n=3;
	Solution s1;
	int ret = s1.climbStairs(n);
	cout << ret << endl;

	system("pause");
	return 0;
}