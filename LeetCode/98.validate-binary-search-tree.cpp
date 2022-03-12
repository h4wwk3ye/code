/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.18%)
 * Likes:    3233
 * Dislikes: 459
 * Total Accepted:    603.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * Input: [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 *
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
	bool isValidBST (TreeNode* root) {
		if (!root) return true;
		bool ans = 1;
		pair< int, int > x = solve (root, ans);
		return ans;
	}
	pair< int, int > solve (TreeNode* root, bool& ans) {
		if (!root) {
			return {-1e9, -1e9};
		}
		if (!root->left and !root->right) return {root->val, root->val};
		pair< int, int > x = {root->val, root->val};
		pair< int, int > y = solve (root->left, ans);
		if (y.first != -1e9 and y.second != -1e9 and (y.first >= root->val or y.second >= root->val))
			ans = 0;
		pair< int, int > z = solve (root->right, ans);
		if (z.first != -1e9 and z.second != -1e9 and (z.first <= root->val or z.second <= root->val))
			ans = 0;

		if (y.first != -1e9) {
			x.first = min (x.first, min (y.first, y.second));
		}
		x.second = max (x.second, max (z.first, z.second));
		return x;
	}
};
// @lc code=end
