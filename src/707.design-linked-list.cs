    public class MyLinkedList
    {
        public ListNode head;
        public ListNode tail;

        public class ListNode
        {
            public int val;
            public ListNode prev;
            public ListNode next;

            public ListNode(int val)
            {
                this.val = val;
                prev = null;
                next = null;
            }
        }

        /** Initialize your data structure here. */
        public MyLinkedList()
        {
            head = tail = null;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        public int Get(int index)
        {
            if (head == null)
                return -1;
            ListNode ptr = head;
            while (ptr != null && index-- != 0)
                ptr = ptr.next;
            if (ptr == null)
                return -1;
            else
                return ptr.val;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        public void AddAtHead(int val)
        {
            ListNode ptr = new ListNode(val);
            ptr.next = head;
            if (head != null)
                head.prev = ptr;
            else
                tail = ptr;
            head = ptr;
        }

        /** Append a node of value val to the last element of the linked list. */
        public void AddAtTail(int val)
        {
            ListNode ptr = new ListNode(val);
            ptr.prev = tail;
            if (tail != null)
                tail.next = ptr;
            else
                head = ptr;
            tail = ptr;
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        public void AddAtIndex(int index, int val)
        {
            ListNode ptr = null;

            if (head == null)
                if (index <= 0)
                    head = tail = new ListNode(val);
                else
                    return;
            else
            {
                ptr = head;
                while (ptr != null && index-- != 0)
                    ptr = ptr.next;
                if (ptr != null)
                {
                    if (ptr.prev != null)
                    {
                        ptr.prev.next = new ListNode(val);
                        ptr.prev.next.prev = ptr.prev;
                        ptr.prev.next.next = ptr;
                        ptr.prev = ptr.prev.next;
                    }
                    else
                    {
                        head.prev = new ListNode(val);
                        head.prev.next = head;
                        head = head.prev;
                    }
                }
                else if (index == 0)
                {
                    tail.next = new ListNode(val);
                    tail.next.prev = tail;
                    tail = tail.next;
                }
            }
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        public void DeleteAtIndex(int index)
        {
            if (head == null)
                return;
            ListNode ptr = null;
            ptr = head;
            while (ptr != null && index-- != 0)
                ptr = ptr.next;
            if (ptr != null)
            {
                if (ptr.prev != null)
                    ptr.prev.next = ptr.next;
                else
                    head = ptr.next;
                if (ptr.next != null)
                    ptr.next.prev = ptr.prev;
                else
                    tail = ptr.prev;
            }
        }
    }