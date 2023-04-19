public class Solution {
    public int IntegerReplacement(int n)
    {
        if(n==0x7fffffff)
            return 32; 
        int count = 0;
        while (n != 1)
        {
            if(n==3){
                n/=3;
                count+=2;
            }
            else{
                if ((n&1) == 0)
                    n /= 2;
                else if ((n&2) == 0)
                    n--;
                else
                    n++;
                count++;
            }
        }
        return count;
    }
}