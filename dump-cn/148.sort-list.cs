/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode SortList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode ptr1 = head;
        ListNode ptr2 = GetMid(head);
        ptr1 = SortList(ptr1);
        ptr2 = SortList(ptr2);
        return Merge(ptr1, ptr2);
    }
    
    public ListNode Merge(ListNode ptr1, ListNode ptr2){
        ListNode newHead = new ListNode(-1);
        ListNode newTail = newHead;
        while(ptr1!=null&&ptr2!=null){
            if(ptr1.val <= ptr2.val){
                newTail.next = ptr1;
                ptr1 = ptr1.next;
            }
            else{
                newTail.next = ptr2;
                ptr2 = ptr2.next;
            }
            newTail = newTail.next;
            newTail.next = null;
        }
        if(ptr1!=null)
            newTail.next = ptr1;
        if(ptr2!=null)
            newTail.next = ptr2;
        return newHead.next;
    }
    
    public ListNode GetMid(ListNode head){
        ListNode fast = head.next;
        ListNode slow = head.next;
        ListNode prev = head;
        while(true){
            if(fast == null)
                break;
            fast = fast.next;
            if(fast==null)
                break;
            fast = fast.next;
            prev = slow;
            slow = slow.next;
        }
        prev.next = null;
        return slow;
    }
}