class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int m = s.size();
		unordered_map<char, int> map;
		int ptr1 = 0;
		int ptr2 = 0;
		int count = 0;
		int results = 0;
		while (ptr2 < m) {
			map[s[ptr2]]++;
			if (map[s[ptr2]] == 1)
				count++;

			while (count > k) {
				map[s[ptr1]]--;
				if (map[s[ptr1]] == 0)
					count--;
				ptr1++;
			}

			if (ptr2 - ptr1 + 1 > results)
				results = ptr2 - ptr1 + 1;
            ptr2++;
		}
		return results;
	}
};