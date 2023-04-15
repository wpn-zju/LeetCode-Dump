class Solution {
public:
	struct transaction {
		string city;
		int time;
		int quant;

		transaction(string city, int time, int quant) {
			this->city = city;
			this->time = time;
			this->quant = quant;
		}
	};

	vector<string> invalidTransactions(vector<string>& transactions) {
		unordered_set<string> result;
		unordered_map<string, vector<pair<int, transaction>>> data;
		for (int i = 0; i < transactions.size(); ++i) {
			vector<int> comma;
			for (int j = 0; j < transactions[i].size(); ++j)
				if (transactions[i][j] == ',')
					comma.push_back(j);
			int time = 0;
			for (int j = comma[0] + 1; j < comma[1]; ++j) {
				time *= 10;
				time += transactions[i][j] - '0';
			}
			int quant = 0;
			for (int j = comma[1] + 1; j < comma[2]; ++j) {
				quant *= 10;
				quant += transactions[i][j] - '0';
			}
			if (quant >= 1000)
				result.insert(transactions[i]);
			data[transactions[i].substr(0, comma[0])].push_back({ i,transaction(transactions[i].substr(comma[2] + 1), time, quant) });
		}
		for (pair<string, vector<pair<int, transaction>>> p : data) {
			for (int i = 0; i < p.second.size(); ++i) {
				for (int j = i + 1; j < p.second.size(); ++j) {
					if (p.second[i].second.city != p.second[j].second.city && abs(p.second[i].second.time - p.second[j].second.time) <= 60) {
						result.insert(transactions[p.second[i].first]);
						result.insert(transactions[p.second[j].first]);
					}
				}
			}
		}
		return vector<string>(result.begin(), result.end());
	}
};