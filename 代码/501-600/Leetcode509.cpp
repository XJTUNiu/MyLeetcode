#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
	int fib(int N) {
		if (N < 2) return N;
		int temp1 = 0, temp2 = 1, val;
		for (int i = 2; i <= N; ++i) {
			val = temp2 + temp1;
			temp1 = temp2;
			temp2 = val;
		}
		return temp2;
	}
};



int main(void)
{
	vector<vector<int> > vec = { {
		{0,0,0},{0,1,0},{0,0,0}
	 } };
	Solution s1;
	int ret = s1.uniquePathsWithObstacles(vec);
	cout << ret;

	system("pause");
	return 0;
}