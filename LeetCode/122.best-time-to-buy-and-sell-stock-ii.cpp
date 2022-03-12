/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (54.52%)
 * Likes:    2058
 * Dislikes: 1678
 * Total Accepted:    549.6K
 * Total Submissions: 987.1K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array prices for which the i^th element is the price of a
 * given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 *
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
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 3 * 10 ^ 4
 * 0 <= prices[i] <= 10 ^ 4
 *
 *
 */

// @lc code=start
class Solution {
public:
	int maxProfit (vector< int >& prices) {
		vector< vector< int > > dp (prices.size (), vector< int > (2, -1));
		int ans = solve (0, 0, prices, dp);
		return ans;
	}
	int solve (int i, int j, vector< int >& prices, vector< vector< int > >& dp) {
		if (i == prices.size ()) return 0;
		int& ans = dp[i][j];
		if (ans != -1) return ans;
		if (!j) {
			ans = max (solve (i + 1, j, prices, dp), solve (i + 1, 1 ^ j, prices, dp) - prices[i]);
		} else {
			ans = max (solve (i + 1, j, prices, dp), solve (i + 1, 1 ^ j, prices, dp) + prices[i]);
		}
		return ans;
	}
};
// @lc code=end
