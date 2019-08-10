#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1) {
			return 0;
		}
		int ret = 0,maxmum=prices[len-1],temp;
		//vector<int> dp(len+1, 0);
		for (int i = len-2; i >=0; i--) {
			if (maxmum < prices[i]) {
				maxmum = prices[i];
			}
			temp = maxmum-prices[i];
			if (ret < temp) {
				ret = temp;
			}
		}
		return ret;
	}
};

int main(void)
{
	vector<int> vec = { 1,2 };
	Solution s1;
	int ret = s1.maxProfit(vec);
	cout << ret << endl;

	system("pause");
	return 0;
}