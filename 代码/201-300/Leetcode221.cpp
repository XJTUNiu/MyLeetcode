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
	int maximalSquare(vector<vector<char>>& matrix) {
		int len1 = matrix.size();
		if (len1 == 0) {
			return 0;
		}
		int len2 = matrix[0].size();
		if (len1 == 1&& len2== 1) {
			return matrix[0][0]-'0';
		}
		int ret = 0;
		vector<vector<int> > dp(len1, vector<int>(len2, 0));
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				dp[i][j] = matrix[i][j] - '0';
			}
		}
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j <len2; ++j) {
				if (i>0&&j>0&&matrix[i][j]=='1') {
					dp[i][j] = min(dp[i - 1][j - 1],min(dp[i][j - 1] ,dp[i - 1][j])) + 1;
					//cout << dp[i][j] << endl;
					//cout << "_________" << endl;
				}
				if (dp[i][j]>ret) {
					ret = dp[i][j];
				}
			}
			//cout << "_________" << endl;
		}
		return ret*ret;
	}
};

int main(void)
{
	vector<vector<char> > matrix = { {'1','1','1','1' },{ '1','1','1','1' },{ '1','1','1','1' } };
	Solution s1;
	int ret = s1.maximalSquare(matrix);
	cout << ret << endl;


	system("pause");
	return 0;
}