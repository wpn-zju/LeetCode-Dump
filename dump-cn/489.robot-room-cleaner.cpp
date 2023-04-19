class Solution {
public:
	vector<int> xV{ -1,0,1,0 };
	vector<int> yV{ 0,1,0,-1 };
	void dfsRobot(Robot& robot, unordered_set<string>& visited, int x, int y, int dir) {
		string key = to_string(x) + ',' + to_string(y);
		if (visited.count(key))
			return;
		visited.insert(key);
		robot.clean();
		for (int i = 0; i < 4; ++i) {
			// 先至少转一个方向
			int newDir = (dir + i + 1) % 4;
			int x1 = x + xV[newDir];
			int y1 = y + yV[newDir];
			// 转向后如果面对障碍物 进入下一个方向
			robot.turnRight();
			if (!robot.move())
				continue;
			// 下层遍历
			dfsRobot(robot, visited, x1, y1, newDir);
			// 遍历完返回 转180度后走一步即可
			robot.turnRight();
			robot.turnRight();
			robot.move();
			// 返回后记得要把朝向转过来 再转180度
			robot.turnRight();
			robot.turnRight();
		}
	}

	void cleanRoom(Robot& robot) {
		unordered_set<string> visited;
		dfsRobot(robot, visited, 0, 0, 0);
	}
};