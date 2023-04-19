class Solution {
public:
	class CharNode6 {
	public:
		bool selfEnabled = false;
		unordered_map<char, CharNode6*> next;
	};

	class Trie6 {
	public:
		CharNode6* head;
		/** Initialize your data structure here. */
		Trie6() {
			head = new CharNode6();
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			CharNode6* ptr = head;
			int index = 0;
			while (index != word.length() && ptr->next.count(word[index])) {
				ptr = ptr->next[word[index]];
				index++;
			}
			while (index != word.length()) {
				ptr->next.insert(pair<char, CharNode6*>(word[index], new CharNode6()));
				ptr = ptr->next[word[index]];
				index++;
			}
			ptr->selfEnabled = true;
		}

		int searchTrie(string& in, int startIndex) {
			int result = 0;
			int count = 0;
			CharNode6* ptr = head;
			while (ptr->next.count(in[startIndex + count])) {
				ptr = ptr->next[in[startIndex + count]];
				++count;
				if (ptr->selfEnabled)
					result = max(result, count);
			}
			return result;
		}
	};

	string boldWords(vector<string>& dict, string s) {
		vector<int> begin(s.size(), false);
		vector<int> end(s.size(), false);
		Trie6 trie;
		for (string& str : dict)
			trie.insert(str);
		for (int i = 0; i < s.size(); ++i) {
			int t = trie.searchTrie(s, i);
			if (t) {
				++begin[i];
				++end[i + t - 1];
			}
		}
		string result = "";
		int cur = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (begin[i]) {
				cur += begin[i];
				if (cur == 1 && (i == 0 || !end[i - 1]))
					result += "<b>";
			}
			result += s[i];
			if (end[i]) {
				cur -= end[i];
				if (cur == 0 && (i == s.size() - 1 || !begin[i + 1]))
					result += "</b>";
			}
		}
		return result;
	}
};