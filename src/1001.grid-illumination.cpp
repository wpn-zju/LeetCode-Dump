class Solution {
public:
		vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
			int dirs[9][2] = { {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {1, -1}, {-1, 1} };
			vector<int> result;
			unordered_map<int, int> xlines;
			unordered_map<int, int> ylines;
			unordered_map<int, int> pos_diags;
			unordered_map<int, int> neg_diags;
			unordered_set<uint64_t> s;
			for (auto& l : lamps) {
				s.insert(((uint64_t)l[0] << 32) + l[1]);
				++xlines[l[0]];
				++ylines[l[1]];
				++pos_diags[l[0] + l[1]];
				++neg_diags[l[0] - l[1]];
			}
			for (auto& q : queries) {
				int x = q[0];
				int y = q[1];
				result.push_back(xlines[x] > 0 || ylines[y] > 0 || pos_diags[x + y] > 0 || neg_diags[x - y] > 0);
				for (int i = 0; i < 9; ++i) {
					int tx = x + dirs[i][0];
					int ty = y + dirs[i][1];
					if (s.count(((uint64_t)tx << 32) + ty)) {
						--xlines[tx];
						--ylines[ty];
						--pos_diags[tx + ty];
						--neg_diags[tx - ty];
						s.erase(((uint64_t)tx << 32) + ty);
					}
				}
			}
			return result;
		}
};