static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class SegmentNode2D {
public:
	int val;
	int startx;
	int endx;
	int starty;
	int endy;
	SegmentNode2D* leftxlefty;
	SegmentNode2D* leftxrighty;
	SegmentNode2D* rightxlefty;
	SegmentNode2D* rightxrighty;

	SegmentNode2D(int startx, int endx, int starty, int endy) {
		this->startx = startx;
		this->endx = endx;
		this->starty = starty;
		this->endy = endy;
		this->leftxlefty = this->leftxrighty = this->rightxlefty = this->rightxrighty = nullptr;
	}
};

class SegmentTree2D {
public:
	int treeType;
	SegmentNode2D* head;

	// 0 -> sum tree
	// 1 -> max tree
	// 2 -> min tree
	SegmentTree2D(vector<vector<int>>& input, int treeType = 0) {
		this->treeType = treeType;
		head = buildTree(input, 0, input.size() - 1, 0, input[0].size() - 1);
	}

	SegmentNode2D* buildTree(vector<vector<int>>& input, int startx, int endx, int starty, int endy) {
		SegmentNode2D* newNode = new SegmentNode2D(startx, endx, starty, endy);
		if (startx == endx && starty == endy) {
			newNode->val = input[startx][starty];
			return newNode;
		}
		int midx = startx + (endx - startx >> 1);
		int midy = starty + (endy - starty >> 1);
		newNode->leftxlefty = buildTree(input, startx, midx, starty, midy);
		if (starty < endy)
			newNode->leftxrighty = buildTree(input, startx, midx, midy + 1, endy);
		if (startx < endx)
			newNode->rightxlefty = buildTree(input, midx + 1, endx, starty, midy);
		if (startx < endx && starty < endy)
			newNode->rightxrighty = buildTree(input, midx + 1, endx, midy + 1, endy);
		switch (treeType)
		{
		case 0:
			newNode->val = newNode->leftxlefty->val;
			if (starty < endy)
				newNode->val += newNode->leftxrighty->val;
			if (startx < endx)
				newNode->val += newNode->rightxlefty->val;
			if (startx < endx && starty < endy)
				newNode->val += newNode->rightxrighty->val;
			break;
		case 1:
			newNode->val = newNode->leftxlefty->val;
			if (starty < endy)
				newNode->val = max(newNode->val, newNode->leftxrighty->val);
			if (startx < endx)
				newNode->val = max(newNode->val, newNode->rightxlefty->val);
			if (startx < endx && starty < endy)
				newNode->val = max(newNode->val, newNode->rightxrighty->val);
			break;
		case 2:
			newNode->val = newNode->leftxlefty->val;
			if (starty < endy)
				newNode->val = min(newNode->val, newNode->leftxrighty->val);
			if (startx < endx)
				newNode->val = min(newNode->val, newNode->rightxlefty->val);
			if (startx < endx && starty < endy)
				newNode->val = min(newNode->val, newNode->rightxrighty->val);
			break;
		}
		return newNode;
	}

	int search(SegmentNode2D* cur, int startx, int endx, int starty, int endy) {
		int result;
		switch (treeType)
		{
		case 0:
			result = 0;
			if (startx == cur->startx && starty == cur->starty && endx == cur->endx && endy == cur->endy)
				return cur->val;
			if (cur->leftxlefty && startx <= cur->leftxlefty->endx && starty <= cur->leftxlefty->endy)
				result += search(cur->leftxlefty, startx, min(endx, cur->leftxlefty->endx), starty, min(endy, cur->leftxlefty->endy));
			if (cur->leftxrighty && startx <= cur->leftxrighty->endx && endy >= cur->leftxrighty->starty)
				result += search(cur->leftxrighty, startx, min(endx, cur->leftxrighty->endx), max(starty, cur->leftxrighty->starty), endy);
			if (cur->rightxlefty && endx >= cur->rightxlefty->startx && starty <= cur->rightxlefty->endy)
				result += search(cur->rightxlefty, max(startx, cur->rightxlefty->startx), endx, starty, min(endy, cur->rightxlefty->endy));
			if (cur->rightxrighty && endx >= cur->rightxrighty->startx && endy >= cur->rightxrighty->starty)
				result += search(cur->rightxrighty, max(startx, cur->rightxrighty->startx), endx, max(starty, cur->rightxrighty->starty), endy);
			break;
		case 1:
			result = INT_MIN;
			if (startx == cur->startx && starty == cur->starty && endx == cur->endx && endy == cur->endy)
				return cur->val;
			if (cur->leftxlefty && startx <= cur->leftxlefty->endx && starty <= cur->leftxlefty->endy)
				result = max(result, search(cur->leftxlefty, startx, min(endx, cur->leftxlefty->endx), starty, min(endy, cur->leftxlefty->endy)));
			if (cur->leftxrighty && startx <= cur->leftxrighty->endx && endy >= cur->leftxrighty->starty)
				result = max(result, search(cur->leftxrighty, startx, min(endx, cur->leftxrighty->endx), max(starty, cur->leftxrighty->starty), endy));
			if (cur->rightxlefty && endx >= cur->rightxlefty->startx && starty <= cur->rightxlefty->endy)
				result = max(result, search(cur->rightxlefty, max(startx, cur->rightxlefty->startx), endx, starty, min(endy, cur->rightxlefty->endy)));
			if (cur->rightxrighty && endx >= cur->rightxrighty->startx && endy >= cur->rightxrighty->starty)
				result = max(result, search(cur->rightxrighty, max(startx, cur->rightxrighty->startx), endx, max(starty, cur->rightxrighty->starty), endy));
			break;
		case 2:
			result = INT_MAX;
			if (startx == cur->startx && starty == cur->starty && endx == cur->endx && endy == cur->endy)
				return cur->val;
			if (cur->leftxlefty && startx <= cur->leftxlefty->endx && starty <= cur->leftxlefty->endy)
				result = min(result, search(cur->leftxlefty, startx, min(endx, cur->leftxlefty->endx), starty, min(endy, cur->leftxlefty->endy)));
			if (cur->leftxrighty && startx <= cur->leftxrighty->endx && endy >= cur->leftxrighty->starty)
				result = min(result, search(cur->leftxrighty, startx, min(endx, cur->leftxrighty->endx), max(starty, cur->leftxrighty->starty), endy));
			if (cur->rightxlefty && endx >= cur->rightxlefty->startx && starty <= cur->rightxlefty->endy)
				result = min(result, search(cur->rightxlefty, max(startx, cur->rightxlefty->startx), endx, starty, min(endy, cur->rightxlefty->endy)));
			if (cur->rightxrighty && endx >= cur->rightxrighty->startx && endy >= cur->rightxrighty->starty)
				result = min(result, search(cur->rightxrighty, max(startx, cur->rightxrighty->startx), endx, max(starty, cur->rightxrighty->starty), endy));
			break;
		}
		return result;
	}

