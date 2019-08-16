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
	struct Heap {
	public:
		//直接构建N元素大顶堆
		Heap(vector<int> nums,int n) {
			N = n;
			data = new int[N + 1];
			int len = nums.size();
			for (int i = 0; i < N;++i) {
				data[i + 1] = nums[i];
			}
			//调整堆
			for (int i = N / 2; i >= 1; i--)
				shiftDown(i);
			for (int i = N; i < len; ++i) {
				if (data[1] < nums[i]) {
					data[1] = nums[i];
					shiftDown(1);
				}
			}
		}
		void shiftDown(int k) {
			while (2 * k <= N) {
				int j = 2 * k;
				if (j + 1 <= N && data[j + 1] < data[j]) j++;
				if (data[k] <= data[j]) break;
				swap(data[k], data[j]);
				k = j;
			}
		}
		int *data;
		int N;
	};
	int findKthLargest(vector<int>& nums, int k) {
		Heap myheap(nums, k);
		return myheap.data[1];
	}
};




int main(void)
{
	vector<int> nums1 = { 3,2,3,1,2,4,5,5,6 };
	int sout;
	Solution s1;
	sout=s1.findKthLargest(nums1,4);
	cout << sout << endl;
	system("pause");
	return 0;
}