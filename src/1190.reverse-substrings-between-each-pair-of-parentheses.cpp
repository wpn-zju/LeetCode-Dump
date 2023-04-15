class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> s1;
        string cur = "";
        for(char& c : s){
            if(c == '('){
                s1.push(cur);
                cur.clear();
            }
            else if(c == ')'){
                reverse(cur.begin(), cur.end());
                cur = s1.top() + cur;
                s1.pop();
            }
            else
                cur.push_back(c);
        }
        return cur;
    }
};