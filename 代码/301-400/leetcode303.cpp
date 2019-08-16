#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;

//303
class NumArray {
public:
	vector<int> sum1;
	NumArray(vector<int>& nums) {
		int sum=0;
		sum1.push_back(sum);
		for (int i = 0; i < nums.size();i++) {
			sum = sum + nums[i];
			sum1.push_back(sum);
		}
	}

	int sumRange(int i, int j) {
		return (sum1[j+1] - sum1[i]);
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(i,j);
*/



int main(void)
{


	system("pause");
	return 0;
}