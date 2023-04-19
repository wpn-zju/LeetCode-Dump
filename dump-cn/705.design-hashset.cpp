class HashNode {
public:
	int value;
	HashNode* next;

	HashNode(int v) {
		value = v;
		next = nullptr;
	}
};

class MyHashSet {
public:
	const int hashKey = 107;
	vector<HashNode*> hashSet;
	/** Initialize your data structure here. */
	MyHashSet() {
		hashSet = vector<HashNode*>(hashKey, nullptr);
	}

	void add(int key) {
		if (!hashSet[key%hashKey])
			hashSet[key%hashKey] = new HashNode(key);
		else {
			HashNode* ptr = hashSet[key%hashKey];
			while (ptr->value != key && ptr->next)
				ptr = ptr->next;
			if (ptr->value != key)
				ptr->next = new HashNode(key);
		}
	}

	void remove(int key) {
		HashNode* prev = nullptr;
		HashNode* ptr = hashSet[key%hashKey];
		while (ptr && ptr->value != key) {
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr) {
			if (!prev)
				hashSet[key%hashKey] = ptr->next;
			else
				prev->next = ptr->next;
			delete(ptr);
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		HashNode* ptr = hashSet[key%hashKey];
		while (ptr && ptr->value != key)
			ptr = ptr->next;
		return ptr != nullptr;
	}
};