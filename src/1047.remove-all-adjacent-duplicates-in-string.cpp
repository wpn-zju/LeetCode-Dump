class Solution {
public:
    string removeDuplicates(string S) {
        stack<int> s;
        for(char& c : S)
            if(!s.empty() && s.top() == c)
                s.pop();
            else
                s.push(c);
        string result = "";
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};