class CharNode2 {
public:
	int hot;
	vector<CharNode2*> next;

	CharNode2() {
		hot = 0;
		next = vector<CharNode2*>(27, nullptr);
	}
};

class Trie2 {
public:
	CharNode2* head;

	Trie2() {
		head = new CharNode2();
	}

	void insert(string& word, int hot) {
		for (char& c : word)
			if (c == ' ')
				c = 'a' - 1;
		CharNode2* ptr = head;
		int index = 0;
		while (index != word.length() && ptr->next[word[index] - 'a' + 1])
			ptr = ptr->next[word[index++] - 'a' + 1];
		while (index != word.length())
			ptr = ptr->next[word[index++] - 'a' + 1] = new CharNode2();
		ptr->hot += hot;
	}

	vector<string> search(CharNode2*& in, string& cur, char& c) {
		vector<string> output;
		in = c == ' ' ? in->next[0] : in->next[c - 'a' + 1];
		if (!in)
			return output;
		vector<pair<int, string>> result;
		getStr(in, cur, result);
		sort(result.begin(), result.end(), [](pair<int, string>& a, pair<int, string>& b) {
			return a.first == b.first ? a.second < b.second : a.first > b.first;
		});
		for (int i = 0; i < min(3, (int)result.size()); ++i)
			output.push_back(result[i].second);
		return output;
	}

	void getStr(CharNode2* in, string& tmp, vector<pair<int, string>>& target) {
		if (in->hot)
			target.push_back({ in->hot, tmp });
		for (int i = 0; i < in->next.size(); ++i)
			if (in->next[i]) {
				tmp += i == 0 ? ' ' : (i + 'a' - 1);
				getStr(in->next[i], tmp, target);
				tmp.pop_back();
			}
	}
};

class AutocompleteSystem {
public:
	string cur;
	CharNode2* tmp;
	Trie2 trie;

	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		for (int i = 0; i < sentences.size(); ++i)
			trie.insert(sentences[i], times[i]);
		cur = "";
		tmp = trie.head;
	}

	vector<string> input(char c) {
		if (c == '#') {
			trie.insert(cur, 1);
			cur = "";
			tmp = trie.head;
		}
		else {
			cur += c;
			if (tmp)
				return trie.search(tmp, cur, c);
		}
		return {};
	}
};