/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.45%)
 * Likes:    2881
 * Dislikes: 242
 * Total Accepted:    297.1K
 * Total Submissions: 908.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 *
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 *
 * Output: 42
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
	int maxPathSum (TreeNode* root) {
		if (!root) return 0;
		int ans = INT_MIN;
		dfs (root, ans);
		return ans;
	}
	int dfs (TreeNode* root, int& ans) {
		if (!root) return 0;
		int l = dfs (root->left, ans);
		int r = dfs (root->right, ans);
		ans = max ({ans, root->val, l + r + root->val, l + root->val, r + root->val});
		return max (root->val, root->val + max (l, r));
	}
};
// @lc code=end
