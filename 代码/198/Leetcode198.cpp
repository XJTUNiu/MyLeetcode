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
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0];
		}
		vector<int>dp(len, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; ++i) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[len - 1];
	}
};

int main(void)
{
	vector<int>wordDict = { 2 };
	Solution s1;
	int ret = s1.rob(wordDict);
	cout << ret << endl;


	system("pause");
	return 0;
}