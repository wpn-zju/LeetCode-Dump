class Solution {
public:
    unordered_map<int, int> tri;
    int tribonacci(int n) {
        if(tri.count(n))
            return tri[n];
        switch(n){
            case 0:
                return tri[0] = 0;
            case 1:
                return tri[1] = 1;
            case 2:
                return tri[2] = 1;
            default:
                return tri[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }
    }
};