class Solution {
public:
    vector<int> constructRectangle(int area) {
        int t = sqrt(area);
        while(true){
            if(area % t == 0)
                return {area / t, t};
            else
                --t;
        }
        return {};
    }
};