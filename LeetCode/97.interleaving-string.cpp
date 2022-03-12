/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (30.24%)
 * Likes:    1180
 * Dislikes: 71
 * Total Accepted:    139.8K
 * Total Submissions: 461.5K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 *
 * Example 1:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 *
 */

// @lc code=start
class Solution {
public:
	bool isInterleave (string s1, string s2, string s3) {
		if (s1.size () + s2.size () != s3.size ()) return false;
		vector< vector< int > > dp (s1.size () + 1, vector< int > (s2.size () + 1, -1));
		int ans = solve (s1, s2, s3, dp, 0, 0);
		return ans;
	}
	int solve (string& s1, string& s2, string& s3, vector< vector< int > >& dp, int i, int j) {
		if (i + j == s3.size ()) return true;
		int& ans = dp[i][j];
		if (ans != -1) return ans;

		if (i == s1.size ()) {
			if (s3[i + j] == s2[j]) {
				ans = solve (s1, s2, s3, dp, i, j + 1);
			} else {
				ans = 0;
			}
			return ans;
		}

		if (j == s2.size ()) {
			if (s3[i + j] == s1[i]) {
				ans = solve (s1, s2, s3, dp, i + 1, j);
			} else {
				ans = 0;
			}
			return ans;
		}

		if (s3[i + j] == s1[i] and s3[i + j] == s2[j]) {
			ans = solve (s1, s2, s3, dp, i + 1, j) or solve (s1, s2, s3, dp, i, j + 1);
		} else if (s3[i + j] == s1[i]) {
			ans = solve (s1, s2, s3, dp, i + 1, j);
		} else if (s3[i + j] == s2[j]) {
			ans = solve (s1, s2, s3, dp, i, j + 1);
		} else {
			ans = 0;
		}
		return ans;
	}
};
// @lc code=end
