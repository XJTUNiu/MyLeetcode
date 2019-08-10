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
	int findTargetSumWays(vector<int>& nums, int S) {
		int len = nums.size(), res = 0, sum = 0;
		for (int num : nums) {
			sum += num;
		}
		//×ª»»ÎÊÌâ
		int newS = (sum + S) / 2;
		if (S > sum || S < -sum || (sum + S) % 2 == 1) {
			return 0;
		}
		vector<vector<int> > dp(len + 1, vector<int>(newS + 1, 0));
		for (int i = 1; i <= len; i++)
		{
			dp[i - 1][0] = 1;
		}

		for (int i = 1; i <= len; ++i) {
			for (int j = 0; j <= newS; ++j) {
				if (nums[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
					//cout << dp[i][j] << endl;
				}
				else {
					dp[i][j] = dp[i - 1][j];
					//cout << dp[i][j] << endl;
				}
			}
		}
		return dp[len][newS];
	}
};




int main(void)
{
	vector<int> nums1 = { 1, 1, 1, 1, 1 };
	Solution s1;
	int nums = s1.findTargetSumWays(nums1,5);
	cout << nums << endl;
	system("pause");
	return 0;
}