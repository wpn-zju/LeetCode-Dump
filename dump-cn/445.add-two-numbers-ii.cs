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
    
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        Stack<int> s1 = new Stack<int>(), s2 = new Stack<int>();
        ListNode ptr = l1;
        while (ptr != null)
        {
            s1.Push(ptr.val);
            ptr = ptr.next;
        }
        ptr = l2;
        while (ptr != null)
        {
            s2.Push(ptr.val);
            ptr = ptr.next;
        }
        ListNode newHead = null;
        bool overflow = false;
        while (s1.Count != 0 || s2.Count != 0)
        {
            int digit = overflow ? 1 : 0;
            overflow = false;
            if (s1.Count != 0)
                digit += s1.Pop();
            if (s2.Count != 0)
                digit += s2.Pop();
            if (digit > 9)
                overflow = true;
            ListNode ln = new ListNode(digit % 10);
            if (newHead == null)
            {
                newHead = ln;
                ptr = newHead;
            }
            else
            {
                ptr.next = ln;
                ptr = ptr.next;
            }
        }
        if (overflow)
            ptr.next = new ListNode(1);
        return ReverseList(newHead);
    }
}