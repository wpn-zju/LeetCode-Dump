namespace PPair {
	class CharNode {
	public:
		int id = -1;
        vector<int> ids;
		unordered_map<char, CharNode*> next;
	};

	class Trie {
	public:
		CharNode* head;
        
		Trie() {
            head = new CharNode();
		}
        
		void insert(string word, int id) {
            if(word == ""){
                head->id = id;
                return;
            }
			CharNode* ptr = head;
			int index = 0;
			while (index != word.length() && ptr->next.count(word[index])) {
				ptr = ptr->next[word[index]];
                ptr->ids.push_back(id);
				index++;
			}
			while (index != word.length()) {
				ptr->next.insert(pair<char, CharNode*>(word[index], new CharNode()));
				ptr = ptr->next[word[index]];
                ptr->ids.push_back(id);
				index++;
			}
			ptr->id = id;
		}
	};
}

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result;
		PPair::Trie myTrie;
		for (int i = 0; i < words.size(); ++i)
			myTrie.insert(words[i], i);

		for (int i = 0; i < words.size(); ++i) {
			PPair::CharNode* cur = myTrie.head;
			if (cur->id != -1 && cur->id != i && palindrome(words[i], words[i].length(), false)) {
				result.push_back({ i, cur->id });
				result.push_back({ cur->id, i });
			}
			int index = words[i].length() - 1;
			for (; index >= 0; --index) {
				if (cur->next.count(words[i][index])) {
					cur = cur->next[words[i][index]];
					if (cur->id != -1 && cur->id != i && palindrome(words[i], index, false))
						result.push_back({ cur->id, i });
				}
				else
					break;
			}
			if (index == -1)
				for (int k : cur->ids)
					if (k != i && words[i].length() < words[k].length() && palindrome(words[k], words[i].length(), true))
						result.push_back({ k, i });
		}
		return result;
	}

	bool palindrome(string& str, int index, bool type) {
		int i = type ? index : 0;
		int j = type ? str.length() - 1 : index - 1;
		while (i < j) {
			if (str[i] != str[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};