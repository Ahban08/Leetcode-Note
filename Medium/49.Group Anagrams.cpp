class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::map<string, int> groupMap;
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
//M (the number of strings) and N (the average length of strings)
//Time Complexity: O(M*NlogN)
//Space Complexity: O(M)

//將sort()換成二維陣列紀錄字串的字母分布
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::map<string, int> groupMap;
        for (int i = 0; i < strs.size(); i++){
            int letterDistribution[26] ={};
            for (int j = 0; j < strs[i].length(); j++){
                int letterAscii = int(strs[i].at(j));
                letterDistribution[letterAscii-int('a')]++;
            }
            string letterCount = "";
            for (int k = 0; k < 26; k++){
                letterCount.append(to_string(letterDistribution[k]));
                letterCount.append(",");
            }
            if(groupMap.find(letterCount)!= groupMap.end()){
                res[groupMap[letterCount]].push_back(strs[i]);
            }else{
                groupMap[letterCount] = res.size();
                res.resize(res.size() + 1);
                res[groupMap[letterCount]].push_back(strs[i]);
            }
        }
        return res;
    }
};
//M (the number of strings) and N (the average length of strings)
//Time Complexity: O(M*N)
//Space Complexity: O(M)