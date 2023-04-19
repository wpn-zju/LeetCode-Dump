/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int NumComponents(ListNode head, int[] G)
    {
        if (head == null)
            return 0;
        HashSet<int> set = new HashSet<int>();
        foreach (int i in G)
            set.Add(i);
        ListNode ptr = head;
        int count = 0;
        bool flag = false;
        while (ptr != null)
        {
            if(set.Contains(ptr.val))
                flag = true;
            else
            {
                if (flag)
                {
                    count++;
                    flag = false;
                }
            }
            ptr = ptr.next;
        }
        return flag ? count + 1 : count;
    }
}