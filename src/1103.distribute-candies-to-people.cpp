class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> count(num_people, 0);
        int ptr = 0;
        while(candies > 0){
            count[ptr % num_people] += ptr + 1;
            candies -= ptr + 1;
            ++ptr;
        }
        count[(ptr - 1) % num_people] += candies;
        return count;
    }
};