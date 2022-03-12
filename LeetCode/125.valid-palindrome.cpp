/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (34.38%)
 * Likes:    1002
 * Dislikes: 2677
 * Total Accepted:    528.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *4
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */

// @lc code=start
class Solution {
public:
	bool isPalindrome (string s) {
		if (!s.size ()) return true;
		int i = 0, j = s.size () - 1;
		bool pal = true;
		while (i < j) {
			if (!(s[i] >= 'a' and s[i] <= 'z') and !(s[i] >= 'A' and s[i] <= 'Z') and
				!(s[i] >= '0' and s[i] <= '9'))
				++i;
			else if (!(s[j] >= 'a' and s[j] <= 'z') and !(s[j] >= 'A' and s[j] <= 'Z') and
					 !(s[j] >= '0' and s[j] <= '9'))
				--j;
			else {
				int x;
				int y;
				if (s[i] >= 'A' and s[i] <= 'Z')
					x = s[i] - 'A';
				else
					x = s[i] - 'a';
				if (s[j] >= 'A' and s[j] <= 'Z')
					y = s[j] - 'A';
				else
					y = s[j] - 'a';
				if (x != y) {
					pal = false;
					break;
				}
				i++;
				j--;
			}
		}
		return pal;
	}
};
// @lc code=end
