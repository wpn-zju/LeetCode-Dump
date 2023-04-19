class SnakeGame {
public:
	struct HashFunc {
		size_t operator()(const pair<int, int>& key) const {
			return (hash<unsigned long long>()(((unsigned long long)key.first << 32) + key.second));
		}
	};

	struct EqualKey {
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};

	int width = 0;
	int height = 0;
	pair<int, int> curPos = pair<int, int>(0, 0);
	queue<pair<int, int>> myQueue;
	queue<pair<int, int>> foodQueue;
	unordered_set<pair<int, int>, HashFunc, EqualKey> mySet;

	/** Initialize your data structure here.
		@param width - screen width
		@param height - screen height
		@param food - A list of food positions
		E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
	SnakeGame(int width, int height, vector<vector<int>>& food) {
		for (vector<int> vec : food)
			foodQueue.push(pair<int, int>(vec[0], vec[1]));
		this->width = width;
		this->height = height;
		myQueue.push(curPos);
		mySet.insert(curPos);
	}

	/** Moves the snake.
		@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
		@return The game's score after the move. Return -1 if game over.
		Game over when snake crosses the screen boundary or bites its body. */
	int move(string direction) {
		for (char c : direction) {
			switch (c)
			{
			case 'U':
				curPos.first--;
				break;
			case 'L':
				curPos.second--;
				break;
			case 'R':
				curPos.second++;
				break;
			case 'D':
				curPos.first++;
				break;
			}

			if (curPos.first < 0 || curPos.first >= height || curPos.second < 0 || curPos.second >= width)
				return -1;
			myQueue.push(curPos);
			if (curPos == foodQueue.front())
				foodQueue.pop();
			else {
				mySet.erase(myQueue.front());
				myQueue.pop();
			}
			if (mySet.count(curPos))
				return -1;
			mySet.insert(curPos);
		}
		return myQueue.size() - 1;
	}
};