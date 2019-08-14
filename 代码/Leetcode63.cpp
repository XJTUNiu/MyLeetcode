#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//3 temp
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m, vector<long>(n, 0));
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				break;
			}
			dp[0][j] = 1;
		}
		for (int i = 0; i < m; i++){
			if ( obstacleGrid[i][0] == 1) {
				break;
			}
			dp[i][0] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};



int main(void)
{
	vector<vector<int> > vec = { {
		{0,0,0},{0,1,0},{0,0,0}
	 } };
	Solution s1;
	int ret = s1.uniquePathsWithObstacles(vec);
	cout << ret;

	system("pause");
	return 0;
}