/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (50.40%)
 * Likes:    1163
 * Dislikes: 95
 * Total Accepted:    347.8K
 * Total Submissions: 686K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
	vector< vector< int > > generate (int numRows) {
		vector< vector< int > > ans;
		if (!numRows) return ans;

		ans.push_back ({1});
		for (int i = 1; i < numRows; ++i) {
			ans.push_back ({1});
			for (int j = 1; j <= i; ++j) {
				if (j == ans[i - 1].size ()) {
					ans.back ().push_back (1);
				} else {
					ans.back ().push_back (ans[i - 1][j - 1] + ans[i - 1][j]);
				}
			}
		}
		return ans;
	}
};
// @lc code=end
