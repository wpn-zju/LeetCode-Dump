class Solution {
public:
	bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
		if (words1.size() != words2.size())
			return false;
		unordered_map<string, set<string>> strMap;
		for (vector<string>& vec : pairs){
            strMap[vec[0]].insert(vec[1]);
            strMap[vec[1]].insert(vec[0]);
        }
		for (int i = 0; i < words1.size(); ++i)
			if (words1[i] != words2[i])
				if (!strMap.count(words1[i]) || !strMap[words1[i]].count(words2[i]))
					if (!strMap.count(words2[i]) || !strMap[words2[i]].count(words1[i]))
						return false;
		return true;
	}
};