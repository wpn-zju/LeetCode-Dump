class Solution {
public:
    int flip(int in, int x, int y, vector<vector<int>>& mat){
        if(in & (1 << mat[0].size() * x + y))
            in -= 1 << mat[0].size() * x + y;
        else
            in += 1 << mat[0].size() * x + y;
        if(x != 0){
            if(in & (1 << mat[0].size() * (x - 1) + y))
                in -= 1 << mat[0].size() * (x - 1) + y;
            else
                in += 1 << mat[0].size() * (x - 1) + y;
        }
        if(y != 0){
            if(in & (1 << mat[0].size() * x + y - 1))
                in -= 1 << mat[0].size() * x + y - 1;
            else
                in += 1 << mat[0].size() * x + y - 1;            
        }
        if(x != mat.size() - 1){
            if(in & (1 << mat[0].size() * (x + 1) + y))
                in -= 1 << mat[0].size() * (x + 1) + y;
            else
                in += 1 << mat[0].size() * (x + 1) + y;            
        }
        if(y != mat[0].size() - 1){
            if(in & (1 << mat[0].size() * x + y + 1))
                in -= 1 << mat[0].size() * x + y + 1;
            else
                in += 1 << mat[0].size() * x + y + 1;            
        }
        return in;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        unordered_set<int> visited;
        int start = 0;
        for(int i =0;i<mat.size();++i)
            for(int j = 0;j<mat[0].size();++j)
                if(mat[i][j])
                    start |= 1 << i * mat[0].size() + j;
        queue<int> que;
        que.push(start);
        int count = 0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int& cur = que.front();
                if(cur == 0)
                    return count;
                for(int i =0;i<mat.size();++i){
                    for(int j =0;j<mat[0].size();++j){
                        int tmp = flip(cur, i, j, mat);
                        if(!visited.count(tmp)){
                            que.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
                que.pop();
            }
            ++count;
        }
        return -1;
    }
};