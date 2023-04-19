class Solution {
public:
	string validIPAddress(string IP) {
		unordered_set<char> ipv4{ '0','1','2','3','4','5','6','7','8','9','.' };
		unordered_set<char> ipv6{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F',':' };
		vector<int> tags1{ -1 };
		vector<int> tags2{ -1 };
		bool v4 = true, v6 = true;
		for (int i = 0; i < IP.size(); ++i) {
			v4 &= ipv4.count(IP[i]);
			v6 &= ipv6.count(IP[i]);
			if (IP[i] == ':')
				tags1.push_back(i);
			else if (IP[i] == '.')
				tags2.push_back(i);
		}
		if (v6 && tags1.size() == 8 && tags2.size() == 1) {
			tags1.push_back(IP.size());
			vector<string> strs;
			for (int i = 0; i < tags1.size() - 1; ++i)
				if (tags1[i] == tags1[i + 1] - 1 || tags1[i + 1] - tags1[i] > 5)
					return "Neither";
				else
					strs.push_back(IP.substr(tags1[i] + 1, tags1[i + 1] - tags1[i] - 1));
			for (string& str : strs)
				if (str.size() > 4)
					return "Neither";
			return "IPv6";
		}
		else if (v4 && tags1.size() == 1 && tags2.size() == 4) {
			tags2.push_back(IP.size());
			vector<string> strs;
			for (int i = 0; i < tags2.size() - 1; ++i)
				if (tags2[i] == tags2[i + 1] - 1 || tags2[i + 1] - tags2[i] > 4)
					return "Neither";
				else
					strs.push_back(IP.substr(tags2[i] + 1, tags2[i + 1] - tags2[i] - 1));
			for (string& str : strs)
				if (str.front() == '0' && str.size() > 1 || stoi(str) > 255)
					return "Neither";
			return "IPv4";
		}
		else
			return "Neither";
	}
};