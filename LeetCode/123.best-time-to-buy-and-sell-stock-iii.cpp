/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (36.19%)
 * Likes:    1785
 * Dislikes: 69
 * Total Accepted:    196.5K
 * Total Submissions: 539.7K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 *
 *
 * Example 3:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 */

// @lc code=start
class Solution {
public:
	int maxProfit (vector< int >& prices) {
		vector< vector< int > > dp (prices.size (), vector< int > (4, -1));
		int ans = solve (0, 0, prices, dp);
		return ans;
	}
	int solve (int i, int j, vector< int >& prices, vector< vector< int > >& dp) {
		if (i == prices.size () or j == 4) return 0;
		int& ans = dp[i][j];
		if (ans != -1) return ans;
		if (!(j & 1)) {
			ans = max (solve (i + 1, j, prices, dp), solve (i + 1, j + 1, prices, dp) - prices[i]);
		} else {
			ans = max (solve (i + 1, j, prices, dp), solve (i + 1, j + 1, prices, dp) + prices[i]);
		}
		return ans;
	}
};
// @lc code=end
