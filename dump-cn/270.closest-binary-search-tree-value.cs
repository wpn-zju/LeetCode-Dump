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
    public int ClosestValue(TreeNode root, double target)
    {
        double minDiff = double.MaxValue;
        int coresVal = root.val;
        while (true)
        {
            if (Math.Abs(root.val - target) < minDiff)
            {
                minDiff = Math.Abs(root.val - target);
                coresVal = root.val;
            }
            if (root.val > target)
            {
                if (root.left != null)
                    root = root.left;
                else
                    break;
            }
            else
            {
                if (root.right != null)
                    root = root.right;
                else
                    break;
            }
        }
        return coresVal;
    }
}