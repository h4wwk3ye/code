/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (27.85%)
 * Likes:    2695
 * Dislikes: 1063
 * Total Accepted:    387.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
	int ladderLength (string& beginWord, string endWord, vector< string >& wordList) {
		unordered_set< string > dict (wordList.begin (), wordList.end ());

		return bfs (beginWord, endWord, wordList, dict);
	}

	int bfs (string& beginWord, string& endWord, vector< string >& wordList, unordered_set< string >& dict) {
		queue< string > q;
		q.push (beginWord);
		int ans = 1;
		while (!q.empty ()) {
			int n = q.size ();
			for (int l = 0; l < n; ++l) {
				string word = q.front ();
				dict.erase (word);
				if (word == endWord) return ans;
				q.pop ();
				for (int i = 0; i < word.size (); i++) {
					char t = word[i];
					for (int j = 0; j < 26; j++) {
						word[i] = 'a' + j;
						if (dict.find (word) != dict.end ()) {
							q.push (word);
						}
					}
					word[i] = t;
				}
			}
			ans++;
		}
		return 0;
	}
};
// @lc code=end
