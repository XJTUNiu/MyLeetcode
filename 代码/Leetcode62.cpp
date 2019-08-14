#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution1 {
public:
	int uniquePaths(int m, int n) {
		if (m > n) {
			swap(m, n);
		}
		double M = m + n - 2, N = m - 1;
		int res=1;
		for (int i = 1; i <= N; i++) {
			res = res*(M - N + i) / i;
		}
		return res;
	}
};

//3 temp
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m-1][n-1];
	}
};



int main(void)
{
	int m = 7, n = 3;
	Solution s1;
	int ret = s1.uniquePaths(m,n);
	cout << ret;

	system("pause");
	return 0;
}