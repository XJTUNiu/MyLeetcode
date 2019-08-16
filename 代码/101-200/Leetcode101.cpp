#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;



 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution {
 public:
	 bool isSymmetric(TreeNode* root) {
		 if (root == nullptr) {
			 return true;
		 }
		 queue<TreeNode*> myq;
		 myq.push(root->left);
		 myq.push(root->right);
		 while (!myq.empty()) {
			 TreeNode* temp1 = myq.front();
			 myq.pop();
			 TreeNode* temp2 = myq.front();
			 myq.pop();
			 if (temp1 == nullptr&&temp2 == nullptr)  continue;
			 if (temp1 == nullptr || temp2 == nullptr) return false;
			 if (temp1->val != temp2->val) return false;
			 myq.push(temp1->left);
			 myq.push(temp2->right);
			 myq.push(temp1->right);
			 myq.push(temp2->left);
		 }
		 return true;
	 }
 };



int main(void)
{
	vector<int> wordList{ 1,2,2,NULL,3,NULL,3 };
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right= new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	Solution s1;
	int ret = s1.isSymmetric(root);
	cout << ret << endl;


	system("pause");
	return 0;
}