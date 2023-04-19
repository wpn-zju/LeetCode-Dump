class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        return recoverFromPreorder(S, 0, S.length() - 1, 0);
    }
    
    TreeNode* recoverFromPreorder(string& S, int start, int end, int len){
        if(start > end)
            return nullptr;
        vector<int> vec = findLen(S, start, end, len + 1);
        int rootVal = 0;
        int ptr = start;
        while(S[ptr] >= '0' && S[ptr] <= '9'){
            rootVal *= 10;
            rootVal += S[ptr] - '0';
            ptr++;
        }
        TreeNode* root = new TreeNode(rootVal);
        if(vec.size() == 1)
            root->left = recoverFromPreorder(S, vec[0], end, len + 1);
        else if(vec.size() == 2){
            root->left = recoverFromPreorder(S, vec[0], vec[1] - len - 2, len + 1);
            root->right = recoverFromPreorder(S, vec[1], end, len + 1);            
        }
        return root;
    }
    
    vector<int> findLen(string& S, int& start, int& end, int len){
        vector<int> result;
        int ptr1 = start;
        int ptr2 = start;
        while (true){
            while (ptr2 <= end && S[ptr2] != '-')
                ptr1 = ++ptr2;
            if (ptr2 > end)
                break;
            while (S[ptr2] == '-')
                ptr2++;
            if (ptr2 - ptr1 == len)
                result.push_back(ptr2);
        }
        return result;
    }
};