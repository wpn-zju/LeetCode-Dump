static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class AllOne {
public:
	list<pair<int, unordered_set<string>>> data;
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> val;

	AllOne() {

	}

	void inc(string key) {
		if (val.count(key)) {
			auto it = val[key];
			auto it2 = data.end(); --it2;
			auto it3 = it; ++it3;
			if (it2->first == it->first || it3->first != it->first + 1) {
				pair<int, unordered_set<string>> tmp;
				tmp.first = it->first + 1;
				tmp.second.insert(key);
				it3 = data.insert(it3, tmp);
			}
			else
				it3->second.insert(key);
			val[key] = it3;
			it->second.erase(key);
			if (it->second.empty())
				data.erase(it);
		}
		else {
			if (data.begin() != data.end() && data.begin()->first == 1) {
				data.begin()->second.insert(key);
				val[key] = data.begin();
			}
			else {
				pair<int, unordered_set<string>> tmp;
				tmp.first = 1;
				tmp.second.insert(key);
				val[key] = data.insert(data.begin(), tmp);
			}
		}
	}

	void dec(string key) {
		if (val.count(key)) {
			if (val[key]->first == 1) {
				val[key]->second.erase(key);
				if (val[key]->second.empty())
					data.erase(val[key]);
				val.erase(key);
			}
			else {
				auto it = val[key];
				auto it2 = data.begin();
				auto it3 = it; --it3;
				if (it->first == it2->first) {
					pair<int, unordered_set<string>> tmp;
					tmp.first = it->first - 1;
					tmp.second.insert(key);
					it->second.erase(key);
					if (it->second.empty())
						it = data.erase(it);
					val[key] = data.insert(it, tmp);
				}
				else {
					if (it->first == it3->first + 1)
						it3->second.insert(key);
					else {
						pair<int, unordered_set<string>> tmp;
						tmp.first = it->first - 1;
						tmp.second.insert(key);
						it3 = data.insert(it, tmp);
					}
					val[key] = it3;
					it->second.erase(key);
					if (it->second.empty())
						data.erase(it);
				}
			}
		}
	}

	string getMaxKey() {
		return data.empty() ? "" : *data.back().second.begin();
	}

	string getMinKey() {
		return data.empty() ? "" : *data.front().second.begin();
	}
};