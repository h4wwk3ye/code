/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.48%)
 * Likes:    1646
 * Dislikes: 85
 * Total Accepted:    315K
 * Total Submissions: 691.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
	vector< vector< int > > zigzagLevelOrder (TreeNode* root) {
		vector< vector< int > > ans;
		if (!root) return ans;
		queue< TreeNode* > q;

		q.push (root);

		bool flag = 1;
		while (!q.empty ()) {
			int n = q.size ();

			vector< int > tmp (n);
			for (int i = 1; i <= n; ++i) {
				auto node = q.front ();
				q.pop ();

				int idx = flag ? i - 1 : n - i;
				tmp[idx] = node->val;

				if (node->left) q.push (node->left);
				if (node->right) q.push (node->right);
			}
			flag = !flag;
			ans.push_back (tmp);
		}

		return ans;
	}
};
// @lc code=end
