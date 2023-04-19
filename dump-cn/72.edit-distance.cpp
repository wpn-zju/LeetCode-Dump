class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() || word2.empty())
            return max(word1.size(), word2.size());
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), INT_MAX));
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for(int i = 1;i<dp.size();++i)
            dp[i][0] = word1[i] == word2[0] ? i : dp[i - 1][0] + 1;
        for(int i =1;i<dp[0].size();++i)
            dp[0][i] = word2[i] == word1[0] ? i : dp[0][i - 1] + 1;
        for(int i = 1;i<dp.size();++i){
            for(int j =1;j<dp[0].size();++j){
                if(word2[j] == word1[i]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp.back().back();
    }
};