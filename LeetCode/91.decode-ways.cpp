/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.75%)
 * Likes:    2196
 * Dislikes: 2446
 * Total Accepted:    352.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */

// @lc code=start
class Solution {
public:
	int numDecodings (string s) {
		vector< int > dp (s.size (), -1);
		int ans = solve (s, 0, dp);
		return ans;
	}
	int solve (string& s, int i, vector< int >& dp) {
		if (i < s.size () and s[i] == '0') return 0;
		if (i == s.size ()) return 1;
		int& ans = dp[i];
		if (ans != -1) return ans;
		ans = solve (s, i + 1, dp);
		if (i + 1 < s.size () and ((s[i] - '0' == 2 and s[i + 1] - '0' <= 6) or (s[i] - '0' == 1)))
			ans += solve (s, i + 2, dp);
		return ans;
	}
};
// @lc code=end
