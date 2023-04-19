class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(result, S, 0);
        return result;
    }
    
    void dfs(vector<string>& result, string& cur, int index){
        if(index == cur.length()){
            result.push_back(cur);
            return;
        }
        if(cur[index] >= '0' && cur[index] <= '9'){
            dfs(result, cur, index + 1);
        }
        else if(cur[index] >= 'a' && cur[index] <= 'z'){
            dfs(result, cur, index + 1);
            cur[index] -= 'a';
            cur[index] += 'A';
            dfs(result, cur, index + 1);
        }
        else{
            dfs(result, cur, index + 1);
            cur[index] -= 'A';
            cur[index] += 'a';
            dfs(result, cur, index + 1);
        }
    }
};