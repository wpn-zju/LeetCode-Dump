// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int min = 0;
        long long int max = 1ll + n;
        long long int x = (min + max) / 2;
        while(max - min > 1){
            if(isBadVersion(x))
                max = x;
            else
                min = x;
            x = (min + max) / 2;
        }
        return max;
    }
};