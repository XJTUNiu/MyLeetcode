#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

//347
class Solution2 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> m1;
		for (int i : nums) {
			if (m1.count(i) == 0) {
				m1.insert(pair<int, int>(i, 1));
			}
			else
			{
				m1[i] = m1[i] + 1;
			}
		}
		struct Freq {
			int data, freq;
			Freq(int data, int freq):data(data),freq(freq) {}
			bool operator<(const Freq& b) const{
				return this->freq > b.freq;
			}
		};
		priority_queue<Freq> q1;
		map<int, int>::iterator it;
		for (it = m1.begin(); it != m1.end();it++) {
			if (q1.size() < k) {
				q1.push(Freq(it->first, it->second));
			}
			else if(it->second > q1.top().freq){
				q1.pop();
				q1.push(Freq(it->first, it->second));
			}
		}
		vector<int> v1;
		while (!q1.empty()) {
			v1.push_back(q1.top().data);
			q1.pop();
		}
		return v1;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m1;
		for (int i : nums) {
			m1[i]++;       //统计<数，频次>
		}
		multimap<int,int> m2;
		for (auto it = m1.begin(); it != m1.end();++it) {
			m2.insert({it->second,it->first});     //反转储存<频次，数>，自动排序
		}
		vector<int> v1;
		int i = 0;               //输出
		for (auto it2 = m2.rbegin(); i<k&&it2 != m2.rend(); ++it2) {
			v1.push_back(it2->second);
			++i;
		}
		return v1;
	}
};




int main(void)
{


	system("pause");
	return 0;
}