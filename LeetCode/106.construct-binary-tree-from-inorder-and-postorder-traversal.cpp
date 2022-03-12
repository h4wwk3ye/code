/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    1331
 * Dislikes: 29
 * Total Accepted:    197.1K
 * Total Submissions: 452.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
	TreeNode* buildTree (vector< int >& inorder, vector< int >& postorder) {
		unordered_map< int, int > mp;
		for (int i = 0; i < postorder.size (); ++i)
			mp[inorder[i]] = i;
		TreeNode* root = build (inorder, postorder, 0, postorder.size () - 1, mp);

		return root;
	}
	TreeNode*
	build (vector< int >& inorder, vector< int >& postorder, int low, int high, unordered_map< int, int >& mp) {
		if (low > high) return nullptr;

		TreeNode* node = new TreeNode (postorder.back ());
		int x = postorder.back ();
		postorder.pop_back ();
		int idx = mp[x];

		node->right = build (inorder, postorder, idx + 1, high, mp);
		node->left = build (inorder, postorder, low, idx - 1, mp);
		return node;
	}
};
// @lc code=end
