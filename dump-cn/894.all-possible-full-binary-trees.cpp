/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	unordered_map<int, vector<TreeNode*>> TNMap;
	vector<TreeNode*> allPossibleFBT(int N) {
		for (int i = 1; i <= N; i+=2)
			buildTree(i);
		return TNMap[N];
	}

	void buildTree(int N) {
		vector<TreeNode*> result;
		  
        if(N==1){
			TreeNode* tn = new TreeNode(0);
			result.push_back(tn);           
        }
        else{
            for (int i = 1; i < N; i += 2) {
			    vector<TreeNode*> vec1 = TNMap[i];
			    vector<TreeNode*> vec2 = TNMap[N - i - 1];
			    for (int j = 0; j < vec1.size(); ++j) {
				    for (int k = 0; k < vec2.size(); ++k) {
					    TreeNode* tn = new TreeNode(0);
					    tn->left = vec1[j];
					    tn->right = vec2[k];
					    result.push_back(tn);
				    }
			    }
		    }           
        }     
		
        TNMap[N] = result;
	}
};