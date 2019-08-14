#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//3 temp
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int j = 1; j < n; j++) {
			dp[0][j]=dp[0][j-1]+grid[0][j];
			//cout << dp[0][j] << endl;
		}
		for (int i = 1; i < m; i++) {
			dp[i][0] = dp[i-1][0] + grid[i][0];
			//cout << dp[i][0] << endl;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
			    dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1])+grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};



int main(void)
{
	vector<vector<int> > vec = { {
		{ 1,2 },{ 1,1 }
		} };
	Solution s1;
	int ret = s1.minPathSum(vec);
	cout << ret;

	system("pause");
	return 0;
}