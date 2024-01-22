class Solution {
public:
    bool isAnagram(string s, string t) {
        int letterDistribution[26] = {};
        int letterAscii;
        bool res = true;
        for (int i = 0; i < s.length(); i++){
            letterAscii = int(s.at(i));
            letterDistribution[letterAscii-97]++; 
        }
        for (int j = 0; j < t.length(); j++){
            letterAscii = int(t.at(j));
            letterDistribution[letterAscii-97]--; 
        }
        for (int k = 0; k < 26; k++){
            if( letterDistribution[k] != 0){
                res =false;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)