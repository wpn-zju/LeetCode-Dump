public class Solution {
    public bool IsLongPressedName(string name, string typed)
    {
        int m = name.Length;
        int n = typed.Length;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 != m && ptr2 != n)
        {
            if(name[ptr1] != typed[ptr2])
                return false;
            char c = name[ptr1];
            while (ptr2 != n && typed[ptr2] == c)
            {
                if(ptr1 != m && name[ptr1] == c)
                    ptr1++;
                ptr2++;     
            }
        }
        if (ptr1 != m && ptr2 == n)
            return false;
        return true;
    }
}