/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (45.29%)
 * Likes:    1637
 * Dislikes: 82
 * Total Accepted:    223.6K
 * Total Submissions: 491.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted linked list: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST (ListNode* head) {
		TreeNode* root = build (head, nullptr);
		return root;
	}
	TreeNode* build (ListNode* head, ListNode* tail) {
		if (head == tail) return nullptr;
		ListNode *slow = head, *fast = head;
		while (fast != tail and fast->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* node = new TreeNode (slow->val);
		node->left = build (head, slow);
		node->right = build (slow->next, tail);
		return node;
	}
};
// @lc code=end
