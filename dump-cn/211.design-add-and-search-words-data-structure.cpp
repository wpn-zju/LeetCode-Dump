class CharNode {
public:
	bool selfEnabled = false;
	unordered_map<char, CharNode*> next;
};

class WordDictionary {
public:
	CharNode head;
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		CharNode* ptr = &head;
		int index = 0;
		while (index != word.length() && ptr->next.count(word[index])) {
			ptr = ptr->next[word[index]];
			index++;
		}
		while (index != word.length()) {
			ptr->next.insert(pair<char, CharNode*>(word[index], new CharNode()));
			ptr = ptr->next[word[index]];
			index++;
		}
		ptr->selfEnabled = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, 0, &head);
	}

	bool search(string& word, int index, CharNode* source) {
		CharNode* ptr = source;
		bool result = false;
		while (index != word.length() && ptr->next.count(word[index])) {
			ptr = ptr->next[word[index]];
			index++;
		}
		if (index == word.length())
			result = ptr->selfEnabled;
		else if (word[index] == '.') {
			for (pair<char, CharNode*> kvp : ptr->next)
				result |= search(word, index + 1, kvp.second);
		}
		else
			result = false;
		return result;
	}
};