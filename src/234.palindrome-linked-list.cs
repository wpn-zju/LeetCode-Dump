/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head)
    {
        if (head == null || head.next == null)
            return head;
        ListNode newHead = ReverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
    
    public bool IsPalindrome(ListNode head)
    {
        if(head==null)
            return true;
        ListNode p1 = head, p2 = head;
        while (p2 != null && p2.next != null)
        {
            p1 = p1.next;
            p2 = p2.next.next;
        }
        p1 = ReverseList(p1); // L(P2) >= L(P1)
        p2 = head;
        while (p1 != null)
        {
            if (p1.val != p2.val)
                return false;
            p1 = p1.next;
            p2 = p2.next;
        }
        return true;
    }
}