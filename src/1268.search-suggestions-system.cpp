static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	struct CharNodeTimes {
		int times = 0;
		map<char, CharNodeTimes*> next;
	};

	class TrieTimes {
	public:
		CharNodeTimes* head;

		TrieTimes() {
			head = new CharNodeTimes();
		}

		void insert(string& in) {
			CharNodeTimes* cur = head;
			int ptr = 0;
			while (ptr < in.size()) {
				cur = cur->next.count(in[ptr]) ? cur->next[in[ptr]] : cur->next[in[ptr]] = new CharNodeTimes();
				++ptr;
			}
			++cur->times;
		}

		void dfsSearch(vector<string>& target, string& cur, CharNodeTimes* node) {
			for (int i = 0; i < node->times; ++i)
				if (target.size() < 3)
					target.push_back(cur);
			for (auto it = node->next.begin(); it != node->next.end(); ++it) {
				if (target.size() == 3)
					return;
				cur += it->first;
				dfsSearch(target, cur, it->second);
				cur.pop_back();
			}
		}

		void search(vector<vector<string>>& target, string& in) {
			CharNodeTimes* node = head;
			string b = "";
			for (int n = 0; n < in.size(); ++n) {
				b += in[n];
				if (node->next.count(in[n]))
					node = node->next[in[n]];
				else
					return;
				dfsSearch(target[n], b, node);
			}
		}
	};

	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		TrieTimes trie;
		vector<vector<string>> result(searchWord.size());
		for (string& str : products)
			trie.insert(str);
		trie.search(result, searchWord);
		return result;
	}
};