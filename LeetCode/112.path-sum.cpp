/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (40.01%)
 * Likes:    1514
 * Dislikes: 438
 * Total Accepted:    423.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
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
 * ⁠/  \      \
 * 7    2      1
 *
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
	bool ans = false;
	bool hasPathSum (TreeNode* root, int sum) {
		if (!root) {
			return false;
		}
		solve (root, sum, 0);
		return ans;
	}
	void solve (TreeNode* root, int& sum, int curr) {
		if (!root) {
			return;
		}
		if (!root->left and !root->right) {
			if (!ans) ans = (curr + root->val) == sum;
			return;
		}
		solve (root->left, sum, curr + root->val);
		solve (root->right, sum, curr + root->val);
		if (ans) return;
	}
};
// @lc code=end
