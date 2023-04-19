class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> out;
        out.clear();
        vector<int> tmp;
        vector<string>::iterator it;
        string word = "";
        for (it = words.begin(); it < words.end(); ++it){
            int position = 0; 
            while((position = text.find(*it, position)) != text.npos){
                tmp.clear();
                word = *it;
                tmp.push_back(position);
                tmp.push_back(position + word.size() - 1);
                position ++;
                out.push_back(tmp);
            }
        }
        
        // 索引对排序
        sort(out.begin(), out.end());
        return out;
    }
};