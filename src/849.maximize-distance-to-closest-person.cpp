class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int ptr1 = 0;
		while (!seats[ptr1])
			++ptr1;
		int maxInterval = ptr1;
		int ptr2 = ptr1 + 1;
		seats.push_back(1);
		while (ptr2 < seats.size()) {
			while (!seats[ptr2])
				++ptr2;
            if(ptr2 == seats.size() - 1){
                maxInterval = max(maxInterval, ptr2 - ptr1 - 1);
                break;
            }
            else{
                maxInterval = max(maxInterval, ptr2 - ptr1 >> 1);
                ptr1 = ptr2++;
            }
		}
		maxInterval = max(maxInterval, ptr2 - ptr1 - 1);
		return maxInterval;
	}
};