/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (46.09%)
 * Likes:    2741
 * Dislikes: 79
 * Total Accepted:    315K
 * Total Submissions: 680.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
	TreeNode* buildTree (vector< int >& preorder, vector< int >& inorder) {
		if (!preorder.size ()) return nullptr;

		map< int, int > mp;
		int i = 0;
		for (auto& j : preorder)
			mp[j] = i++;

		return build (preorder, inorder, 0, inorder.size () - 1, mp);
	}

	TreeNode* build (vector< int >& preorder, vector< int >& inorder, int low, int high, map< int, int >& mp) {
		if (low == high) {
			return new TreeNode (inorder[low]);
		} else if (low > high) {
			return nullptr;
		}
		int mn = low;
		for (int i = low + 1; i <= high; ++i) {
			if (mp[inorder[i]] < mp[inorder[mn]]) mn = i;
		}
		TreeNode* root = new TreeNode (inorder[mn]);
		root->left = build (preorder, inorder, low, mn - 1, mp);
		root->right = build (preorder, inorder, mn + 1, high, mp);
		return root;
	}
};
// @lc code=end
