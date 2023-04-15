class Solution {
public:
	string originalDigits(string s) {
		unordered_map<char, int> count;
		for (char& c : s)
			++count[c];
		vector<int> c(10, 0);
		c[0] = count['z'];
		count['e'] -= count['z'];
		count['r'] -= count['z'];
		count['o'] -= count['z'];
		count['z'] -= count['z'];
		c[2] = count['w'];
		count['t'] -= count['w'];
		count['o'] -= count['w'];
		count['w'] -= count['w'];
		c[6] = count['x'];
		count['s'] -= count['x'];
		count['i'] -= count['x'];
		count['x'] -= count['x'];
		c[8] = count['g'];
		count['e'] -= count['g'];
		count['i'] -= count['g'];
		count['h'] -= count['g'];
		count['t'] -= count['g'];
		count['g'] -= count['g'];
		c[3] = count['t'];
		count['h'] -= count['t'];
		count['r'] -= count['t'];
		count['e'] -= count['t'];
		count['e'] -= count['t'];
		count['t'] -= count['t'];
		c[4] = count['r'];
		count['f'] -= count['r'];
		count['o'] -= count['r'];
		count['u'] -= count['r'];
		count['r'] -= count['r'];
		c[5] = count['f'];
		count['i'] -= count['f'];
		count['v'] -= count['f'];
		count['e'] -= count['f'];
		count['f'] -= count['f'];
		c[7] = count['s'];
		count['e'] -= count['s'];
		count['v'] -= count['s'];
		count['e'] -= count['s'];
		count['n'] -= count['s'];
		count['s'] -= count['s'];
		c[9] = count['i'];
		count['n'] -= count['i'];
		count['n'] -= count['i'];
		count['e'] -= count['i'];
		count['i'] -= count['i'];
		c[1] = count['o'];
		count['n'] -= count['o'];
		count['e'] -= count['o'];
		count['o'] -= count['o'];
		string result = "";
		for (int i = 0; i < c.size(); ++i)
			for (int j = 0; j < c[i]; ++j)
				result += (i + '0');
		return result;
	}
};