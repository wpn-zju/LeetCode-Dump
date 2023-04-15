class Solution {
public:
    int gcd(int x, int y){
        while(x)
            swap(x, y %= x);
        return y;
    }
    
    bool isGoodArray(vector<int>& nums) {
        int t = nums[0];
        for(int i = 1;i<nums.size();++i)
            t = gcd(t, nums[i]);
        return t == 1;
    }
};