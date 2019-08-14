#define _CRK_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> freq(26);
		for (int i = 0; i < s.size();i++) {
			freq[s[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (freq[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}
};