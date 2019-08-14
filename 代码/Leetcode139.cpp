#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

class Solution1 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int totallen = s.size();
		int vlen = wordDict.size();
		if (totallen == 0 || vlen == 0) {
			return false;
		}
		int minlen = 1e8;
		set<string> s1;
		for (int i = 0; i <vlen; i++) {
			if (minlen > wordDict[i].size()) {
				minlen = wordDict[i].size();
			}
			s1.insert(wordDict[i]);
			//cout << wordDict[i] << endl;
		}
		vector<vector<bool> > dp(totallen, vector<bool>(totallen, false));
		//dp[0][0] = true;
		string temp;
		for (int i = minlen-1; i < totallen; i++) {
			int j;
			for (j = 0; j <= i-minlen+1;j++) {
				temp = s.substr(j, i - j+1);
				//cout << temp << endl;
				if (s1.count(temp) > 0) {
					dp[j][i] = true;
					//cout << j << "," << i << "," << dp[j][i] << endl;
					if (j > 0) {
						dp[0][i] = dp[0][j - 1] && dp[j][i];
					}
					//cout << 0 << "," << i << "," << dp[0][i] << endl;
					if (dp[0][i] == true) {
						break;
					}
				}
			}
		}
		return dp[0][totallen - 1];
	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int totallen = s.size();
		set<string> s1(wordDict.begin(), wordDict.end());
		vector<bool> dp(totallen+1, false);
		dp[0] = true;
		for (int i = 0; i <= totallen; i++) {
			for (int j = i-1; j >=0 ; j--) {
				if (dp[j]&& s1.count(s.substr(j, i - j)) > 0) {
						dp[i] =true;
						break;
					}
			}
		}
		return dp[totallen];
	}
};

int main(void)
{
	string s = "dogs";
	vector<string>wordDict = { "dog", "s", "gs" };
	Solution s1;
	bool ret = s1.wordBreak(s,wordDict);
	cout << ret << endl;
	system("pause");
	return 0;
}