/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode SortedArrayToBST(List<int> nums, int start, int end)
    {
        TreeNode node = null;
        if (end >= start)
        {
            int mid = start + (end - start >> 1);
            node = new TreeNode(nums[mid]);
            node.left = SortedArrayToBST(nums, start, mid - 1);
            node.right = SortedArrayToBST(nums, mid + 1, end);
        }
        return node;
    }

    public TreeNode SortedListToBST(ListNode head)
    {
        if (head == null)
            return null;
        List<int> vec = new List<int>();
        ListNode ptr = head;
        while (ptr != null)
        {
            vec.Add(ptr.val);
            ptr = ptr.next;
        }
        return SortedArrayToBST(vec, 0, vec.Count - 1);
    }
}