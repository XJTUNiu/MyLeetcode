#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int lef=0, mid=0, rig=len-1;   //ÈýÂ·¿ìÅÅ
		while (mid <= rig) {         //ÖÕÖ¹Ìõ¼þ
			//cout << nums[mid] << endl;
			if (nums[mid] < 1) {
				swap(nums[mid], nums[lef]);
				++mid;
				++lef;
			}
			else if (nums[mid] == 1) {
				++mid;
			}
			else {                  //nums[mid] > 1
				swap(nums[mid], nums[rig]);
				--rig;
			}
		}
	}
};




int main(void)
{
	vector<int> nums1 = { 1,2,0 };
	int sout;
	Solution s1;
	s1.sortColors(nums1);
	for(int i:nums1)
	   cout << i << endl;
	system("pause");
	return 0;
}