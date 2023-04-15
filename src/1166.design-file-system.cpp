static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class FileNode {
public:
	string name;
	int val;
	unordered_map<string, FileNode*> children;

	FileNode(string name, int val) {
		this->name = name;
		this->val = val;
	}
};

vector<string> readString(string& path) {
	path.push_back('/');
	vector<string> result;
	int prev = 1;
	for (int i = 1; i < path.length(); ++i){
 		if (path[i] == '/') {
			result.push_back(path.substr(prev, i - prev));
			prev = i + 1;
		}       
    }
	return result;
}

class FileSystem {
public:
	FileNode* root;
	FileSystem() {
		root = new FileNode("", 0);
	}

	bool createPath(string path, int value) {
		vector<string> strs = readString(path);
		FileNode* cur = root;
		for (int i = 0; i < strs.size() - 1; ++i) {
			if (cur->children.count(strs[i]))
				cur = cur->children[strs[i]];
			else
				return false;
		}
		if (cur->children.count(strs.back()))
			return false;
		cur->children[strs.back()] = new FileNode(strs.back(), value);
		return true;
	}

	int get(string path) {
		vector<string> strs = readString(path);
		FileNode* cur = root;
		for (string& str : strs) {
			if (cur->children.count(str))
				cur = cur->children[str];
			else
				return -1;
		}
		return cur->val;
	}
};