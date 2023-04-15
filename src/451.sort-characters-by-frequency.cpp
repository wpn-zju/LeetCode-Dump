class Solution {
public:
	string frequencySort(string s) {
		string result = "";
		vector<vector<int>> charMap;
		for (int i = 0; i < 130; ++i)
			charMap.push_back({i, 0});
		for (char& c : s)
			charMap[c][1]++;
		sort(charMap.begin(), charMap.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });
		for (int i = 0; i < 130; ++i){
            if (!charMap[i][1])
                break;
   			for (int n = 0; n < charMap[i][1]; ++n)
				result.push_back(charMap[i][0]);    
        }
		return result;
	}
};