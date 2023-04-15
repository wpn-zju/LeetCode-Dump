static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	ListNode* head;
	Solution(ListNode* head) {
		this->head = head;
	}

	int getRandom() {
		int count = 1;
		ListNode *result = head, *cur = head;
		while (cur = cur->next)
			result = rand() % ++count ? result : cur;
		return result->val;
	}
};