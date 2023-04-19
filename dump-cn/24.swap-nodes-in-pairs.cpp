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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return head;
		ListNode* newHead = head->next;
		ListNode* prev = NULL;
		ListNode* cur = head;
		ListNode* next = cur->next;
		ListNode* next2 = next == NULL ? NULL : next->next;
		while (next != NULL && next2 != NULL) {
			if (prev != NULL)
				prev->next = next;
			next->next = cur;
			cur->next = next2;
			prev = cur;
			cur = next2;
			next = cur->next;
			next2 = next == NULL ? NULL : next->next;
		}
		if (next!=NULL && next2 == NULL) {
			if (prev != NULL)
				prev->next = next;
			cur->next = NULL;
			next->next = cur;
		}
		return newHead == NULL ? head : newHead;
	}
};