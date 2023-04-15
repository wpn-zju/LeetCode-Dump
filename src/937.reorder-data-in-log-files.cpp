class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> typeL;
        vector<string> typeN;
        for(string& str : logs){
            int ptr = 0;
            while(str[ptr] != ' ')
                ++ptr;
            if(str[ptr + 1] >= '0' && str[ptr + 1]  <= '9')
                typeN.push_back(str);
            else
                typeL.push_back(str);
        }
        sort(typeL.begin(), typeL.end(), [](string& a, string& b){
            int ptr1 = 0;
            int ptr2 = 0;
            while(a[ptr1] != ' ')
                ++ptr1;
            while(b[ptr2] != ' ')
                ++ptr2;
            while(ptr1 < a.size() && ptr2 < b.size()){
                if(a[ptr1] != b[ptr2])
                    return a[ptr1] < b[ptr2];
                ++ptr1;
                ++ptr2;
            }
            return ptr1 == a.size();
        });
        for(string& str : typeN)
            typeL.push_back(str);
        return typeL;
    }
};