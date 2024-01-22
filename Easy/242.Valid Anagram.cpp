class Solution {
public:
    bool isAnagram(string s, string t) {
        int letterDistribution[26] = {};
        int letterAsciiS, letterAsciiT;
        bool res = true;
        if (s.length() != t.length()){
            res = false;
        }else{
            for (int i = 0; i < s.length(); i++){
                letterAsciiS = int(s.at(i));
                letterDistribution[letterAsciiS-97]++;
                letterAsciiT = int(t.at(i));
                letterDistribution[letterAsciiT-97]--;  
            }
            for (int k = 0; k < 26; k++){
                if( letterDistribution[k] != 0){
                    res =false;
                    break;
                }
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)