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
	int numTrees(int n) {
		vector<int>dp(n + 1, 0);
		if (n <= 2) {
			return n;
		}
		for (int i = 1; i <= 2; i++) {
			dp[i] = i;
		}
		dp[0] = 1;
		for (int i = 3; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= i; j++) {
				sum = sum + dp[j-1]*dp[i-j];
			}
			dp[i] = sum;
		}
		return dp[n];
	}
};

int main(void)
{
	int n = 7;
	Solution s1;
	int ret = s1.numTrees(n);
	cout << ret << endl;

	system("pause");
	return 0;
}