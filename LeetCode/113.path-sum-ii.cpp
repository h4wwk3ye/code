/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (44.58%)
 * Likes:    1425
 * Dislikes: 49
 * Total Accepted:    301.3K
 * Total Submissions: 673.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 *
 *
 * Return:
 *
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector< vector< int > > pathSum (TreeNode* root, int sum) {
		vector< vector< int > > ans;
		if (!root) return ans;
		solve (root, sum, {}, 0, ans);
		return ans;
	}
	void solve (TreeNode* root, int& sum, vector< int > x, int curr, vector< vector< int > >& ans) {
		if (!root) return;
		if (!root->left and !root->right) { // leaf
			if (curr + root->val == sum) {
				x.push_back (root->val);
				ans.push_back (x);
			}
			return;
		}
		x.push_back (root->val);
		solve (root->left, sum, x, curr + root->val, ans);
		solve (root->right, sum, x, curr + root->val, ans);
	}
};
// @lc code=end
