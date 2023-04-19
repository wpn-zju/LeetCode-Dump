class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result = 0;
        stack<int> s;
        for(string& str : ops){
            if(str == "C"){
                result -= s.top();
                s.pop();
            }
            else if(str == "D"){
                result += s.top() * 2;
                s.push(s.top() * 2);
            }
            else if(str == "+"){
                int last = s.top();
                s.pop();
                int last2 = s.top();
                result += last + last2;
                s.push(last);
                s.push(last + last2);
            }
            else{
                int ptr = 0;
                bool neg = str[ptr] == '-';
                if(neg) ++ptr;
                int len = 0;
                while(ptr < str.length()){
                    len *= 10;
                    len += str[ptr] - '0';
                    ++ptr;
                }
                result += neg ? -len : len;
                s.push(neg ? -len : len);
            }
        }
        return result;
    }
};