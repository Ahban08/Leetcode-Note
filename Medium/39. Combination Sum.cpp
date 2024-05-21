class Solution {
public:
    
    void backTracking(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &current, int start) {
        if(target == 0){
            res.push_back(current);
            return;
        }
        if(target < 0){
            // current.pop_back();
            return;
        }
        
        for(int i =start; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            backTracking(candidates, target-candidates[i], res, current, i);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // map<int, vector<vector<int>>> candidatesMap;
        vector<vector<int>> res;
        vector<int> current;
        backTracking(candidates, target, res, current, 0);
        return res;
    }
};

//Time Complexity: O(n ^(target/min(candidates)))
//Space Complexity: O(target/min(candidates))+O(k⋅m)