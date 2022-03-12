/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.62%)
 * Likes:    2941
 * Dislikes: 75
 * Total Accepted:    229.5K
 * Total Submissions: 682.6K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * Example:
 *
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 *
 */

// @lc code=start
class Solution {
public:
	int largestRectangleArea (vector< int >& heights) {
		stack< int > stk;
		int ans = 0, n = heights.size ();
		int i = 0;
		while (i < n) {
			if (stk.empty () or heights[i] > heights[stk.top ()]) {
				stk.push (i);
				i++;
			} else {
				int x = stk.top ();
				stk.pop ();
				int area = heights[x] * (stk.empty () ? i : i - stk.top () - 1);
				ans = max (ans, area);
			}
		}
		while (!stk.empty ()) {
			int x = stk.top ();
			stk.pop ();
			int area = heights[x] * (stk.empty () ? n : n - stk.top () - 1);
			ans = max (ans, area);
		}
		return ans;
	}
};
// @lc code=end
