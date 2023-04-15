class Solution {
public:
	Node* construct(vector<vector<int>>& grid) {
		int state = 0;
		return construct(grid, 0, grid.size() - 1, 0, grid[0].size() - 1, state);
	}

	Node* construct(vector<vector<int>>& grid, int startx, int endx, int starty, int endy, int& state) {
		if (startx == endx && starty == endy) {
			state = grid[startx][starty] ? 1 : 2;
			return new Node(grid[startx][starty], true, nullptr, nullptr, nullptr, nullptr);
		}
		int state1, state2, state3, state4;
		Node* newNode = new Node(true, false, 
			construct(grid, startx, startx + (endx - startx >> 1), starty, starty + (endy - starty >> 1), state1),
			construct(grid, startx, startx + (endx - startx >> 1), starty + (endy - starty >> 1) + 1, endy, state2),
			construct(grid, startx + (endx - startx >> 1) + 1, endx, starty, starty + (endy - starty >> 1), state3),
			construct(grid, startx + (endx - startx >> 1) + 1, endx, starty + (endy - starty >> 1) + 1, endy, state4));
		if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1) {
			state = 1;
			return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
		}
		else if (state1 == 2 && state2 == 2 && state3 == 2 && state4 == 2) {
			state = 2;
			return new Node(false, true, nullptr, nullptr, nullptr, nullptr);
		}
		else {
			state = 0;
			return newNode;
		}
	}
};