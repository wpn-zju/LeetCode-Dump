class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
        letters.push_back(letters.front());
		int start = 0;
		int end = letters.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (letters[mid] <= target)
				start = mid + 1;
			else
				end = mid;
		}
		return letters[start];
	}
};