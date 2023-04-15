static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
	class NormalTrieNode {
	public:
		bool selfEnabled = false;
		unordered_map<char, NormalTrieNode*> next;
	};

	class NormalTrie {
	public:
		NormalTrieNode* head;

		NormalTrie() {
			head = new NormalTrieNode();
		}

		void insert(string& word) {
			NormalTrieNode* cur = head;
			int i = word.length() - 1;
			while (i >= 0 && cur->next.count(word[i]))
				cur = cur->next[word[i--]];
			while (i >= 0)
				cur = cur->next[word[i--]] = new NormalTrieNode();
			cur->selfEnabled = true;
		}

		bool search(string& in) {
			NormalTrieNode* cur = head;
			int i = in.length() - 1;
			while (i >= 0) {
				if (cur->selfEnabled)
					return true;
				if (cur->next.count(in[i]))
					cur = cur->next[in[i--]];
				else
					return false;
			}
			return cur->selfEnabled;
		}
	};

	class StreamChecker {
	public:
		string cur = "";
		NormalTrie trie;

		StreamChecker(vector<string>& words) {
			for (string& str : words)
				trie.insert(str);
		}

		bool query(char letter) {
			return trie.search(cur += letter);
		}
	};