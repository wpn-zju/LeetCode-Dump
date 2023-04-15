class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 1000000));
        dp[0] = A[0];
        for(int i = 1;i<A.size();++i){
            for(int j =0;j<A[0].size();++j){
                dp[i][j] = dp[i-1][j]+A[i][j];
                if(j != 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + A[i][j]);
                if(j != A[0].size() - 1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + A[i][j]);
            }
        }
        int mn = INT_MAX;
        for(int i = 0;i<dp[0].size();++i)
            mn = min(mn, dp.back()[i]);
        return mn;
    }
};