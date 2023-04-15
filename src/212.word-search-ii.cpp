static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
	class CharNode5 {
	public:
		bool selfEnabled = false;
		vector<CharNode5*>* next;

		CharNode5() {
			next = new vector<CharNode5*>(26, nullptr);
		}
	};

	class Trie5 {
	public:
		CharNode5* head;

		Trie5() {
			head = new CharNode5();
		}

		void insert(string& word) {
			CharNode5* ptr = head;
			int index = 0;
			while (index != word.length() && ptr->next->at(word[index] - 'a'))
				ptr = ptr->next->at(word[index++] - 'a');
			while (index != word.length()) {
				ptr->next->at(word[index] - 'a') = new CharNode5();
				ptr = ptr->next->at(word[index++] - 'a');
			}
			ptr->selfEnabled = true;
		}

		void searchUsingBoard(vector<vector<char>>& board, vector<string>& result) {
			string tmp = "";
			for (int i = 0; i < board.size(); ++i) {
				for (int j = 0; j < board[0].size(); ++j) {
					if (head->next->at(board[i][j] - 'a')) {
						vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
						tmp.push_back(board[i][j]);
						dfsSearch(board, result, head->next->at(board[i][j] - 'a'), tmp, i, j, visited);
						tmp.pop_back();
					}
				}
			}
		}

		void dfsSearch(vector<vector<char>>& board, vector<string>& result, CharNode5* cur, string& str, int x, int y, vector<vector<bool>>& visited) {
			if (cur->selfEnabled) {
				result.push_back(str);
				cur->selfEnabled = false;
			}
			visited[x][y] = true;
			if (x != 0 && !visited[x - 1][y] && cur->next->at(board[x - 1][y] - 'a')) {
				str.push_back(board[x - 1][y]);
				dfsSearch(board, result, cur->next->at(board[x - 1][y] - 'a'), str, x - 1, y, visited);
				str.pop_back();
			}
			if (x != board.size() - 1 && !visited[x + 1][y] && cur->next->at(board[x + 1][y] - 'a')) {
				str.push_back(board[x + 1][y]);
				dfsSearch(board, result, cur->next->at(board[x + 1][y] - 'a'), str, x + 1, y, visited);
				str.pop_back();
			}
			if (y != 0 && !visited[x][y - 1] && cur->next->at(board[x][y - 1] - 'a')) {
				str.push_back(board[x][y - 1]);
				dfsSearch(board, result, cur->next->at(board[x][y - 1] - 'a'), str, x, y - 1, visited);
				str.pop_back();
			}
			if (y != board[0].size() - 1 && !visited[x][y + 1] && cur->next->at(board[x][y + 1] - 'a')) {
				str.push_back(board[x][y + 1]);
				dfsSearch(board, result, cur->next->at(board[x][y + 1] - 'a'), str, x, y + 1, visited);
				str.pop_back();
			}
			visited[x][y] = false;
		}
	};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> output;
		Trie5 trie;
		for (string& str : words)
			trie.insert(str);
		trie.searchUsingBoard(board, output);
		return output;
	}
};