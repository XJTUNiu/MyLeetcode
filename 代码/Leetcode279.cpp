#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//BFS
class Solution {
public:
	int numSquares(int n) {
		vector<int> squres;
		for (int i = 1; i*i <= n; ++i) {     //产生平方数
			squres.push_back(i*i);
		}
		queue<int> myq;
		vector<bool> marked(n+1,false);
		myq.push(n);
		marked[n] = true;
		int level = 0;
		while (!myq.empty()){
			int size = myq.size();
			++level;
			cout << "level  " << level << endl;
			while (size-- > 0) {
				int cur = myq.front();
				cout << "size  " << size << endl;
				cout << "cur  " << cur << endl;
				myq.pop();
				for (int s : squres) {
					cout << "s  " << s << endl;
					int next = cur - s;
					cout << "next  " << next << endl;
					if (next < 0) {
						break;
					}
					if (next == 0) {
						return level;
					}
					if (marked[next]) {
						continue;
					}
					marked[next] = true;
					myq.push(next);
				}

			}
		}
		return n;
	}
};

class Solution1 {
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
	int ret = s1.numSquares(4);
	cout << ret << endl;


	system("pause");
	return 0;
}