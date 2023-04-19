/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		queue<Node*> myQueue;
		myQueue.push(root);
		while (!myQueue.empty()) {
			int size = myQueue.size();
			vector<int> vec;
			while (size--) {
				for (int i = 0; i < myQueue.front()->children.size(); ++i)
					myQueue.push(myQueue.front()->children[i]);
				vec.push_back(myQueue.front()->val);
				myQueue.pop();
			}
			result.push_back(vec);
		}
        return result;
	}
};