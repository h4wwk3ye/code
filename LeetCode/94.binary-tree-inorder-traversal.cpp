/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (61.11%)
 * Likes:    2576
 * Dislikes: 112
 * Total Accepted:    647.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
	vector< int > inorderTraversal (TreeNode* root) {
		vector< int > ans;
		// inorder (ans, root);
		if (!root) return ans;
		stack< TreeNode* > stk;
		while (!stk.empty () or root) {
			while (root) {
				stk.push (root);
				root = root->left;
			}
			root = stk.top ();
			stk.pop ();
			ans.push_back (root->val);
			root = root->right;
		}
		return ans;
	}
	void inorder (vector< int >& ans, TreeNode* root) {
		if (!root) return;
		inorder (ans, root->left);
		ans.push_back (root->val);
		inorder (ans, root->right);
	}
};
// @lc code=end
