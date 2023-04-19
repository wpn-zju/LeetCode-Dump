/*
// Definition for a Node.
public class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node(){}
    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
}
*/
public class Solution {
        public Node Flatten(Node head)
        {            
            if (head == null)
                return null;
            DFS(head);
            return head;
        }

        public Node DFS(Node head)
        {
            if (head.next == null && head.child == null)
                return head;
            if (head.child != null)
            {
                Node dfs = DFS(head.child);
                if (head.next != null)
                    head.next.prev = dfs;
                dfs.next = head.next;
                head.next = head.child;
                head.child.prev = head;
                head.child = null;
                if (dfs.next != null)
                    return DFS(dfs.next);
                else
                    return dfs;
            }
            else
                return DFS(head.next);
        }
}