class Solution {
public:
	uint getHashTableOfString(string s) {
		uint result = 0;
		for (int i = 0;i<s.size();++i)
			result = result | 1u << (s[i] - 'a');
		return result;
	}

	vector<int> partitionLabels(string S) {
		int m = S.size();
		vector<int> result;
		if (m == 1) {
			result.push_back(1);
			return result;
		}
		int prevPtr = 0;
		int ptr = 1;
		while (ptr != m) {
			if ((getHashTableOfString(S.substr(prevPtr, ptr - prevPtr))&getHashTableOfString(S.substr(ptr))) == 0) {
				result.push_back(ptr - prevPtr);
				prevPtr = ptr;
			}
			ptr++;
		}
        result.push_back(m-prevPtr);
		return result;
	}
};