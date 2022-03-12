/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (37.73%)
 * Likes:    1254
 * Dislikes: 67
 * Total Accepted:    149.2K
 * Total Submissions: 394.2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Example 1:
 *
 *
 * Input: [1,3,null,null,2]
 *
 * 1
 * /
 * 3
 * \
 * 2
 *
 * Output: [3,1,null,null,2]
 *
 * 3
 * /
 * 1
 * \
 * 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,4,null,null,2]
 *
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 *
 * Output: [2,1,4,null,null,3]
 *
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 *
 *
 * Follow up:
 *
 *
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
	TreeNode *node1, *node2;
	int val = INT_MIN;
	void recoverTree (TreeNode* root) {
		if (!root) return;
		inorder (root);
		swap (node1->val, node2->val);
	}
	void inorder (TreeNode* root) {
		if (!root) return;
		inorder (root->left);
		if (val > root->val) node1 = root;
		if (!node1) node2 = root;
		val = root->val;
		inorder (root->right);
	}
};
// @lc code=end
