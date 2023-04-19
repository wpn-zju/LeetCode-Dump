class Solution {
public:
	int maxRepOpt1(string text) {
		vector<int> count(26, 0);
		for (char& c : text)
			++count[c - 'a'];
		int result = 1;
		for (char c = 'a'; c <= 'z'; ++c) {
			int ptr1 = 0;
			int ptr2 = 0;
			int ptr3 = 0;
			bool replaced = false;
			while (ptr3 < text.size()) {
				if (text[ptr3] == c);
				else if (replaced) {
					result = max(result, count[c - 'a'] < ptr3 - ptr1 ? ptr3 - ptr1 - 1 : ptr3 - ptr1);
					ptr1 = ptr2 + 1;
					ptr2 = ptr3;
				}
				else {
					ptr2 = ptr3;
					replaced = true;
				}
				++ptr3;
			}
			result = max(result, count[c - 'a'] < ptr3 - ptr1 ? ptr3 - ptr1 - 1 : ptr3 - ptr1);
		}
		return result;
	}
};