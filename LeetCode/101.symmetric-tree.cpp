/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.77%)
 * Likes:    3428
 * Dislikes: 83
 * Total Accepted:    573.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
	bool isSymmetric (TreeNode* root) {
		if (!root) return true;
		if ((root->left and !root->right) or (root->right and !root->left)) {
			return false;
		}
		if (!root->left and !root->right) return true;

		deque< pair< int, TreeNode* > > q;
		q.push_back ({-1, root->left});
		q.push_back ({1, root->right});
		bool ans = true;
		set< pair< int, TreeNode* > > tmp;
		while (!q.empty ()) {
			auto left = q.front ();
			q.pop_front ();
			if (q.empty ()) {
				ans = false;
				break;
			}
			auto right = q.back ();
			q.pop_back ();
			if (((left.second)->val != (right.second)->val) or (left.first != -right.first)) {
				ans = false;
				break;
			}
			tmp.insert (left);
			tmp.insert (right);
			if (q.empty ()) {
				while (tmp.size ()) {
					auto node = *tmp.begin ();
					tmp.erase (tmp.begin ());
					if ((node.second)->left) {
						q.push_back ({node.first - 1, (node.second)->left});
					}
					if ((node.second)->right) {
						q.push_back ({node.first + 1, (node.second)->right});
					}
				}
			}
		}
		return ans;
	}
};
// @lc code=end
