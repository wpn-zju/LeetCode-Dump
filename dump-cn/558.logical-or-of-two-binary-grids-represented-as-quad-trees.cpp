class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (quadTree1->isLeaf && quadTree2->isLeaf)
			return new Node(quadTree1->val || quadTree2->val, true, nullptr, nullptr, nullptr, nullptr);
		else if (quadTree1->isLeaf) {
			if (quadTree1->val)
				return quadTree1;
			else
				return quadTree2;
		}
		else if (quadTree2->isLeaf) {
			if (quadTree2->val)
				return quadTree2;
			else
				return quadTree1;
		}
		else {
			Node* newNode = new Node(false, false,
				intersect(quadTree1->topLeft, quadTree2->topLeft),
				intersect(quadTree1->topRight, quadTree2->topRight),
				intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
				intersect(quadTree1->bottomRight, quadTree2->bottomRight));
			if (newNode->bottomLeft->isLeaf && newNode->bottomRight->isLeaf && newNode->topLeft->isLeaf && newNode->topRight->isLeaf) {
				if (newNode->bottomLeft->val == newNode->bottomRight->val && newNode->bottomRight->val == newNode->topRight->val && newNode->topRight->val == newNode->topLeft->val) {
					newNode->isLeaf = true;
					newNode->val = newNode->bottomLeft->val;
					newNode->bottomLeft = newNode->bottomRight = newNode->topLeft = newNode->topRight = nullptr;
				}
			}
			return newNode;
		}
	}
};