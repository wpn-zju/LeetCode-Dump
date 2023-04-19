class MagicNode {
public:
	bool selfEnabled = false;
	unordered_map<char, MagicNode*> next;
};

class MagicTrie {
public:
	MagicNode* head;

	MagicTrie() {
		head = new MagicNode();
	}

	void insert(string& in) {
		MagicNode* cur = head;
		int i = -1;
		while (++i < in.length())
			cur = cur->next.count(in[i]) ? cur->next[in[i]] : cur->next[in[i]] = new MagicNode();
		cur->selfEnabled = true;
	}

	bool magicSearch(string& in, MagicNode* cur, int index, bool dirty) {
		if (index == in.length() && dirty)
			return cur->selfEnabled;
		if (!dirty) {
			for (pair<char, MagicNode*> p : cur->next)
				if (magicSearch(in, p.second, index + 1, p.first != in[index]))
					return true;
		}
		else if (cur->next.count(in[index]))
			return magicSearch(in, cur->next[in[index]], index + 1, dirty);
		return false;
	}
};

class MagicDictionary {
public:
	MagicTrie trie;

	void buildDict(vector<string> dict) {
		for (string& str : dict)
			trie.insert(str);
	}

	bool search(string word) {
		return trie.magicSearch(word, trie.head, 0, false);
	}
};