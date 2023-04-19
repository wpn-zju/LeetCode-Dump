/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head)
    {
        if (head == null || head.next == null)
            return head;
        ListNode newHead = reverseList(head.next);
        head.next.next=head;
        head.next=null;
        return newHead;
    }
    
    public ListNode reverseBetween(ListNode head, int m, int n)
    {
        if (head == null || head.next == null)
            return head;
        ListNode ln1 = null, ln2 = null, ln3 = null, ln4 = null;
        ListNode prev = null, cur = head;
        int count = 0;
        while (true)
        {
            count++;
            if (count == m)
            {
                ln1 = prev;
                ln2 = cur;
            }
            if (count == n)
            {
                ln3 = prev;
                ln4 = cur;
            }
            if (cur != null)
            {
                prev = cur;
                cur = cur.next;
            }
            else
                break;
        }
        ListNode end = ln4.next;
        ln4.next = null;
        ListNode newHead = reverseList(ln2);
        if (ln1 != null)
        {
            ln1.next.next = end;
            ln1.next = newHead;
            return head;
        }
        else
        {
            ln2.next = end;
            return newHead;
        }
    }
}