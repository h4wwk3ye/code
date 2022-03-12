/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (38.75%)
 * Likes:    1803
 * Dislikes: 146
 * Total Accepted:    174.3K
 * Total Submissions: 449.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
	vector< TreeNode* > generateTrees (int n) {
		vector< TreeNode* > ans;
		if (!n) return ans;
		ans = solve (1, n);
		return ans;
	}
	vector< TreeNode* > solve (int start, int end) {
		vector< TreeNode* > ans;
		if (start > end) {
			ans.push_back (nullptr);
			return ans;
		}
		for (int i = start; i <= end; ++i) {
			vector< TreeNode* > leftSubTree = solve (start, i - 1);
			vector< TreeNode* > rightSubTree = solve (i + 1, end);

			for (auto& j : leftSubTree) {
				for (auto& k : rightSubTree) {
					TreeNode* node = new TreeNode (i);
					node->left = j;
					node->right = k;
					ans.push_back (node);
				}
			}
		}
		return ans;
	}
};
// @lc code=end
