class Solution {
public:
    int calSum(vector<int>& nums, int t){
        int ret = 0;
        for(int& i : nums)
            ret += i / t + (i % t != 0);
        return ret;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = INT_MIN;
        for(int& i : nums)
            end = max(end, i);
        while(start < end){
            int mid = start + (end - start >> 1);
            int sum = calSum(nums, mid);
            if(sum <= threshold){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};