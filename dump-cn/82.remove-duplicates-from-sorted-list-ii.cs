/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode DeleteDuplicates(ListNode head)
    {
        if (head == null) return null;
        ListNode prev = null, cur;
        bool toDelete = false;
        cur = head;
        while (cur.next != null)
        {
            if(cur.next.val == cur.val)
            {
                toDelete = true;
            }
            else
            {
                if (toDelete)
                {
                    if (prev == null)
                        head = cur.next;
                    else
                        prev.next = cur.next;
                    toDelete = false;
                }
                else
                    prev = cur;
            }
            cur = cur.next;
        }
        if (toDelete)
        {
            if (prev == null)
                head = cur.next; // indeed cur.next = null
            else
                prev.next = cur.next; // indeed cur.next = null
            toDelete = false;
        }
        return head;
    }
}