public class Solution {
    public char FindTheDifference(string s, string t)
    {
        int i1 = 0, i2 = 0;
        foreach(char a in s)
            i1 ^= (int)a;
        foreach (char a in t)
            i2 ^= (int)a;
        return (char)(i1 ^ i2);
    }
}