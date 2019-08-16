#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;




//307-2___Ïß¶ÎÊ÷
class NumArray {
public:
	vector<int> data;
	vector<int> tree;
	NumArray(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		tree=vector<int>(4*nums.size(),0);
		data.assign(nums.begin(), nums.end());
		BuildSegmentTree(0, 0, data.size() - 1);
	}
	void BuildSegmentTree(int TreeIndex, int left, int right) {
		if (left == right) {
			tree[TreeIndex] = data[left];
			return;
		}
		int LeftTreeIndex = 2 * TreeIndex + 1;
		int RightTreeIndex = 2 * TreeIndex + 2;
		int mid = left + (right - left) / 2;
		BuildSegmentTree(LeftTreeIndex, left, mid);
		BuildSegmentTree(RightTreeIndex, mid + 1, right);
		tree[TreeIndex] = tree[LeftTreeIndex] + tree[RightTreeIndex];
	}

	void update(int i, int val) {
		if (i<0 || i>data.size() - 1) {
			return;
		}
		data[i] = val;
		set(0, 0, data.size() - 1, i, val);
	}
	void set(int TreeIndex, int l, int r, int index, int e) {
		if (l == r) {
			tree[TreeIndex] = e;
			return;
		}
		int LeftTreeIndex = 2 * TreeIndex + 1;
		int RightTreeIndex = 2 * TreeIndex + 2;
		int mid = l + (r - l) / 2;
		if (index >= mid + 1) {
			set(RightTreeIndex, mid + 1, r, index, e);
		}
		else {
			set(LeftTreeIndex, l, mid, index, e);
		}
		tree[TreeIndex] = tree[LeftTreeIndex] + tree[RightTreeIndex];
	}

	int sumRange(int i, int j) {
		if (i > j || i<0 || j>data.size() - 1) {
			return -1;
		}
		return query(0, 0, data.size() - 1, i, j);
	}
	int query(int TreeIndex, int left, int right, int queryL, int queryR) {
		if (left == queryL&&right == queryR) {
			return tree[TreeIndex];
		}
		int LeftTreeIndex = 2 * TreeIndex + 1;
		int RightTreeIndex = 2 * TreeIndex + 2;
		int mid = left + (right - left) / 2;
		if (queryL >= mid + 1) {
			return query(RightTreeIndex, mid + 1, right, queryL, queryR);
		}
		else if (queryR <= mid) {
			return query(LeftTreeIndex, left, mid, queryL, queryR);
		}
		int lrec = query(LeftTreeIndex, left, mid, queryL, mid);
		int rrec = query(RightTreeIndex, mid + 1, right, mid + 1, queryR);
		return lrec + rrec;
	}

};





//307-1___²î·½·¨
class NumArray1 {
public:
	vector<int> sum1;
	vector<int> nums1;
	NumArray1(vector<int>& nums) {
		int sum = 0;
		sum1.push_back(sum);
		for (int i = 0; i < nums.size(); i++) {
			sum = sum + nums[i];
			sum1.push_back(sum);
		}
		nums1.assign(nums.begin(), nums.end());
	}

	void update(int i, int val) {
		int temp = val - nums1[i];
		nums1[i] = val;
		for (int j = i + 1; j < sum1.size(); j++) {
			sum1[j] = sum1[j] + temp;
		}
	}

	int sumRange(int i, int j) {
		return (sum1[j + 1] - sum1[i]);
	}
};
/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

int main(void)
{


	system("pause");
	return 0;
}