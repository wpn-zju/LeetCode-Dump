/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode[] SplitListToParts(ListNode root, int k)
    {
        ListNode[] result = new ListNode[k];
        int count = 0;
        ListNode ptr = root;
        while (ptr != null)
        {
            count++;
            ptr = ptr.next;
        }
        int kdn = count / k;
        int mod = count % k;
        ListNode ptr2 = ptr = root;
        int total = k;
        while (k-- != 0)
        {
            int tmp = kdn;
            while (--tmp > 0)
                ptr = ptr.next;
            if (kdn != 0 && mod-- > 0)
                ptr = ptr.next;

            // 前一段已经完毕 后面还有新段
            if (ptr != null && ptr.next != null)
            {
                ListNode nP = ptr.next;
                ptr.next = null;
                ptr = nP;
                result[total - k - 1] = ptr2;
                ptr2 = ptr;
            }
            // 前一段已经完毕 后面没有新段
            else
            {
                result[total - k - 1] = ptr2;
                ptr2 = ptr = null;
            }
        }
        return result;
    }
}