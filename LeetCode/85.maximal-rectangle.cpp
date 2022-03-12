/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.11%)
 * Likes:    2189
 * Dislikes: 61
 * Total Accepted:    156.6K
 * Total Submissions: 433.7K
 * Testcase Example: '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 *
 *
 */

// @lc code=start
class Solution {
public:
	int maximalRectangle (vector< vector< char > >& matrix) {
		if (!matrix.size () or !matrix[0].size ()) return 0;
		int area = 0;
		vector< vector< int > > arr (matrix.size (), vector< int > (matrix[0].size (), 0));

		auto max_histogram_area = [&](int x) {
			stack< int > stk;
			int i = 0;
			while (i < matrix[0].size ()) {
				if (stk.empty () or arr[x][stk.top ()] <= arr[x][i]) {
					stk.push (i++);
				} else {
					int p = stk.top ();
					stk.pop ();
					int curr_area = arr[x][p] * (stk.empty () ? i : i - stk.top () - 1);
					area = max (area, curr_area);
				}
			}
			while (!stk.empty ()) {
				int p = stk.top ();
				stk.pop ();
				int curr_area = arr[x][p] * (stk.empty () ? i : i - stk.top () - 1);
				area = max (area, curr_area);
			}
		};

		for (int i = 0; i < matrix.size (); ++i) {
			if (i)
				for (int j = 0; j < matrix[0].size (); ++j) {
					if (matrix[i][j] == '1') {
						arr[i][j] = 1 + arr[i - 1][j];
					}
				}
			else
				for (int i = 0; i < matrix[0].size (); ++i) {
					if (matrix[0][i] == '1')
						arr[0][i] = 1;
					else
						arr[0][i] = 0;
				}
			max_histogram_area (i);
		}
		return area;
	}
};
// @lc code=end
