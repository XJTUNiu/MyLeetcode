#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//3 temp
class Solution1 {
public:
	int maxSubArray1(vector<int>& nums) {
		int len = nums.size();
		vector<int> temp(len,0);
		int maxval = nums[0];
		for (int i = 0; i < len; i++) {
			temp[i] = nums[i];
			if (temp[i]>maxval) {
				maxval = temp[i];
			}
		}
		for (int i = 0; i < len; i++) {
			vector<int> temp(len, nums[i]);
			for (int j = i+1; j < len; j++) {
				temp[j]= temp[j - 1] + nums[j];
				if (temp[j] > maxval) {
					maxval = temp[j];
				}
			}
		}
		return maxval;
	}
};


//3 temp
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size(),maxval=nums[0];
		vector<int> dp(len, nums[0]);
		for (int i = 1; i < len;i++) {
			if (dp[i - 1]>0) {
				dp[i] = dp[i - 1] + nums[i];
				maxval = max(dp[i],maxval);
			}
			else
			{
				dp[i] = nums[i];
				maxval = max(dp[i], maxval);
			}
		}

		return maxval;
	}
};



int main(void)
{
	vector<int> s = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution s1;
	int ret = s1.maxSubArray(s);
	cout << ret;

	system("pause");
	return 0;
}