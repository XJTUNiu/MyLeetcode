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
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		vector<int> ret(2, 0);
		if (len == 0 || target<numbers[0]) {
			return ret;
		}
		int temp = 0,i=0,j=len-1;
		while (i < j) {
			temp = numbers[i] + numbers[j];
			if (temp < target) {
				++i;
			}
			else if (temp > target) {
				--j;
			}
			else {
				ret[0] = ++i;
				ret[1] = ++j;
				break;
			}
		}
		return ret;
	}
};




int main(void)
{
	vector<int> nums1 = { 2, 7, 11, 15 };
	Solution s1;
	vector<int> nums=s1.twoSum(nums1, 9);
	cout << nums[0]<<"       "<<nums[1] << endl;
	system("pause");
	return 0;
}