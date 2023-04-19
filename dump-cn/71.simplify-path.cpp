static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> s;
		for (int i = 0; i < path.length(); ++i) {
			if (path[i] == '.') {
				++i;
				if (i < path.length() && path[i] == '.') {
					++i;
					if (i < path.length() && path[i] == '.') {
						++i;
						string cur = "...";
						while (i < path.length() && path[i] != '/')
							cur.push_back(path[i++]);
						s.push(cur);
					}
					else if (i < path.length() && path[i] != '/') {
						string cur = "..";
						while (i < path.length() && path[i] != '/')
							cur.push_back(path[i++]);
						s.push(cur);
					}
					else if (!s.empty())
						s.pop();
				}
				else if (i < path.length() && path[i] != '/') {
					string cur = ".";
					while (i < path.length() && path[i] != '/')
						cur.push_back(path[i++]);
					s.push(cur);
				}
			}
			else if (path[i] != '/') {
				string cur = "";
				while (i < path.length() && path[i] != '/')
					cur.push_back(path[i++]);
				s.push(cur);
			}
		}
		string result = "";
		while (!s.empty()) {
			result = '/' + s.top() + result;
			s.pop();
		}
		return result.empty() ? "/" : result;
	}
};