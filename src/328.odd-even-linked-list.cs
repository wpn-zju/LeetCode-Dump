/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode OddEvenList(ListNode head)
    {
        if (head == null || head.next == null)
            return head;
        ListNode ptr1 = head;
        ListNode ptr2 = head.next;
        ListNode ptr3 = null;
        ListNode ptr4 = head.next;
        while (ptr2 != null && ptr2.next != null)
        {
            ptr3 = ptr2.next;
            ptr1.next = ptr3;
            ptr2.next = ptr3.next;
            ptr3.next = ptr2;
            ptr1 = ptr3;
            if (ptr2.next != null)
                ptr2 = ptr2.next;
        }
        if(ptr3!=null)
        ptr3.next = ptr4;
        return head;
    }
}