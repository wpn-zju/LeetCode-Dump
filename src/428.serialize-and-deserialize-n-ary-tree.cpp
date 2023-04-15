/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:
	string serialize(Node* root) {
		string result = "";
		if (!root)
			return result;
		dfsNTree(root, result);
		return result;
	}
	
	void dfsNTree(Node* root, string& result) {
		if (!root)
			return;
		result += '[' + to_string(root->val);
		for (Node*& child : root->children)
			dfsNTree(child, result);
		result += ']';
	}
    
	Node* deserialize(string data) {
		if (!data.length())
			return nullptr;
		int ptr = 0;
		Node* dummy = new Node();
		stack<Node*> s;
		Node* cur = dummy;
		s.push(dummy);
		while (ptr != data.length()) {
			cur = s.top();
			if (data[ptr] == '[') {
				ptr++;
				int len = 0;
				bool flag = false;
				if (data[ptr] == '-') {
					flag = true;
					ptr++;
				}
				while (data[ptr] >= '0' && data[ptr] <= '9') {
					len *= 10;
					len += data[ptr] - '0';
					ptr++;
				}
				if (flag)
					len = -len;
				Node* newChild = new Node(len, vector<Node*>());
				cur->children.push_back(newChild);
				s.push(newChild);
			}
			else if (data[ptr] == ']') {
				ptr++;
				s.pop();
			}
		}
		return dummy->children[0];
	}
};