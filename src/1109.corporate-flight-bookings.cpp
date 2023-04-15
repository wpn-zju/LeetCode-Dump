class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n + 1, 0);
        for(vector<int>& vec : bookings){
            result[vec[0] - 1] += vec[2];
            result[vec[1]] -= vec[2];
        }
        int sum = 0;
        for(int i = 0;i < result.size(); ++i)
            result[i] = (sum += result[i]);
        result.pop_back();
        return result;
    }
};