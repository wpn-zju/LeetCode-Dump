class Solution {
public:
	unordered_map<Node*, Node*> mySet;
	Node* cloneGraph(Node* node) {
		dfsGraph(node);
		for (pair<Node*, Node*> a : mySet) {
			if (!mySet[a.first])
				mySet[a.first] = new Node(a.first->val, vector<Node*>());
			for (Node* nd : a.first->neighbors)
				if (mySet[nd] != nullptr)
					mySet[a.first]->neighbors.push_back(mySet[nd]);
				else
					mySet[a.first]->neighbors.push_back(mySet[nd] = new Node(nd->val, vector<Node*>()));
		}
		return mySet[node];
	}

	void dfsGraph(Node* node) {
		mySet[node] = nullptr;
		for (Node* nd : node->neighbors)
			if (!mySet.count(nd))
				dfsGraph(nd);
	}
};