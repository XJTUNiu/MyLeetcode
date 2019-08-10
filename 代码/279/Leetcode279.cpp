#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

//´íÎó
class Solution1 {
public:
	int numSquares(int n) {
		int count1=0, count2 = 0,ret=INT_MAX;
		int sum1=0,sum2=0;
		int num = sqrt(n)+1;
		//vector<int> dp(num,0);
		for (int i = num; i > 0; --i) {
			int j = i,k=i;
			while (n > sum1&&j > 0) {
				while (n - sum1 < j*j&&j>0) {
					--j;
				}
				while (n - sum2 < k*k&&k>0) {
					k-=2;
				}
				sum1 += j*j;
				sum2 += k*k;
				++count1;
				++count2;
				if (sum1 == n||sum2==n) {
					break;
				}
			}
			if (ret > min(count1,count2)) {
				ret = min(count1, count2);
			}
			sum1 = 0;
			count1 = 0;
			sum2= 0;
			count2 = 0;
		}
		return ret;
	}
};

class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n+1,0);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			int ret = INT_MAX;
			for (int j = 1; j*j <= i;++j)
			{
				if (j*j==i) {
					ret = 1;
				}
				else if (ret > dp[i - j*j] + dp[j*j]) {
					ret = dp[i - j*j] + dp[j*j];
				}
			}
			dp[i] = ret;
			//cout << dp[i] << endl;
		}
		return dp[n];
	}
};



int main(void)
{
	
	Solution s1;
	int ret = s1.numSquares(43);
	cout << ret << endl;


	system("pause");
	return 0;
}