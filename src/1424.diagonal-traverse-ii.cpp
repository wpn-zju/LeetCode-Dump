class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> memory;

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j) {
                if(memory.size() < i + j + 1) {
                    memory.emplace_back(vector<int>());
                }
                memory[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> result;

        // for(auto it = memory.begin(); it != memory.end(); ++it) {
        //     for(int i = it->second->size() - 1; i >= 0; --i) {
        //         result.push_back(it->second->at(i));
        //     }
        // }

        for(vector<int>& vec : memory) {
            for(int i = vec.size() - 1; i >= 0; --i) {
                result.push_back(vec[i]);
            }
        }

        return result;
    }
};