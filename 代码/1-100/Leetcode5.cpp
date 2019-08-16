#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//1
class Solution1 {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		int maxindex=0,maxlen=1;
		for (int i = 0; i < len - 1; i++) {
			int temp1=0, temp2=1;
			int j = 1;
			while (i - j+1 >= 0 && i + j < len&&s[i - j + 1] == s[i + j]) {
				j++;
				temp1 += 2;
			}
			j = 1;
			while (i - j >= 0 && i + j < len&& s[i - j] == s[i + j]) {
				j++;
				temp2 += 2;
			}
			if (temp1> maxlen|| temp2> maxlen) {
				maxlen = max(temp1, temp2);
				maxindex = i;
			}
		}
		return s.substr(maxindex-(maxlen-1)/2,maxlen);
	}
};

//2 mydp
class Solution2 {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		int maxind = 0, maxlen = 1,range=0;
		int* dp = new int[len];
		for (int i = 0; i < len; i++) {
			dp[i] = 1;
		}
		for (int i = 0; i < len;i++) {
			int ji = 1,ou=1;
			while (i - ji >= 0 && i + ji < len&&s[i - ji] == s[i + ji]) {
				ji += 1;
			}
			while (i - ou+1 >= 0 && i + ou < len&&s[i - ou+1] == s[i + ou]) {
				ou += 1;
			}
			range = max(2 * ji-2, 2 * ou - 3);
			dp[i] = dp[i] + range;
			if (dp[i] > maxlen) {
				maxlen = dp[i];
				maxind = i;
			}
		}
		delete[] dp;
		return s.substr(maxind - (maxlen - 1) / 2, maxlen);
	}
};


//3 dp
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len == 0 || len == 1) {
			return s;
		}
		int start = 0, end = 0;
		vector<vector<bool> > dp(len, vector<bool>(len,false));
		for (int i = 0; i < len; i++) {
			dp[i][i] = true;
			//cout << dp[i][i] << endl;
			if ((i +1 <len ) && s[i] == s[i+1]) {
				dp[i][i+1] = true;
				//cout << dp[i][i + 1] << endl;
				if (1> end - start) {
					start = i;
					end = i+1;
				}
			}
		}
		for (int j =2; j < len; j++) {
			for (int i = 0; i < len-1; i++) {
				if ((dp[i + 1][j - 1]) && s[i] == s[j]) {
					dp[i][j] = true;
					if (j - i > end - start) {
						start = i;
						end = j;
					}
				}
			}
		}
		return s.substr(start, end - start + 1);
	}
};


int main(void)
{
	string s = "cbaabd";
	Solution s1;
	string ret = s1.longestPalindrome(s);
	cout << ret;

	system("pause");
	return 0;
}