class Solution {
public:    
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for(int i = 0;i < points.size();++i)
            for(int j = i + 1;j<points.size();++j)
                for(int k = j + 1;k < points.size();++k)
                    result = max(result, abs(((double)points[k][1] - points[i][1]) * ((double)points[j][0] - points[i][0]) - ((double)points[k][0] - points[i][0]) * ((double)points[j][1] - points[i][1])));
        return result / 2;
    }
};