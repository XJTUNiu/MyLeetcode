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
	bool judgeSquareSum(int c) {
		int i = 0, j = round(sqrt(c+1)), temp;
		while (i <= j) {
			temp = i*i + j*j;
			if (temp < c) {
				++i;
			}
			else if (temp > c) {
				--j;
			}
			else {
				return true;
			}
		}
		return false;
	}
};




int main(void)
{
	vector<int> nums1 = { 2, 7, 11, 15 };
	Solution s1;
	bool nums = s1.judgeSquareSum(4);
	cout << nums<< endl;
	system("pause");
	return 0;
}