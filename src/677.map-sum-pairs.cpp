	class CharNode1 {
	public:
		int val = 0;
		unordered_map<char, CharNode1*> next;
	};

	class Trie1 {
	public:
		CharNode1* head;

		Trie1() {
			head = new CharNode1();
		}

		void insert(string& in, int val) {
			CharNode1* cur = head;
			int i = 0;
			while (i < in.length() && cur->next.count(in[i]))
				cur = cur->next[in[i++]];
			while (i < in.length())
				cur = cur->next[in[i++]] = new CharNode1();
			cur->val = val;
		}

		int search(string& in) {
			CharNode1* cur = head;
			int i = 0;
			while (i < in.length() && cur->next.count(in[i]))
				cur = cur->next[in[i++]];
			return i == in.length() ? dfsSum(cur) : 0;
		}

		int dfsSum(CharNode1* cur) {
			int result = 0;
			result += cur->val;
			for (pair<char, CharNode1*> p : cur->next)
				result += dfsSum(p.second);
			return result;
		}
	};

	class MapSum {
	public:
		Trie1 trie;

		void insert(string key, int val) {
			trie.insert(key, val);
		}

		int sum(string prefix) {
			return trie.search(prefix);
		}
	};