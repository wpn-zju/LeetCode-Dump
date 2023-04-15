class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A)*(D - B);
        int area2 = (G - E)*(H - F);
        if (C < E || B > H || A > G || F > D)
            return area1 + area2;
        else {
            int x1 = min(G, C);
            int x2 = max(A, E);
            int y1 = min(D, H);
            int y2 = max(B, F);
            return area1 - (x1 - x2)*(y1 - y2) + area2;
        }
	}
};