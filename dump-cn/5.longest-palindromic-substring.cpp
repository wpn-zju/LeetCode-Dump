class Solution {
public:
    string manacher(string ori_s) {
        string s = "#";
        for (auto c : ori_s) {
            s += c;
            s += "#";
        }
        int N = s.size();
        vector<int> radius(N, 0);
        int C = 0;
        int R = 0;
        int max_c = 0;
        int max_r = 0;
        for (int i = 0; i < N; ++i) {
            if (i <= R) radius[i] = min(R - i, radius[2 * C - i]);
            while (radius[i] + 1 + i < N && i - radius[i] - 1>= 0 && 
                    s[radius[i] + 1 + i] == s[i - radius[i] - 1]) ++radius[i];
            if (radius[i] + i > R) {
                R = radius[i] + i;
                C = i;
            }
            if (radius[i] > max_r) {
                max_r = radius[i];
                max_c = i;
            }
        }
        string res;
        for (int i = max_c - max_r; i <= max_c + max_r; ++i) {
            if (s[i] != '#') res += s[i];
        }
        return res;
    }
    
    string longestPalindrome(string s) {
        return manacher(s);
    }
};