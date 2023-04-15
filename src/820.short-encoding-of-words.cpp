class Solution {
public:
	struct CharNode7 {
		bool enabled = false;
		unordered_map<char, CharNode7*> next;
	};

	class Trie7 {
	public:
		CharNode7* head;
		/** Initialize your data structure here. */
		Trie7() {
			head = new CharNode7();
		}

		void insert(string& in) {
			CharNode7* cur = head;
			int ptr = in.size() - 1;
			while (ptr >= 0) {
				cur = cur->next.count(in[ptr] - 'a') ? cur->next[in[ptr] - 'a'] : cur->next[in[ptr] - 'a'] = new CharNode7();
				--ptr;
			}
			cur->enabled = true;
		}

		int sum() {
			int result = 0;
			int length = 0;
			queue<CharNode7*> que;
			que.push(head);
			while (!que.empty()) {
				int size = que.size();
				while (size--) {
					CharNode7* cur = que.front();
					if (cur->next.empty())
						result += length + 1;
					else
						for (auto it = cur->next.begin(); it != cur->next.end(); ++it)
							que.push(it->second);
					que.pop();
				}
				++length;
			}
			return result;
		}
	};

	int minimumLengthEncoding(vector<string>& words) {
		Trie7 trie;
		for (string& str : words)
			trie.insert(str);
		return trie.sum();
	}
};