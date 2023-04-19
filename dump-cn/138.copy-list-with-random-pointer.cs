/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node(){}
    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
}
*/
public class Solution {
    public Node CopyRandomList(Node head)
    {
        if(head==null)
            return null;
        Dictionary<Node, Node> nMap = new Dictionary<Node, Node>();
        Node tmp = head;
        Node last = null;
        while (head != null)
        {
            Node nd = new Node(head.val, null, null);
            if (last != null)
                last.next = nd;
            last = nd;
            nMap[head] = nd;
            head = head.next;
        }
        head = tmp;
        while (head != null)
        {
            Node nd = nMap[head];
            if(head.random!=null)
            nd.random = nMap[head.random];
            head = head.next;
        }
        return nMap[tmp];
    }
}