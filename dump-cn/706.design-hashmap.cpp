class HashNode {
public:
	int key;
	int value;
	HashNode* next;

	HashNode(int k) {
		key = k;
		value = 0;
		next = nullptr;
	}

	HashNode(int k, int v) {
		key = k;
		value = v;
		next = nullptr;
	}
};

class MyHashMap {
public:
	const int hashKey = 997;
	vector<HashNode*> hashSet;
	/** Initialize your data structure here. */
	MyHashMap() {
		hashSet = vector<HashNode*>(hashKey, nullptr);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		if (!hashSet[key%hashKey])
			hashSet[key%hashKey] = new HashNode(key, value);
		else {
			HashNode* ptr = hashSet[key%hashKey];
			while (ptr->key != key && ptr->next)
				ptr = ptr->next;
			if (ptr->key != key)
				ptr->next = new HashNode(key, value);
            else
				ptr->value = value;
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		HashNode* ptr = hashSet[key%hashKey];
		while (ptr && ptr->key != key)
			ptr = ptr->next;
		return ptr ? ptr->value : -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		HashNode* prev = nullptr;
		HashNode* ptr = hashSet[key%hashKey];
		while (ptr && ptr->key != key) {
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
};