#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
public:
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		stack<int> s1;
		while (head->next != NULL) {
			s1.push(head->val);
			head = head->next;
		}
		ListNode* ret = head;
		while (!s1.empty()) {
			ret->next = new ListNode(s1.top());
			ret = ret->next;
			s1.pop();
		}
		return head;
	}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL) {
			return NULL;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		int index = 0;
		ListNode* ret = dummy;
		while (index<m-1)
		{
			ret = ret->next;
			index++;
		}
		ListNode* first = ret->next;
		ListNode* target = ret->next->next;
		ListNode* temp = NULL;
		while (index<n-1) {
			temp = ret->next;
			ret->next = target;
			first->next=target->next;
			target->next = temp;
			target = first->next;
			index++;
		}
		return dummy->next;
	}
};


class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode*temp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return temp;
	}
};


int main(void)
{
	int vec[] = { 3,5 };
	ListNode* head = NULL;
	head = new ListNode(vec[0]);
	ListNode* temp = head;
	//cout << temp->val << endl;
	for (int i = 1; i < 5; i++) {
		temp->next = new ListNode(vec[i]);
		temp = temp->next;
		//cout << temp->val << endl;
	}
	Solution s1;
	ListNode* ret = s1.reverseBetween(head,1,2);
	while (ret != NULL) {
		cout << ret->val << endl;
		ret = ret->next;
	}

	system("pause");
	return 0;
}