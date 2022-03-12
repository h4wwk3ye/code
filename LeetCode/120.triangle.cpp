/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (42.52%)
 * Likes:    1693
 * Dislikes: 205
 * Total Accepted:    230.9K
 * Total Submissions: 539.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */

// @lc code=start
class Solution {
public:
	int minimumTotal (vector< vector< int > >& triangle) {
		if (!triangle.size ()) return 0;
		vector< vector< int > > dp (triangle.size ());
		for (int i = 0; i < triangle.size (); ++i) {
			dp[i].assign (triangle[i].size (), -1);
		}
		int ans = solve (0, 0, triangle, dp);
		return ans;
	}
	int solve (int i, int j, vector< vector< int > >& t, vector< vector< int > >& dp) {
		if (i == t.size ()) return 0;
		if (j < 0 or j >= t[i].size ()) return 1e9;
		int& ans = dp[i][j];
		if (ans != -1) return ans;
		ans = min (solve (i + 1, j, t, dp) + t[i][j], solve (i + 1, j + 1, t, dp) + t[i][j]);
		return ans;
	}
};
// @lc code=end
