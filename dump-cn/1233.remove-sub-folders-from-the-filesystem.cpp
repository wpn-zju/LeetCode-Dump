static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	class CharNode4 {
	public:
		bool selfEnabled = false;
		unordered_map<string, CharNode4*> next;
	};

	class Trie4 {
	public:
		CharNode4* head;

		Trie4() {
			head = new CharNode4();
		}

		void readStrs(string& in, vector<string>& out) {
			vector<int> tags;
			for (int i = 0; i < in.size(); ++i)
				if (in[i] == '/')
					tags.push_back(i);
			tags.push_back(in.size());
			for (int i = 0; i < tags.size() - 1; ++i)
				out.push_back(in.substr(tags[i] + 1, tags[i + 1] - tags[i] - 1));
		}

		void getStr(vector<string>& in, string& out) {
			for (string& str : in)
				out += str + '/';
			out.pop_back();
		}

		void insert(string& in) {
			vector<string> data;
			readStrs(in, data);
			int ptr = -1;
			CharNode4* cur = head;
			while (++ptr < data.size())
				cur = cur->next.count(data[ptr]) ? cur->next[data[ptr]] : cur->next[data[ptr]] = new CharNode4();
			cur->selfEnabled = true;
		}

		void getResult(vector<string>& result) {
			vector<string> str;
			dfs(result, head, str);
		}

		void dfs(vector<string>& result, CharNode4* cur, vector<string>& str) {
			if (cur->selfEnabled) {
				result.push_back("/");
				getStr(str, result.back());
			}
			else
				for (pair<string, CharNode4*> p : cur->next) {
					str.push_back(p.first);
					dfs(result, p.second, str);
					str.pop_back();
				}
		}
	};

	vector<string> removeSubfolders(vector<string>& folder) {
		vector<string> result;
		Trie4 trie;
		for (string& str : folder)
			trie.insert(str);
		trie.getResult(result);
		return result;
	}
};