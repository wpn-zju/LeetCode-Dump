class WordDistance {
public:
	unordered_map<string, vector<int>> dic;
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i)
			dic[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {
		vector<int>& vec1 = dic[word1];
		vector<int>& vec2 = dic[word2];
		int ptr1 = 0;
		int ptr2 = 0;
		int min = INT_MAX;
		while (ptr1 != vec1.size() && ptr2 != vec2.size()) {
			if (abs(vec2[ptr2] - vec1[ptr1]) < min)
				min = abs(vec2[ptr2] - vec1[ptr1]);
			if (vec1[ptr1] < vec2[ptr2])
				ptr1++;
			else
				ptr2++;
		}
		return min;
	}
};