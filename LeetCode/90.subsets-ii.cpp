/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (45.47%)
 * Likes:    1384
 * Dislikes: 61
 * Total Accepted:    254.7K
 * Total Submissions: 559.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
	vector< vector< int > > subsetsWithDup (vector< int >& nums) {
		set< vector< int > > ans;
		solve (nums, ans, 0, {});
		vector< vector< int > > op;
		for (auto& i : ans)
			op.push_back (i);
		return op;
	}
	void solve (vector< int >& nums, set< vector< int > >& ans, int i, vector< int > curr) {
		if (i == nums.size ()) {
			sort (curr.begin (), curr.end ());
			ans.insert (curr);
			return;
		}
		solve (nums, ans, i + 1, curr);
		curr.push_back (nums[i]);
		solve (nums, ans, i + 1, curr);
	}
};
// @lc code=end
