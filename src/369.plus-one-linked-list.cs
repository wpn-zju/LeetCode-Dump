/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode PlusOne(ListNode head)
    {
        ListNode slow = head, fast = head;
        while (fast != null)
        {
            if (fast.val != 9)
                slow = fast;
            fast = fast.next;
        }
        if (slow == head && slow.val == 9)
        {
            head = new ListNode(1);
            head.next = slow;
        }
        else
        {
            slow.val++;
            slow = slow.next;
        }
        while (slow != null)
        {
            slow.val = 0;
            slow = slow.next;
        }
        return head;
    }
}