class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        ans = ListNode(0)
        ans.next = head
        flag = True
        while flag:
            h = ans
            d = {0: ans}
            t = 0
            flag = False
            while h.next:
                h = h.next
                t += h.val
                if t in d:
                    d[t].next = h.next
                    flag = True
                    break
                d[t] = h
        return ans.next