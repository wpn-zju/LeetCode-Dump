class Solution {
public:
	int hIndex(vector<int>& citations) {
		int start = 0;
		int end = citations.size();
		while (start < end) {
			int ptr = (start + end + 1) / 2;
			if (citations[citations.size() - ptr] >= ptr)
				start = ptr;
			else
				end = ptr - 1;
		}
		return end;
	}
};