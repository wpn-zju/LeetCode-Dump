class Solution {
public:
    vector<int> killProcess(const vector<int>& pid, const vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < pid.size(); ++i) {
          int currPid = pid[i];
          int currPPid = ppid[i];
          if (currPPid) {
            M[currPPid].push_back(currPid);
          }
        }
        vector<int> res;
        function<void(int)> traverse;
        traverse = [&] (int pid) {
          res.push_back(pid);
          auto iter = M.find(pid);
          if (iter == M.end()) return;
          for (auto childpid: iter->second) {
            traverse(childpid);
          }
        };
        traverse(kill);
        return res;
    }
};