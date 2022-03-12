/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (37.44%)
 * Likes:    1885
 * Dislikes: 123
 * Total Accepted:    247K
 * Total Submissions: 659.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
class Solution {
public:
	ListNode* reverseBetween (ListNode* head, int m, int n) {
		int i = 0;
		ListNode* node = head;
		ListNode* prv = nullptr;
		while (node and i + 1 < m) {
			prv = node;
			node = node->next;
			i++;
		}
		ListNode *p = nullptr, *next;

		while (node and i < n) {
			next = node->next;
			node->next = p;
			p = node;
			node = next;
			++i;
		}
		if (prv) { // reversing from head
			prv->next->next = node;
			prv->next = p;
		} else {
			head->next = node;
			head = p;
		}
		return head;
	}
};
// @lc code=end
