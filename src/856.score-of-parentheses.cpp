class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> t;
        int l = 0;
        for(int i =0;i<S.length();++i){
            if(S[i] == '('){
                if(S[i+1] == ')'){
                    ++l;
                    ++i;
                }
                else{
                    t.push(l);
                    l = 0;
                }
            }
            else{
                l *= 2;
                l += t.top();
                t.pop();
            }
        }
        return l;
    }
};