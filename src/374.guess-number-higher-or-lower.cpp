// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int min = 0;
        long long int max = 1ll + n;
        long long int x = (min + max) / 2;
        while(true){
            int g = guess(x);
            if(g == -1)
                max = x;
            else if(g == 1)
                min = x;
            else
                return x;
            x = (min + max) / 2;
        }
    }
};