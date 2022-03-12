/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (20.68%)
 * Likes:    1557
 * Dislikes: 227
 * Total Accepted:    169.8K
 * Total Submissions: 806.8K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 *
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return an empty list if there is no such transformation sequence.
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
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
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
 * Output: []
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
	vector< vector< string > > findLadders (string beginWord, string endWord, vector< string >& wordList) {
		unordered_set< string > dict (wordList.begin (), wordList.end ());
		if (dict.find (endWord) == dict.end ()) return {};

		unordered_map< string, vector< string > > children;
		bool possible = bfs (beginWord, endWord, wordList, children, dict);
		if (!possible) return {};

		vector< vector< string > > ans;
		vector< string > tmp;
		tmp.push_back (beginWord);
		dfs (beginWord, endWord, children, ans, tmp);
		return ans;
	}

	bool bfs (string& beginWord,
			  string& endWord,
			  vector< string >& wordList,
			  unordered_map< string, vector< string > >& children,
			  unordered_set< string >& dict) {
		unordered_set< string > current, next;
		current.insert (beginWord);
		while (true) {
			for (string word : current) {
				dict.erase (word);
			}

			for (string word : current) {
				string parent = word;
				for (int i = 0; i < word.size (); i++) {
					char t = word[i];
					for (int j = 0; j < 26; j++) {
						word[i] = 'a' + j;
						if (dict.find (word) != dict.end ()) {
							next.insert (word);
							children[parent].push_back (word);
						}
					}
					word[i] = t;
				}
			}

			if (next.empty ()) return false;

			if (next.find (endWord) != next.end ()) return true;
			current.clear ();
			swap (current, next);
		}

		return false;
	}


	void dfs (string& curr,
			  string& endWord,
			  unordered_map< string, vector< string > >& children,
			  vector< vector< string > >& ans,
			  vector< string > tmp) {
		if (curr == endWord) {
			ans.push_back (tmp);
			return;
		}
		for (auto& word : children[curr]) {
			tmp.push_back (word);
			dfs (word, endWord, children, ans, tmp);
			tmp.pop_back ();
		}
	}
};
// @lc code=end
