class Solution {
public:
	bool parseBoolExpr(string& in, int start, int end) {
		switch (in[start])
		{
		case 't':
			return true;
		case 'f':
			return false;
		case '!':
			return !parseBoolExpr(in, start + 2, end - 1);
		default:
			int prev = start + 1;
			int nextR = start + 2;
			int lC = 0;
			int rC = 0;
			while (nextR < end) {
				if (in[nextR] == '(')
					++lC;
				else if (in[nextR] == ')')
					++rC;
				else if (in[nextR] == ',' && lC == rC) {
					bool tmp = parseBoolExpr(in, prev + 1, nextR - 1);
					if (in[start] == '&' && !tmp)
						return false;
					if (in[start] == '|' && tmp)
						return true;
					prev = nextR;
				}
				++nextR;
			}
			return parseBoolExpr(in, prev + 1, nextR - 1);
		}
	}

	bool parseBoolExpr(string in) {
		return parseBoolExpr(in, 0, in.size() - 1);
	}
};