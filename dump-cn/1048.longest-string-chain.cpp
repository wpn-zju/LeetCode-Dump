class Solution {
public:
	bool isPrece(string& a, string& b) {
		if (b.size() != a.size() + 1)
			return false;
		int ptr1 = 0, ptr2 = 0;
		bool insert = false;
		while (ptr2 < b.size()) {
			if (a[ptr1] == b[ptr2])
				++ptr1;
			else
				if (insert)
					return false;
				else
					insert = true;
			++ptr2;
		}
		return insert;
	}

	int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
           return a.size() == b.size() ? a < b : a.size() < b.size(); 
        });
		int result = 1;
		vector<int> dp(words.size(), 1);
		for (int i = 0; i < words.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (isPrece(words[j], words[i]))
					result = max(result, dp[i] = max(dp[i], dp[j] + 1));
		return result;
	}
};