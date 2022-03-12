/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    2431
 * Dislikes: 64
 * Total Accepted:    537.9K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
	vector< vector< int > > levelOrder (TreeNode* root) {
		vector< vector< int > > ans;
		if (!root) return ans;
		queue< pair< TreeNode*, int > > q;
		q.push ({root, 0});
		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();

			if (ans.size () <= node.second) {
				ans.push_back ({(node.first)->val});
			} else {
				ans.back ().push_back ((node.first)->val);
			}
			if ((node.first)->left) {
				q.push ({(node.first)->left, node.second + 1});
			}
			if ((node.first)->right) {
				q.push ({(node.first)->right, node.second + 1});
			}
		}
		return ans;
	}
};
// @lc code=end
