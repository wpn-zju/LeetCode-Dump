class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, (steps >> 1) + 1);
        vector<vector<uint32_t>> dp(steps + 1, vector<uint32_t>(arrLen, 0));
        dp[0][0] = 1;
        for(int i =1;i<=steps;++i){
            for(int j = 0;j<arrLen;++j){
                dp[i][j] = dp[i-1][j];
                if(j > 0)
                    dp[i][j] += dp[i-1][j-1];
                if(j < arrLen - 1)
                    dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= 1000000007;
            }
        }
        return dp.back()[0];
    }
};