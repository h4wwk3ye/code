/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (47.23%)
 * Likes:    696
 * Dislikes: 193
 * Total Accepted:    263.7K
 * Total Submissions: 553.8K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

// @lc code=start
class Solution {
public:
	vector< int > getRow (int rowIndex) {
		vector< int > ans;
		vector< int > tmp;
		for (int i = 0; i <= rowIndex; ++i) {
			tmp = ans;
			ans.push_back (1);
			for (int j = ans.size () - 2; j > 0; --j) {
				ans[j] = tmp[j] + tmp[j - 1];
			}
		}
		return ans;
	}
};
// @lc code=end
