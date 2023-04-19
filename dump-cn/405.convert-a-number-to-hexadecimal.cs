public class Solution {
    public string ToHex(int num)
    {
        if(num==0)
            return "0";
        uint unum = (uint)num;
        string result = "";
        uint[] i = new uint[8] { unum >> 28, (unum << 4) >> 28, (unum << 8) >> 28, (unum << 12) >> 28, (unum << 16) >> 28, (unum << 20) >> 28, (unum << 24) >> 28, (unum << 28) >> 28 };
        string s = "0123456789abcdef";
        foreach(uint j in i)
            result += s[(int)j];
        int offset = 0;
        while (result[offset] == '0')
            offset++;
        return result.Substring(offset, result.Length - offset);
    }
}