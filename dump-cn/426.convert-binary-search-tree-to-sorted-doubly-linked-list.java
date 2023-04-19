/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
        public Node DLHead = null, prev = null, cur = null;
        public Node treeToDoublyList(Node root)
        {
            if (root == null)
                return null;
            DFS(root);
            DLHead.left = cur;
            cur.right = DLHead;
            return DLHead;
        }

        public void DFS(Node root)
        {
            if (root == null)
                return;
            DFS(root.left);
            prev = cur;
            cur = root;
            if (DLHead == null)
                DLHead = root;
            if (prev != null)
                prev.right = cur;
            cur.left = prev;
            DFS(root.right);
        }
}