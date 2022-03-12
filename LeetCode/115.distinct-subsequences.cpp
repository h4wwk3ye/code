/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (36.95%)
 * Likes:    1012
 * Dislikes: 50
 * Total Accepted:    126.9K
 * Total Submissions: 342.2K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 *
 * Example 1:
 *
 *
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 *
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 *
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 *
 *
 * Example 2:
 *
 *
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 *
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 *
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 *
 *
 */

// @lc code=start
class Solution {
public:
	int numDistinct (string s, string t) {
		vector< vector< int > > dp (s.size () + 5, vector< int > (t.size () + 5, -1));
		return solve (s, t, 0, 0, dp);
	}
	int solve (string& s, string& t, int i, int j, vector< vector< int > >& dp) {
		if (j == t.size ()) return 1;
		if (i == s.size ()) return 0;
		int& ans = dp[i][j];
		if (ans != -1) return ans;

		if (s[i] == t[j]) {
			ans = solve (s, t, i + 1, j + 1, dp) + solve (s, t, i + 1, j, dp);
		} else {
			ans = solve (s, t, i + 1, j, dp);
		}
		return ans;
	}
};
// @lc code=end
