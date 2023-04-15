/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode RemoveElements(ListNode head, int val)
    {
        if (head == null)
            return head;
        head.next = RemoveElements(head.next, val);
        if (head.val == val)
            return head.next;
        else
            return head;
    }
}