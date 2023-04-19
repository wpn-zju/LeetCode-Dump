/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public Dictionary<int, ListNode> listNodeMap1 = new Dictionary<int, ListNode>();
    public ListNode RemoveNthFromEnd(ListNode head, int n)
    {
        ListNode ptr = head;
        int count = 1;
        listNodeMap1[count] = ptr;
        while (ptr.next != null)
        {
            ptr = ptr.next;
            count++;
            listNodeMap1[count] = ptr;
        }
        int reverseN = count - n + 1;
        if (reverseN == 1)
            return head.next;
        if (listNodeMap1.ContainsKey(reverseN + 1))
            listNodeMap1[reverseN - 1].next = listNodeMap1[reverseN + 1];
        else
            listNodeMap1[reverseN - 1].next = null;
        return head;
    }
}