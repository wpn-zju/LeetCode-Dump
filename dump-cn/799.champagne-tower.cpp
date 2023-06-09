class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<vector<double>> glass(100, vector<double>(100));
		glass[0][0] += poured;
		for (int i = 0; i < 99; ++i) {
			for (int j = 0; j <= i; ++j) { 
                if(glass[i][j] > 1){
                    glass[i + 1][j] += (glass[i][j] - 1) / 2;
				    glass[i + 1][j + 1] += (glass[i][j] - 1) / 2;
                    glass[i][j] = 1;
                }
			}
		}
		return glass[query_row][query_glass];
	}
};