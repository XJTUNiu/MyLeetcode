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
	int maxProfit(vector<int>& prices) {
		int len = prices.size(), ret = 0;
		if (len <= 1) {
			return 0;
		}
		if (len == 2) {
			return prices[1] - prices[0]>0 ? prices[1] - prices[0] : 0;
		}
		vector<vector<int> > dp(len, vector<int>(3, 0));//1有0无
		dp[0][1] = -prices[0];
		dp[0][0] = 0;
		dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
		dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
		for (int i = 2; i < len; ++i) {
			//今天有无
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		}
		return max(dp[len - 1][0], dp[len - 1][1]);
	}
};

int main(void)
{
	vector<int> nums = { 1,2,3,0,2 };
	Solution s1;
	int ret = s1.maxProfit(nums);
	cout << ret << endl;


	system("pause");
	return 0;
}