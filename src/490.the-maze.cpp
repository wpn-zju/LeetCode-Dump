class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        return dfs(maze, start, destination, 0, visited)
            || dfs(maze, start, destination, 1, visited)
            || dfs(maze, start, destination, 2, visited)
            || dfs(maze, start, destination, 3, visited);
    }
    
private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, int dir, vector<vector<int>>& visited) {
        visited[start[0]][start[1]] = 1;
        int i = start[0];
        int j = start[1];
        while (1) {
            int next_i = i + direction[dir][0];
            int next_j = j + direction[dir][1];
            if (next_i < 0 || next_i == maze.size() || next_j < 0 || next_j == maze[0].size() || maze[next_i][next_j] == 1) {
                break;
            }
            i = next_i;
            j = next_j;
        }
        if (visited[i][j] == 1) {
            return false;
        }
        if (i == destination[0] && j == destination[1]) {
            return true;
        }
        vector<int> next_start = {i, j};
        return dfs(maze, next_start, destination, (dir + 1) % 4, visited)
            || dfs(maze, next_start, destination, (dir + 2) % 4, visited)
            || dfs(maze, next_start, destination, (dir + 3) % 4, visited);
    }
};