class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> que;
        int i =0;
        for(;i < arr.size() - 1;){
            if(que.empty()){
                if(arr[i])
                    ++i;
                else{
                    que.push(arr[i + 1]);
                    arr[i + 1] = 0;
                    i += 2;
                }
            }
            else{
                que.push(arr[i]);
                arr[i] = que.front();
                que.pop();
                if(arr[i])
                    ++i;
                else{
                    que.push(arr[i + 1]);
                    arr[i + 1] = 0;
                    i += 2;
                }
            }
        }
        if(i == arr.size() - 1 && !que.empty())
            arr[i] = que.front();
    }
};