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
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size(), ret = 0,minnum=INT_MAX;
		if (len <= 1) {
			return len;
		}
		vector<int> dp(len, 0);
		dp[0] = 1;
		minnum = nums[0];
		for (int i = 0; i <len; ++i) {
			for (int j = 0; j <i;++j) {
				if (nums[j] < nums[i]&&dp[i]<=dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
				else if(dp[i]==0)
				{
					dp[i] =1;
				}
			}
			//cout << dp[i] << endl;
			if (ret < dp[i]) {
				ret = dp[i];
			}
		}
		return ret;
	}
};



int main(void)
{
	vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
	Solution s1;
	int ret = s1.lengthOfLIS(nums);
	cout << ret << endl;


	system("pause");
	return 0;
}