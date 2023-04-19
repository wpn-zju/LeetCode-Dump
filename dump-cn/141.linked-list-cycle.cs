/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head)
    {
        ListNode p1 = head, p2 = head;
        do
        {        
            if (p1 == null || p2 == null || p2.next == null || p2.next.next == null)
                return false;
            p1 = p1.next;
            p2 = p2.next.next;

        } while (p1.val != p2.val);
        return true;
    }
}