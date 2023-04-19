class Solution {
public:
    int getByte(int& num, int& offset) {
        return (num & (1u << offset)) >> offset;
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int l = word.size();
        int num = 1 << l;
        for (int i = 0; i < num; ++i) {
            int count = 0;
            string res;
            for (int j = 0; j <= l; ++j) {
                int tmp = getByte(i, j);
                if (tmp == 1) {
                    ++count;
                } else {
                    if (count != 0) {
                        res += to_string(count);
                        count = 0;
                    }
                    res += word[j];
                }
            }
            if (count != 0) {
                res += to_string(count);
            }
            result.emplace_back(move(res));
        }
        return result;
    }
};