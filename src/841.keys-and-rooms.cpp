class Solution {
public:
		bool canVisitAllRooms(vector<vector<int>>& rooms) {
			vector<bool> visited(rooms.size(), false);
			dfsCVAR(rooms, visited, 0);
            for(bool b : visited)
                if(!b)
                    return false;
			return true;
		}

		void dfsCVAR(vector<vector<int>>& rooms, vector<bool>& visited, int cur) {
			visited[cur] = true;
			for (int i : rooms[cur])
				if (!visited[i])
					dfsCVAR(rooms, visited, i);
		}
};