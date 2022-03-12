/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (49.90%)
 * Likes:    2655
 * Dislikes: 99
 * Total Accepted:    256.1K
 * Total Submissions: 512.5K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
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
class Solution {
public:
	int numTrees (int n) {
		vector< int > dp (n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {			// total i nodes in current tree
			for (int j = 1; j <= i; ++j) {		// jth node is the root
				dp[i] += dp[j - 1] * dp[i - j]; // j-1 in left subtree and i - j in the right subtree
			}
		}
		return dp[n];
	}
};
// @lc code=end
