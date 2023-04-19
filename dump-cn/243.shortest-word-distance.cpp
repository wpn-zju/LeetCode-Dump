class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int ptr1 = 0;
		int ptr2 = 0;
		int min = INT_MAX;
		while (ptr1 != words.size() && ptr2 != words.size()) {
			while (ptr1 != words.size() && words[ptr1] != word1)
				ptr1++;
			while (ptr2 != words.size() && words[ptr2] != word2)
				ptr2++;
			if (ptr1 == words.size() || ptr2 == words.size())
				break;
			if (abs(ptr2 - ptr1) < min)
				min = abs(ptr2 - ptr1);
			if (ptr2 > ptr1)
				ptr1++;
			else
				ptr2++;
		}
		return min;
	}
};