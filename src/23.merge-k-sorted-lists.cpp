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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode vHead(0), *p = &vHead;
		auto cmp = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>heap(cmp);
		for (ListNode *node : lists) 
			if (node)
				heap.push(node);
		while (!heap.empty()) {
			ListNode *tmp = heap.top(); 
			heap.pop();
			p = p->next = tmp;
			if (tmp->next)
				heap.push(tmp->next);
		}
		return vHead.next;
	}
};