	void update(SegmentNode2D* cur, int indexx, int indexy, int value) {
		if (cur->startx == cur->endx && cur->starty == cur->endy) {
			cur->val = value;
			return;
		}
		int midx = cur->startx + (cur->endx - cur->startx >> 1);
		int midy = cur->starty + (cur->endy - cur->starty >> 1);
		switch (treeType)
		{
		case 0:
			if (indexx <= midx && indexy <= midy) {
				cur->val -= cur->leftxlefty->val;
				update(cur->leftxlefty, indexx, indexy, value);
				cur->val += cur->leftxlefty->val;
			}
			else if (indexx > midx && indexy <= midy) {
				cur->val -= cur->rightxlefty->val;
				update(cur->rightxlefty, indexx, indexy, value);
				cur->val += cur->rightxlefty->val;
			}
			else if (indexx <= midx && indexy > midy) {
				cur->val -= cur->leftxrighty->val;
				update(cur->leftxrighty, indexx, indexy, value);
				cur->val += cur->leftxrighty->val;
			}
			else {
				cur->val -= cur->rightxrighty->val;
				update(cur->rightxrighty, indexx, indexy, value);
				cur->val += cur->rightxrighty->val;
			}
			break;
		case 1:
			if (indexx <= midx && indexy <= midy) {
				cur->val = max(max(cur->leftxrighty->val, cur->rightxlefty->val), cur->rightxrighty->val);
				update(cur->leftxlefty, indexx, indexy, value);
				cur->val = max(cur->val, cur->leftxlefty->val);
			}
			else if (indexx > midx && indexy <= midy) {
				cur->val = max(max(cur->leftxlefty->val, cur->leftxrighty->val), cur->rightxrighty->val);
				update(cur->rightxlefty, indexx, indexy, value);
				cur->val = max(cur->val, cur->rightxlefty->val);
			}
			else if (indexx <= midx && indexy > midy) {
				cur->val = max(max(cur->leftxlefty->val, cur->rightxlefty->val), cur->rightxrighty->val);
				update(cur->leftxrighty, indexx, indexy, value);
				cur->val = max(cur->val, cur->leftxrighty->val);
			}
			else {
				cur->val = max(max(cur->leftxlefty->val, cur->leftxrighty->val), cur->rightxlefty->val);
				update(cur->rightxrighty, indexx, indexy, value);
				cur->val = max(cur->val, cur->rightxrighty->val);
			}
			break;
		case 2:
			if (indexx <= midx && indexy <= midy) {
				cur->val = min(min(cur->leftxrighty->val, cur->rightxlefty->val), cur->rightxrighty->val);
				update(cur->leftxlefty, indexx, indexy, value);
				cur->val = min(cur->val, cur->leftxlefty->val);
			}
			else if (indexx > midx && indexy <= midy) {
				cur->val = min(min(cur->leftxlefty->val, cur->leftxrighty->val), cur->rightxrighty->val);
				update(cur->rightxlefty, indexx, indexy, value);
				cur->val = min(cur->val, cur->rightxlefty->val);
			}
			else if (indexx <= midx && indexy > midy) {
				cur->val = min(min(cur->leftxlefty->val, cur->rightxlefty->val), cur->rightxrighty->val);
				update(cur->leftxrighty, indexx, indexy, value);
				cur->val = min(cur->val, cur->leftxrighty->val);
			}
			else {
				cur->val = min(min(cur->leftxlefty->val, cur->leftxrighty->val), cur->rightxlefty->val);
				update(cur->rightxrighty, indexx, indexy, value);
				cur->val = min(cur->val, cur->rightxrighty->val);
			}
			break;
		}
	}
};

class NumMatrix {
public:
    SegmentTree2D* stree;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() && matrix[0].size())
            stree = new SegmentTree2D(matrix);
    }
    
    void update(int row, int col, int val) {
        stree->update(stree->head, row, col, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return stree->search(stree->head, row1, row2, col1, col2);
    }
};