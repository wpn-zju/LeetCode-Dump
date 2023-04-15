class Solution {
public:
	string removeDuplicateLetters(string text) {
		vector<int> last(26, -1);
		vector<bool> count(26, false);
		for (int i = 0; i < text.size(); ++i)
			last[text[i] - 'a'] = i;
		string result = "";
		for (int i = 0; i < text.size(); ++i) {
			if (!count[text[i] - 'a']) {
				if (result.empty() || result.back() < text[i]) {
					result.push_back(text[i]);
					count[text[i] - 'a'] = true;
				}
				else {
					while (!result.empty() && result.back() > text[i] && last[result.back() - 'a'] > i) {
						count[result.back() - 'a'] = false;
						result.pop_back();
					}
					result.push_back(text[i]);
					count[text[i] - 'a'] = true;
				}
			}
		}
		return result;
	}
};