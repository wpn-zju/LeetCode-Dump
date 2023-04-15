	class CamelTrieNode {
	public:
		int val = -1;
		unordered_map<char, CamelTrieNode*> next;
	};

	class CamelTrie {
	public:
		CamelTrieNode* head;

		CamelTrie() {
			head = new CamelTrieNode();
		}

		void insert(string& word, int val) {
			CamelTrieNode* cur = head;
			int i = 0;
			while (i < word.length() && cur->next.count(word[i]))
				cur = cur->next[word[i++]];
			while (i < word.length())
				cur = cur->next[word[i++]] = new CamelTrieNode();
			cur->val = val;
		}

		void dfsSearch(vector<bool>& result, CamelTrieNode* cur, int index, string& pattern) {
			if (cur->val != -1 && index == pattern.length())
				result[cur->val] = true;
			for (pair<char, CamelTrieNode*> p : cur->next) {
				if (p.first == pattern[index])
					dfsSearch(result, p.second, index + 1, pattern);
				if (p.first >= 'a' && p.first <= 'z')
					dfsSearch(result, p.second, index, pattern);
			}
		}
	};

class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		CamelTrie trie;
		for (int i = 0; i < queries.size(); ++i)
			trie.insert(queries[i], i);
		vector<bool> result(queries.size(), false);
		trie.dfsSearch(result, trie.head, 0, pattern);
		return result;
	}
};