class Solution {
public:
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> result(queries.size());
		vector<int> search(words.size());
		for (int i = 0; i < words.size(); ++i) {
			vector<int> count(26, 0);
			for (char& c : words[i])
				++count[c - 'a'];
			for (int n = 0; n < 26; ++n) {
				if (count[n]) {
					search[i] = count[n];
					break;
				}
			}
		}
        search.push_back(INT_MAX);
		sort(search.begin(), search.end(), greater<int>());
		for (int i = 0; i < queries.size(); ++i) {
			vector<int> count(26, 0);
			for (char& c : queries[i])
				++count[c - 'a'];
			int tmp = 0;
			for (int n = 0; n < 26; ++n) {
				if (count[n]) {
					tmp = count[n];
					break;
				}
			}
			int start = 0;
			int end = search.size() - 1;
			while (start < end) {
				int mid = end - (end - start >> 1);
				if (search[mid] <= tmp)
					end = mid - 1;
				else
					start = mid;
			}
			result[i] = start;
		}
		return result;
	}
};