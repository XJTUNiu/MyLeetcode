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
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		res[0] = 0;
		for (int i = 0; i <= num; ++i) {
			if (i % 2 == 1) {
				res[i] = res[i >> 1]+1;
			}
			else {
				res[i] = res[i >> 1];
			}
		}
		return res;
	}
};

class Solution1 {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 0; i <= num; ++i) {
			int count = 0, temp = i;
			while (temp != 0) {
				if ((temp & 1) == 1) {
					++count;
				}
				temp = temp >> 1;
			}
			res[i] = count;
		}
		return res;
	}
};



int main(void)
{
	Solution s1;

	vector<int> nums = s1.countBits(2);
	for (int i : nums) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}