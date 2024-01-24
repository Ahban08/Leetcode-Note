class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::map<string, int> groupMap;
        int set= 0;
        for (int i = 0; i < strs.size(); i++){
            string sortedStr = strs[i];
            std::sort (sortedStr.begin(), sortedStr.end());
            if(groupMap.find(sortedStr)!= groupMap.end()){
                res[groupMap[sortedStr]].push_back(strs[i]);
            }else{
                groupMap[sortedStr] = res.size();
                //cout<<"size:"<<res.size();
                res.resize(res.size() + 1);
                res[groupMap[sortedStr]].push_back(strs[i]);
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)