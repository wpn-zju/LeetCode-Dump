class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        bool ok = false;
        ListNode *header = new ListNode(0);
        
        header->next = head;
        
        while (!ok) {
            int sum = 0;
            unordered_map<int, ListNode*> sum2node;

            ok = true;

            for (auto *iter = header; iter != nullptr; iter = iter->next) {
                sum += iter->val;
                if (sum2node[sum] != nullptr) {
                    ok = false;

                    int tmpSum = sum;
                    auto left = sum2node[sum], right = iter->next;
                    for (auto iter = left->next; iter != right; iter = iter->next)
                        sum2node[tmpSum += iter->val] = nullptr;

                    left->next = right;
                    sum2node[sum] = left;
                } else sum2node[sum] = iter;
            }
        }

        return header->next;
    }
};