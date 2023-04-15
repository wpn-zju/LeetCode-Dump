public class Solution {
    public int GetByte(int num, int offset)
    {
        return (num & 1 << offset) >> offset;
    }
    
    public int FindComplement(int num)
    {
        int offset = 31;
        while (GetByte(num, offset) != 1)
            offset--;
        return num ^ ((1 << offset+1) - 1);
    }
}