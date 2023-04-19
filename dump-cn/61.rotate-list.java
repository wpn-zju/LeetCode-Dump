/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;
        ListNode ptr = head;
        ListNode prev = head;
        int count = 1;
        while (prev.next != null)
        {
            count++;
            prev = prev.next;
        }
        ListNode end = prev;
        prev = head;

        k %= count;
        if (k == 0)
            return head;
        k = count - k + 1;

        for (int i = 1; i < k; ++i)
        {
            prev = ptr;
            ptr = ptr.next;
        }
        prev.next = null;
        end.next = head;
        return ptr;
    }
}