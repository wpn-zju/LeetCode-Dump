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
    int sum = 0;
    public TreeNode BstToGst(TreeNode root)
    {
        myOrder(root);
        return root;
    }

    // Traversal with order right->root->left
    public void myOrder(TreeNode root)
    {
        if (root == null)
            return;
        myOrder(root.right);
        sum += root.val;
        root.val = sum;
        myOrder(root.left);
    }
}