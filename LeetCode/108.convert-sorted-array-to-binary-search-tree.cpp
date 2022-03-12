/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.49%)
 * Likes:    1937
 * Dislikes: 185
 * Total Accepted:    361.6K
 * Total Submissions: 649.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
	TreeNode* sortedArrayToBST (vector< int >& nums) {
		TreeNode* root = build (nums, 0, nums.size () - 1);
		return root;
	}
	TreeNode* build (vector< int >& nums, int low, int high) {
		if (low > high) return nullptr;
		int mid = (low + high) >> 1;
		TreeNode* node = new TreeNode (nums[mid]);
		node->left = build (nums, low, mid - 1);
		node->right = build (nums, mid + 1, high);
		return node;
	}
};
// @lc code=end
