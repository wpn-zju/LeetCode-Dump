class Solution {
public:
    int gcd(int x, int y){
        while(x) swap(x, y %= x);
        return y;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.size(), str2.size());
        if(str2.size() < str1.size())
            swap(str1, str2);
        string pattern = str1.substr(0, g);
        bool matched = true;
        for(int j =0;j<(int)str1.size()/g;++j){
            if(str1.substr(g * j, g) != pattern){
                matched = false;
                break;
            }
        }
        if(!matched)
            return "";
        for(int j =0;j<(int)str2.size()/g;++j){
            if(str2.substr(g * j, g) != pattern){
                matched = false;
                break;
            }
        }
        if(matched)
            return pattern;
        return "";
    }
};