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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i>=0||j>=0) {
			while (k >= 0 && i >= 0) {
				if (j < 0) {
					--i;
					break;
				}
				if (nums1[i] >= nums2[j]) {
					nums1[k] = nums1[i];
					cout << nums1[k] << endl;
					--i;
					--k;
				}
				else {
					break;
				}
			}
			while (k >= 0 && j >= 0) {
				if (i < 0) {
					while (j >= 0) {
						nums1[j] = nums2[j];
						--j;
					}
					break;
				}
				if (nums1[i] < nums2[j]) {
					nums1[k] = nums2[j];
					cout << nums1[k] << endl;
					--j;
					--k;
				}
				else {
					break;
				}
			}
		}
	}
};


int main(void)
{
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	Solution s1;
	vector<int>::iterator it;
	s1.merge(nums1,3, nums2,3);
	for (it = nums1.begin(); it != nums1.end(); ++it) {
		cout << *it << endl;
	}
	system("pause");
	return 0;
}