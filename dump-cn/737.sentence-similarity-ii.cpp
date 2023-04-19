class Solution {
public:
	class UnionFindWords {
	public:
		vector<int> nodes;

		UnionFindWords(int n) {
			nodes = vector<int>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] == x)
				return nodes[x];
			return nodes[x] = find(nodes[x]);
		}

		void unionEle(int a, int b) {
			int pa = find(a);
			int pb = find(b);
			if (pa != pb)
				nodes[pb] = pa;
		}
	};

	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
		if (words1.size() != words2.size())
			return false;
		unordered_map<string, int> strMap;
		int count = 0;
		for (vector<string>& vec : pairs)
			for (string& str : vec) {
				if (!strMap.count(str))
					strMap[str] = count++;
			}
		UnionFindWords ufw(strMap.size());
		for (vector<string>& vec : pairs)
			ufw.unionEle(strMap[vec[0]], strMap[vec[1]]);
		for (int i = 0; i < words1.size(); ++i)
			if (strMap.count(words1[i]) && strMap.count(words2[i])) {
				if (ufw.find(strMap[words1[i]]) != ufw.find(strMap[words2[i]]))
					return false;
			}
			else if (strMap.count(words1[i]) || strMap.count(words2[i]) || words1[i] != words2[i])
				return false;
		return true;
	}
};