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
	int coinChange(vector<int>& coins, int amount) {
		int len = coins.size();
		if (amount == 0) {
			return 0;
		}
		//sort(coins.begin(), coins.end());||coins[0]>amount
		if (len == 0 ) {
			return -1;
		}
		vector<int> dp(amount+1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int coin : coins) {
				if (coin <= amount) {
					dp[coin] = 1;
				}
				if (i- coin >=0&&dp[i - coin] < dp[i]-1 ) {
					dp[i] = dp[i- coin] + 1;
				}
			}
		}
		return dp[amount] == INT_MAX ? -1: dp[amount];
	}
};

int main(void)
{
	vector<int> nums = { 474,83,404,3 };
	Solution s1;
	int ret = s1.coinChange(nums,264);
	cout << ret << endl;


	system("pause");
	return 0;
}