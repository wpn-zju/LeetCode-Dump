/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode InsertionSortList(ListNode head)
    {
        if (head == null || head.next == null)
            return head;
        ListNode ptr1 = head;
        ListNode ptr2 = head;
        ListNode prevPtr1 = null;
        while (ptr2 != null && ptr2.next != null)
        {
            if (ptr2.next.val >= ptr2.val)
            {
                ptr2 = ptr2.next;
                continue;
            }
            while (ptr1.val < ptr2.next.val)
            {
                prevPtr1 = ptr1;
                ptr1 = ptr1.next;
            }
            ListNode cur = ptr2.next;
            if (prevPtr1 == null)
            {
                ptr2.next = cur.next;
                cur.next = head;
                head = cur;
            }
            else
            {
                ptr2.next = cur.next;
                prevPtr1.next = cur;
                cur.next = ptr1;
            }
            prevPtr1 = null;
            ptr1 = head;
        }
        return head;
    }
}