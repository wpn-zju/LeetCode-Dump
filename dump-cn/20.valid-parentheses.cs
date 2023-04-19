public class Solution {
    public bool IsValid(string s)
    {
        int m = s.Length;
        if(m == 0)
            return true;
        if (m < 2 || m % 2 == 1)
            return false;
        int i = 0;
        Stack<char> s1 = new Stack<char>();
        while (i < m)
        {
            switch (s[i])
            {
                case '(':
                    s1.Push(s[i]);
                    break;
                case '[':
                    s1.Push(s[i]);
                    break;
                case '{':
                    s1.Push(s[i]);
                    break;
                case ')':
                    if (s1.Count != 0 && s1.Peek() == '(')
                        s1.Pop();
                    else
                        return false;
                    break;
                case ']':
                    if (s1.Count != 0 && s1.Peek() == '[')
                        s1.Pop();
                    else
                        return false;
                    break;
                case '}':
                    if (s1.Count != 0 && s1.Peek() == '{')
                        s1.Pop();
                    else
                        return false;
                    break;
            }
            ++i;
        }
        return s1.Count == 0;
    }
}