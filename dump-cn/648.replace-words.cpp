class CharNode {
public:
	bool selfEnabled = false;
	unordered_map<char, CharNode*> next;
};

class Trie {
public:
	CharNode* head;
	/** Initialize your data structure here. */
	Trie() {
		head = new CharNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		CharNode* ptr = head;
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

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return search(word, 0, head);
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

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return startsWith(prefix, 0, head);
	}

	bool startsWith(string& prefix, int index, CharNode* source) {
		CharNode* ptr = source;
		bool result = false;
		while (index != prefix.length() && ptr->next.count(prefix[index])) {
			ptr = ptr->next[prefix[index]];
			index++;
		}
		if (index == prefix.length())
			result = true;
		else if (prefix[index] == '.') {
			for (pair<char, CharNode*> kvp : ptr->next)
				result |= search(prefix, index + 1, kvp.second);
		}
		else
			result = false;
		return result;
	}
    
	string findMinPrefixWord(string& word, int index, CharNode* source) {
		CharNode* ptr = source;
		while (index != word.length() && ptr->next.count(word[index])) {
			ptr = ptr->next[word[index]];
			index++;
			if (ptr->selfEnabled)
				return word.substr(0, index);
		}
		return word;
	}
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie myTrie;
        string result = "";
        for(string& str : dict)
            myTrie.insert(str);
        int m = sentence.length();
        int prev = 0;
        int ptr = 0;
        while(ptr < m){
            prev = ptr;
            while(sentence[ptr] >= 'a' && sentence[ptr] <= 'z')
                ptr++;
            string word = sentence.substr(prev, ptr - prev);
            result += myTrie.findMinPrefixWord(word, 0, myTrie.head) + ' ';
            ptr++;
        }
        result.resize(result.size() - 1);
        return result;
    }
};