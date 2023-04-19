static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	double r;
	double x;
	double y;
	Solution(double radius, double x_center, double y_center) {
		this->r = radius;
		this->x = x_center;
		this->y = y_center;
	}

	vector<double> randPoint() {
		double degree = rand() % 360000000;
		double dis = rand() % 100000000;
		degree /= 180000000;
		degree *= 3.1415926535897932;
		dis = sqrt(dis);
		dis /= 10000;
		return { dis * r * sin(degree) + x ,dis * r * cos(degree) + y };
	}
};