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
    
    public void ReorderList(ListNode head)
    {
        if (head == null || head.next == null)
            return;
        ListNode ptr = head;
        int count = 0;
        while (ptr != null)
        {
            count++;
            ptr = ptr.next;
        }
        // Console.WriteLine(count);
        ptr = head;
        int halfCount = count / 2;
        while (--halfCount!=0)
        {
            ptr = ptr.next;
        }
        ListNode midNode = ptr.next;
        if (count % 2 == 0)
            ptr = ReverseList(midNode);
        else
            ptr = ReverseList(midNode);
        midNode.next = null;
        ListNode ptr2 = head;
        // Console.WriteLine(ptr.val);
        // Console.WriteLine(ptr2.val);
        while (ptr2.next != null && ptr.next != null)
        {
            ListNode p1 = ptr2.next, p2 = ptr.next;
            ptr2.next = ptr;
            ptr.next = p1;
            ptr2 = p1;
            ptr = p2;
        }
    }
}