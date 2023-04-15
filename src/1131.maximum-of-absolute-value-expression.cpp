class Solution {
public:
	struct p3d {
		int x;
		int y;
		int z;

		p3d(int x, int y, int z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};

	int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		int result = 0;
		vector<p3d> v;
		for (int i = 0; i < arr1.size(); ++i)
			v.push_back({ arr1[i],arr2[i],i });
		vector<p3d> cmp{
			p3d(-100000000,-100000000,-100000000),
			p3d(-100000000,-100000000,100000000),
			p3d(-100000000,100000000,-100000000),
			p3d(-100000000,100000000,100000000)
		};
		auto dis = [](p3d& a, p3d& b) {
			return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
		};
		for (int n = 0; n < cmp.size(); ++n) {
			int mx = INT_MIN, mn = INT_MAX;
			for (int i = 0; i < v.size(); ++i) {
				int t = dis(v[i], cmp[n]);
				mx = max(mx, t);
				mn = min(mn, t);
			}
			result = max(result, mx - mn);
		}
		return result;
	}
};