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

//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
//如果使用unicode，即無法使用array的方式進行比較，可轉而使用hashmap
class Solution_2 {
public:
    bool isAnagram(string s, string t) {
        std::map<char,int> counter;
        char letterS, letterT;
        bool res = true;
        if (s.length() != t.length()){
            res = false;
        }else{
            for (int i = 0; i < s.length(); i++){
                letterS = s[i];
                counter[letterS]++;
                letterT = t[i];
                counter[letterT]--;
            }
            for (auto pair : counter){
                if (pair.second != 0){
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