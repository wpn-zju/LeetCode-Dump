class LRUCache {
public:
	int capa;
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> myMap;
	LRUCache(int capacity) {
		capa = capacity;
	}

	int get(int key) {
		if (!myMap.count(key))
			return -1;
		cache.push_back({ myMap[key]->first, myMap[key]->second });
		cache.erase(myMap[key]);
		list<pair<int, int>>::iterator it = cache.end();
		myMap[key] = --it;
		return myMap[key]->second;
	}

	void put(int key, int value) {
		if (myMap.count(key)) {
			cache.push_back({ myMap[key]->first, value });
			cache.erase(myMap[key]);
		}
		else {
			if (cache.size() < capa)
				cache.push_back({ key, value });
			else {
				myMap.erase(cache.front().first);
				cache.erase(cache.begin());
				cache.push_back({ key, value });
			}
		}
		list<pair<int, int>>::iterator it = cache.end();
		myMap[key] = --it;
	}
};