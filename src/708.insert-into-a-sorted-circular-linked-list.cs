/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;

    public Node(){}
    public Node(int _val,Node _next) {
        val = _val;
        next = _next;
}
*/
public class Solution {
    public Node Insert(Node head, int insertVal)
    {
        if(head == null)
        {
            head = new Node();
            head.val = insertVal;
            head.next = head;
            return head;
        }
        Node prev = head;
        Node headStorage = head;
        head = head.next;
        Node newPt = null;
        do
        {
            if (prev.val <= insertVal && head.val >= insertVal)
            {
                newPt = new Node();
                newPt.val = insertVal;
                prev.next = newPt;
                newPt.next = head;
                break;
            }
            prev = head;
            head = head.next;
        }while (head != headStorage.next);
        if (newPt == null)
        {
            prev = headStorage;
            head = headStorage.next;
            do
            {
                if (prev.val > head.val)
                {
                    newPt = new Node();
                    newPt.val = insertVal;
                    prev.next = newPt;
                    newPt.next = head;
                    break;
                }
                prev = head;
                head = head.next;
            }while (head != headStorage.next);
        }
        if (newPt == null)
        {
            prev = headStorage;
            head = headStorage.next;
            while (true)
            {
                if (prev.val >= head.val)
                {
                    newPt = new Node();
                    newPt.val = insertVal;
                    prev.next = newPt;
                    newPt.next = head;
                    break;
                }
                prev = head;
                head = head.next;
            }
        }
        return headStorage;
    }
}