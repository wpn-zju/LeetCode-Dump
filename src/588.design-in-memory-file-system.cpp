vector<string> readString(string path) {
	path.push_back('/');
	vector<string> result;
	int prev = 1;
	for (int i = 1; i < path.length(); ++i) {
		if (path[i] == '/') {
			result.push_back(path.substr(prev, i - prev));
			prev = i + 1;
		}
	}
	return result;
}

class FileNode2 {
public:
	string name;
	unordered_map<string, string> content;
	unordered_map<string, FileNode2*> children;

	FileNode2(string name) {
		this->name = name;
	}
};

class FileSystem {
public:
	FileNode2* root;
	FileSystem() {
		root = new FileNode2("");
	}

	vector<string> ls(string path) {
		if (path.length() == 1) {
			vector<string> target;
			for (pair<string, string> f : root->content)
				target.push_back(f.first);
			for (pair<string, FileNode2*> f : root->children)
				target.push_back(f.first);
            sort(target.begin(), target.end());
			return target;
		}
		vector<string> strs = readString(path);
		FileNode2* cur = root;
		for (int i = 0; i < strs.size() - 1; ++i)
			if (cur->children.count(strs[i]))
				cur = cur->children[strs[i]];
		if (cur->children.count(strs.back())) {
			vector<string> target;
			for (pair<string, string> f : cur->children[strs.back()]->content)
				target.push_back(f.first);
			for (pair<string, FileNode2*> f : cur->children[strs.back()]->children)
				target.push_back(f.first);
			sort(target.begin(), target.end());
			return target;
		}
		return { strs.back() };
	}

	void mkdir(string path) {
		vector<string> strs = readString(path);
		FileNode2* cur = root;
		for (int i = 0; i < strs.size(); ++i)
			if (cur->children.count(strs[i]))
				cur = cur->children[strs[i]];
			else
				cur = cur->children[strs[i]] = new FileNode2(strs[i]);
	}

	void addContentToFile(string filePath, string content) {
		vector<string> strs = readString(filePath);
		FileNode2* cur = root;
		for (int i = 0; i < strs.size() - 1; ++i)
			if (cur->children.count(strs[i]))
				cur = cur->children[strs[i]];
			else
				cur = cur->children[strs[i]] = new FileNode2(strs[i]);
		if (cur->content.count(strs.back()))
			cur->content[strs.back()] += content;
		else
			cur->content[strs.back()] = content;
	}

	string readContentFromFile(string filePath) {
		vector<string> strs = readString(filePath);
		FileNode2* cur = root;
		for (int i = 0; i < strs.size() - 1; ++i)
			if (cur->children.count(strs[i]))
				cur = cur->children[strs[i]];
			else
				cur = cur->children[strs[i]] = new FileNode2(strs[i]);
		return cur->content[strs.back()];
	}
};