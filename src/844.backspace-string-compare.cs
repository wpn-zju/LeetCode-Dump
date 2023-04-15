public class Solution {
    public bool BackspaceCompare(string S, string T)
    {
        Stack<char> s1 = new Stack<char>();
        Stack<char> s2 = new Stack<char>();
        foreach (char c in S)
            if (c == '#')
            {
                if(s1.Count > 0)
                    s1.Pop();
            }
            else
                s1.Push(c);
        foreach (char c in T)
            if (c == '#')
            {
                if(s2.Count > 0)
                    s2.Pop();
            }
            else
                s2.Push(c);
        while (s1.Count != 0 && s2.Count != 0)
        {
            if (s1.Peek() == s2.Peek())
            {
                s1.Pop();
                s2.Pop();
            }
            else
                return false;
        }
        return s1.Count == s2.Count ? true : false;
    }
}