class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        for(int& i : distance)
            sum += i;
        int tmp = 0;
        if(start > destination)
            swap(start, destination);
        for(int i = start; i<destination;++i)
            tmp += distance[i];
        return min(tmp, sum - tmp);
    }
};