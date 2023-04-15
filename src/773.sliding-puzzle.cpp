class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		int origin = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 3; ++j)
			{
				origin *= 10;
				origin += board[i][j];
			}
		int target = 123450;
        if(origin == target)
            return 0;
		unordered_map<int, int> memory;
		queue<int> count;
		queue<int> tag;
		queue<int> myQueue;
		count.push(0);
		tag.push(6);
		myQueue.push(target);
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			int curL = count.front();
			int tag1 = tag.front();
			if (!memory.count(cur)) {
				memory[cur] = curL;
				int bit1 = cur / 100000 % 10;
				int bit2 = cur / 10000 % 10;
				int bit3 = cur / 1000 % 10;
				int bit4 = cur / 100 % 10;
				int bit5 = cur / 10 % 10;
				int bit6 = cur % 10;
				vector<int> s;
				switch (tag1)
				{
				case 1:
					s.push_back(bit2 * 100000 + bit1 * 10000 + bit3 * 1000 + bit4 * 100 + bit5 * 10 + bit6);
					tag.push(2);
					s.push_back(bit4 * 100000 + bit2 * 10000 + bit3 * 1000 + bit1 * 100 + bit5 * 10 + bit6);
					tag.push(4);
					break;
				case 2:
					s.push_back(bit2 * 100000 + bit1 * 10000 + bit3 * 1000 + bit4 * 100 + bit5 * 10 + bit6);
					tag.push(1);
					s.push_back(bit1 * 100000 + bit3 * 10000 + bit2 * 1000 + bit4 * 100 + bit5 * 10 + bit6);
					tag.push(3);
					s.push_back(bit1 * 100000 + bit5 * 10000 + bit3 * 1000 + bit4 * 100 + bit2 * 10 + bit6);
					tag.push(5);
					break;
				case 3:
					s.push_back(bit1 * 100000 + bit3 * 10000 + bit2 * 1000 + bit4 * 100 + bit5 * 10 + bit6);
					tag.push(2);
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit6 * 1000 + bit4 * 100 + bit5 * 10 + bit3);
					tag.push(6);
					break;
				case 4:
					s.push_back(bit4 * 100000 + bit2 * 10000 + bit3 * 1000 + bit1 * 100 + bit5 * 10 + bit6);
					tag.push(1);
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit3 * 1000 + bit5 * 100 + bit4 * 10 + bit6);
					tag.push(5);
					break;
				case 5:
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit3 * 1000 + bit5 * 100 + bit4 * 10 + bit6);
					tag.push(4);
					s.push_back(bit1 * 100000 + bit5 * 10000 + bit3 * 1000 + bit4 * 100 + bit2 * 10 + bit6);
					tag.push(2);
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit3 * 1000 + bit4 * 100 + bit6 * 10 + bit5);
					tag.push(6);
					break;
				case 6:
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit6 * 1000 + bit4 * 100 + bit5 * 10 + bit3);
					tag.push(3);
					s.push_back(bit1 * 100000 + bit2 * 10000 + bit3 * 1000 + bit4 * 100 + bit6 * 10 + bit5);
					tag.push(5);
					break;
				}
				for (int&i : s) {
					if (i == origin)
						return curL + 1;
					myQueue.push(i);
					count.push(curL + 1);
				}
			}
			myQueue.pop();
			count.pop();
			tag.pop();
		}
		return -1;
	}
};