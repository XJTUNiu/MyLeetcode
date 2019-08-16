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
	int maxProduct(vector<int>& nums) {
		int len = nums.size(),ret=nums[0];
		vector<vector<int> >dp(len, vector<int>(2, -1e8));
		dp[0][0] = nums[0];
		dp[0][1] = nums[0];
		for (int i = 1; i < len; i++) {
			if (nums[i] >= 0) {
				dp[i][0] = max(dp[i - 1][0] * nums[i],nums[i]);
				dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i]);
			}
			else if (nums[i] < 0) {
				dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i]);
				dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i]);
			}
			if (ret < dp[i][0]) {
				ret = dp[i][0];
			}
		}
		return ret;
	}
};

int main(void)
{
	vector<int>wordDict = { 7,-2,-4 };
	Solution s1;
	int ret = s1.maxProduct(wordDict);
	cout << ret << endl;


	system("pause");
	return 0;
}