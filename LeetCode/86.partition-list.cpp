/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (39.95%)
 * Likes:    1028
 * Dislikes: 261
 * Total Accepted:    198K
 * Total Submissions: 495.7K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
	ListNode* partition (ListNode* head, int x) {
		if (!head) return head;
		ListNode *node = head, *less = nullptr, *prv = nullptr;
		while (node) {
			if (node->val < x) { // place node at less
				if (!prv) {
					less = node;
					node = node->next;
					continue;
				}
				prv->next = node->next;
				if (!less) {
					node->next = head;
					head = node;
					less = head;
					node = prv->next;
				} else {
					node->next = less->next;
					less->next = node;
					less = node;
					node = prv->next;
				}
			} else {
				prv = node;
				node = node->next;
			}
		}
		return head;
	}
};
// @lc code=end
