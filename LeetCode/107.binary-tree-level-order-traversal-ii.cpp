/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (50.24%)
 * Likes:    1088
 * Dislikes: 198
 * Total Accepted:    286.2K
 * Total Submissions: 568.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
	vector< vector< int > > levelOrderBottom (TreeNode* root) {
		vector< vector< int > > ans;
		if (!root) return ans;

		queue< pair< TreeNode*, int > > q;
		q.push ({root, 0});
		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();
			if (node.second >= ans.size ()) {
				ans.push_back ({(node.first)->val});
			} else {
				ans.back ().push_back ({(node.first)->val});
			}
			if ((node.first)->left) {
				q.push ({(node.first)->left, node.second + 1});
			}
			if ((node.first)->right) {
				q.push ({(node.first)->right, node.second + 1});
			}
		}
		reverse (ans.begin (), ans.end ());
		return ans;
	}
};
// @lc code=end
