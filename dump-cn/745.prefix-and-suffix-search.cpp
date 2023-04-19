	class BiCharNode {
	public:
		vector<int> contains;
		unordered_map<char, BiCharNode*> next;
	};

	class BiTrie {
	public:
		BiCharNode* head;

		BiTrie() {
			head = new BiCharNode();
		}

		void insert(string& str, int val) {
			BiCharNode* cur = head;
			int i = 0;
			while (i < str.length() && cur->next.count(str[i])) {
				cur->contains.push_back(val);
				cur = cur->next[str[i++]];
			}
			while (i < str.length()) {
				cur->contains.push_back(val);
				cur = cur->next[str[i++]] = new BiCharNode();
			}
			cur->contains.push_back(val);
		}
	};

	class WordFilter {
	public:
		BiTrie preTrie, sufTrie;

		WordFilter(vector<string>& words) {
			unordered_map<string, int> m;
			for (int i = 0; i < words.size(); ++i)
				m[words[i]] = i;
			for (pair<string, int> p : m) {
				preTrie.insert(p.first, p.second);
				reverse(p.first.begin(), p.first.end());
				sufTrie.insert(p.first, p.second);
			}
		}

		int f(string prefix, string suffix) {
			reverse(suffix.begin(), suffix.end());
			int preI = 0, sufI = 0;
			BiCharNode *preP = preTrie.head, *sufP = sufTrie.head;
			while (preI < prefix.length() && preP->next.count(prefix[preI]))
				preP = preP->next[prefix[preI++]];
			while (sufI < suffix.length() && sufP->next.count(suffix[sufI]))
				sufP = sufP->next[suffix[sufI++]];
			if (preI < prefix.length() || sufI < suffix.length())
				return -1;
			int result = -1;
            for(int& i : preP->contains)
                if(find(sufP->contains.begin(), sufP->contains.end(), i) != sufP->contains.end())
                    result = max(i, result);
			return result;
		}
	};