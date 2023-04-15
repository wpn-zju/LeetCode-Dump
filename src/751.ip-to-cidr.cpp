class Solution {
public:
	uint32_t ipToInt(string &str) {
		uint32_t sum = 0;
		int num = 0;
		for (char& c : str) {
			if (c == '.') {
				sum *= 256;
				sum += num;
				num = 0;
			}
			else {
				num *= 10;
				num += c - '0';
			}
		}
		sum *= 256;
		sum += num;
		return sum;
	}

	string intToIp(unsigned int num, int k) {
		string ss = "";
		int a[4];
		for (int i = 3; i >= 0; --i) {
			a[i] = num % 256;
			num /= 256;
		}
		for (int i = 0; i < 3; ++i) {
			ss += to_string(a[i]);
			ss += '.';
		}
		int tmp = -1;
		while (k) {
			k >>= 1;
			tmp++;
		}
		ss += to_string(a[3]);
		ss += '/';
		ss += to_string(32 - tmp);
		return ss;
	}

	vector<string> ipToCIDR(string ip, int n) {
		vector<string> res;
		uint32_t num = ipToInt(ip);
		while (true) {
			uint32_t k = num & (-num);
			while (k > n)
				k >>= 1;
			n -= k;
			res.push_back(intToIp(num, k));
			if (n <= 0)
				break;
			num += k;
		}
		return res;
	}
};