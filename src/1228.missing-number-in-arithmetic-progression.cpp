class Solution {
public:
    int missingNumber(vector<int>& arr) {
        arr.push_back(arr.back() + arr[1] - arr[0]);
        for(int i = 0;i<arr.size() - 2;++i)
            if(arr[i + 1] - arr[i] == 2 * (arr[i + 2] - arr[i + 1]))
                return arr[i] + arr[i + 2] - arr[i + 1];
        return 0;
    }
};