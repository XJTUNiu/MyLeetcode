#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;

//349
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end());
		vector<int> res;
		for (int i = 0; i < nums2.size(); i++) {
			if (s1.find(nums2[i]) != s1.end()) {
				res.push_back(nums2[i]);
				s1.erase(nums2[i]);
			}
		}
		return res;
	}
};



int main(void)
{


	system("pause");
	return 0;
}