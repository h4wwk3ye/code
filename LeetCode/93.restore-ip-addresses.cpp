/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.92%)
 * Likes:    1002
 * Dislikes: 454
 * Total Accepted:    174.1K
 * Total Submissions: 512.7K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * Example:
 *
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 *
 *
 */

// @lc code=start
class Solution {
public:
	vector< string > restoreIpAddresses (string s) {
		vector< string > ans;
		if (s.size () > 12) return ans;
		solve (s, ans, 0, 0, "");
		sort (ans.begin (), ans.end ());
		return ans;
	}
	void solve (string& s, vector< string >& ans, int i, int j, string curr) {
		if (j > 3) return;
		if (i == s.size ()) {
			if (j != 3) return;
			string c;
			bool f = 1;
			for (auto& k : curr) {
				if (k == '.') {
					if (!c.size ()) f = 0;
					if (!f) break;
					long long x = stoll (c);
					if (c[0] == '0' and c.size () > 1) f = 0;
					if (x > 255) f = 0;
					c = "";
				} else {
					c += k;
					if (c.size () > 3) {
						f = 0;
						break;
					}
				}
			}
			if (!c.size () or c.size () > 3) f = 0;
			if (!f) return;
			long long x = stoll (c);
			if (c[0] == '0' and c.size () > 1) f = 0;
			if (x > 255) f = 0;

			if (f) ans.push_back (curr);
			return;
		}
		solve (s, ans, i + 1, j, curr + s[i]);
		solve (s, ans, i, j + 1, curr + '.');
	}
};
// @lc code=end
