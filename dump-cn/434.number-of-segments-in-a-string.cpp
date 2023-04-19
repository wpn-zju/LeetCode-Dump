class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool flag = false;
        for(char& c : s){
            if(c == ' ')
                flag = false;
            else if(!flag){
                ++count;
                flag = true;
            }
        }
        return count;
    }
};