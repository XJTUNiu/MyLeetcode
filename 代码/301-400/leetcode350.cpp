#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;

//350
class Solution1 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> m1;
		for (int i : nums1) {
			if (m1.count(i)==0) {
				m1.insert(pair<int,int>(i, 1));
			}
			else
			{
				m1[i] = m1[i] + 1;
			}
		}
		vector<int> v1;
		for (int i : nums2) {
			if (m1.count(i)==1) {
				v1.push_back(i);
				m1[i] = m1[i] - 1;
				if (m1[i] == 0) {
					m1.erase(i);
				}
			}
		}
		return v1;
	}
};



int main(void)
{


	system("pause");
	return 0;
}