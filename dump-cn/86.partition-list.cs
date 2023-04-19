/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode Partition(ListNode head, int x)
    {
        if (head == null) return null;
        ListNode l1 = null, l2 = null;
        ListNode p1 = null, p2 = null;
        ListNode cur = head;
        while (cur != null)
        {
            if (cur.val < x)
            {
                if (p1 == null)
                {
                    p1 = cur;
                    l1 = p1;
                }
                else
                {
                    p1.next = cur;
                    p1 = p1.next;
                }
            }
            else
            {
                if (p2 == null)
                {
                    p2 = cur;
                    l2 = p2;
                }
                else
                {
                    p2.next = cur;
                    p2 = p2.next;
                }
            }
            cur = cur.next;
        }
        if(p1!=null)
        p1.next = null;
        if(p2!=null)
        p2.next = null;
        cur = l1;
        if (cur != null)
        {
            while (cur.next != null)
                cur = cur.next;
            cur.next = l2;
            return l1;
        }
        else
            return l2;
    }
}