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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1, *p2, *p3 = NULL;
		ListNode *head = p3;
		p1 = l1;
		p2 = l2;
		do {
			ListNode* tmp = NULL;
			if (p1 && p2) {
				if (p1->val > p2->val) {
					tmp = new ListNode(p2->val);
					p2 = p2->next;
				}
				else {
					tmp = new ListNode(p1->val);
					p1 = p1->next;
				}
			}
			else if (p1 && !p2) {
				tmp = new ListNode(p1->val);
				p1 = p1->next;
			}
			else if (p2) {
				tmp = new ListNode(p2->val);
				p2 = p2->next;
			}
			if (p3 == NULL) {
				p3 = tmp;
				head = p3;
			}
			else {
				p3->next = tmp;
				p3 = p3->next;
			}
		} while (p1 || p2);
		
		return head;
	}
};