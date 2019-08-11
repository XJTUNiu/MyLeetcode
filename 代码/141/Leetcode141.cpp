#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;




 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return false;
		ListNode* p1 = head->next, *p2 = head->next->next;
		//p1¿ìÖ¸Õë,p2Âý
		while (p2 != nullptr) {
			if (p1->val == p2->val) {
				return true;
			}
			p1 = p1->next;
			p2 = p2->next->next;
		}
		return false;
	}
};


int main(void)
{
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	Solution s1;
	vector<int>::iterator it;
	s1.merge(nums1, 3, nums2, 3);
	for (it = nums1.begin(); it != nums1.end(); ++it) {
		cout << *it << endl;
	}
	system("pause");
	return 0;
}