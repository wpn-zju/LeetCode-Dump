/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head)
    {
        ListNode p1 = head, p2 = head;
        do
        {
            if (p1 == null || p2 == null || p2.next == null || p2.next.next == null)
                return null;
            p1 = p1.next;
            p2 = p2.next.next;

        } while (p1 != p2);
        ListNode p3 = head;
        while (p1 != p3)
        {
            p1 = p1.next;
            p3 = p3.next;
        }
        return p1;
    }

    public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
    {
        if(headA==null||headB==null)
            return null;
        ListNode ln = headA;
        while (ln.next != null)
            ln = ln.next;
        ln.next = headB;
        ListNode result = DetectCycle(headA);
        ln.next = null;
        return result;
    }
}