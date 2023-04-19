/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int[] NextLargerNodes(ListNode head)
    {
        if (head == null)
            return null;
        List<ListNode> vec = new List<ListNode>();
        ListNode ptr = head;
        while (ptr != null)
        {
            vec.Add(ptr);
            ptr = ptr.next;
        }
        int[] result = new int[vec.Count];
        Stack<ListNode> s = new Stack<ListNode>();
        result[result.Length - 1] = 0;
        s.Push(vec[result.Length - 1]);
        for(int i = result.Length - 2; i >= 0; --i)
        {
            while (s.Count != 0)
            {
                if (s.Peek().val <= vec[i].val)
                    s.Pop();
                else
                    break;
            }
            if (s.Count == 0)
                result[i] = 0;
            else
                result[i] = s.Peek().val;
            s.Push(vec[i]);
        }
        return result;
    }
}