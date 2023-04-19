class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> result;
		vector<string> vec;
		int prev = 0;
		int ptr = 0;
		while (ptr < text.length()) {
			while (text[ptr] >= 'a' && text[ptr] <= 'z')
				ptr++;
			vec.push_back(text.substr(prev, ptr - prev));
			prev = ++ptr;
		}
		for (int i = 0; i < vec.size() - 2; ++i)
			if (vec[i] == first && vec[i + 1] == second)
				result.push_back(vec[i + 2]);
		return result;
	}
};