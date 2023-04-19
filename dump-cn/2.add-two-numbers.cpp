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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int temp = 0;
		ListNode *head, *p, *s, *p1, *p2;
		head = new ListNode((l1->val + l2->val) % 10);
		p = head;
		p1 = l1;
		p2 = l2;
		if (l1->val + l2->val >= 10)
			temp = 1;
		if (p1 != NULL)
			p1 = p1->next;
		if (p2 != NULL)
			p2 = p2->next;

		while (1)
		{
			if (p1 != NULL && p2 != NULL)
			{
				s = new ListNode((p1->val + p2->val + temp) % 10);
				if (p1->val + p2->val + temp >= 10)
					temp = 1;
				else
					temp = 0;
				p->next = s;
				p = p->next;
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1 != NULL)
			{
				s = new ListNode((p1->val + temp) % 10);
				if (p1->val + temp >= 10)
					temp = 1;
				else
					temp = 0;
				p->next = s;
				p = p->next;
				p1 = p1->next;
			}
			else if (p2 != NULL)
			{
				s = new ListNode((p2->val + temp) % 10);
				if (p2->val + temp >= 10)
					temp = 1;
				else
					temp = 0;
				p->next = s;
				p = p->next;
				p2 = p2->next;
			}
			else
				break;
		}

		if (temp == 1)
		{
			s = new ListNode(1);
			p->next = s;
			p = p->next;
		}

		return head;
	}
};