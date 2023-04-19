class Solution {
public:
	int numberOfPatterns(int m, int n) {
		int result = 0;
		vector<bool> vis(9, false);
		dfsFindPattern(result, m, n, vis, 0, 0);
		return result;
	}

	void dfsFindPattern(int& result, int& m, int& n, vector<bool>& vis, int last, int cur) {
		if (cur >= m && cur <= n)
			++result;
		if (cur == n)
			return;
		if (!vis[0] && (vis[1] || last != 3) && (vis[3] || last != 7) && (vis[4] || last != 9)) {
			vis[0] = true;
			dfsFindPattern(result, m, n, vis, 1, cur + 1);
			vis[0] = false;
		}
		if (!vis[1] && (vis[4] || last != 8)) {
			vis[1] = true;
			dfsFindPattern(result, m, n, vis, 2, cur + 1);
			vis[1] = false;
		}
		if (!vis[2] && (vis[1] || last != 1) && (vis[5] || last != 9) && (vis[4] || last != 7)) {
			vis[2] = true;
			dfsFindPattern(result, m, n, vis, 3, cur + 1);
			vis[2] = false;
		}
		if (!vis[3] && (vis[4] || last != 6)) {
			vis[3] = true;
			dfsFindPattern(result, m, n, vis, 4, cur + 1);
			vis[3] = false;
		}
		if (!vis[4]) {
			vis[4] = true;
			dfsFindPattern(result, m, n, vis, 5, cur + 1);
			vis[4] = false;
		}
		if (!vis[5] && (vis[4] || last != 4)) {
			vis[5] = true;
			dfsFindPattern(result, m, n, vis, 6, cur + 1);
			vis[5] = false;
		}
		if (!vis[6] && (vis[3] || last != 1) && (vis[4] || last != 3) && (vis[7] || last != 9)) {
			vis[6] = true;
			dfsFindPattern(result, m, n, vis, 7, cur + 1);
			vis[6] = false;
		}
		if (!vis[7] && (vis[4] || last != 2)) {
			vis[7] = true;
			dfsFindPattern(result, m, n, vis, 8, cur + 1);
			vis[7] = false;
		}
		if (!vis[8] && (vis[4] || last != 1) && (vis[7] || last != 7) && (vis[5] || last != 3)) {
			vis[8] = true;
			dfsFindPattern(result, m, n, vis, 9, cur + 1);
			vis[8] = false;
		}
	}
};