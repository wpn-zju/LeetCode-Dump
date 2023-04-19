/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public class ListBlock
    {
        public int length;
        public ListNode prev;
        public ListNode start;
        public ListNode end;
        public ListNode next;

        public ListBlock()
        {
            length = 0;
            prev = start = end = next = null;
        }

        public ListBlock(ListNode prev, ListNode start, ListNode end, ListNode next)
        {
            this.prev = prev;
            this.start = start;
            this.end = end;
            this.next = next;
        }

        public void Reverse()
        {
            end.next = null;
            ListNode tmp = start;
            start = Reverse(start);
            end = tmp;
            // Console.WriteLine(start.val);
            // Console.WriteLine(end.val);
            if(prev!=null)
                prev.next = start;
            end.next = next;
        }
        
        private ListNode Reverse(ListNode head)
        {
            if (head == null || head.next == null)
                return head;
            ListNode newHead = Reverse(head.next);
            head.next.next = head;
            head.next = null;
            return newHead;
        }
    }

    public ListNode ReverseKGroup(ListNode head, int k)
    {
        if (k == 1 || head == null)
            return head;
        ListNode ptr, newHead = null;
        ptr = head;
        ListBlock listBlock = new ListBlock();
        listBlock.start = ptr;
        while (ptr != null)
        {
            if (listBlock.length == k)
            {
                listBlock.Reverse();
                if (newHead == null)
                    newHead = listBlock.start;
                listBlock.length = 0;
                listBlock.prev = listBlock.end;
                listBlock.start = listBlock.next;
                listBlock.end = null;
                listBlock.next = null;
            }
            listBlock.length++;
            listBlock.end = ptr;
            listBlock.next = ptr.next;
            ptr = ptr.next;
        }
        if (listBlock.length == k)
        {
            listBlock.Reverse();
            if (newHead == null)
                newHead = listBlock.start;
            listBlock.length = 0;
            listBlock.prev = listBlock.end;
            listBlock.start = listBlock.next;
            listBlock.end = null;
            listBlock.next = null;
        }
        if(newHead!=null)
        return newHead;
        else
            return head;
    }
}