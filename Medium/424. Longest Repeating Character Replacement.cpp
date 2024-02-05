class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 1, slow, fast;
        char slowChar;

        for(slow = 0; slow < s.length()-1; slow++){
            if( slow > 0 && s[slow] == s[slow-1]){
                continue;
            }
            int replaceNum = 0;
            for(fast = slow+1; fast < s.length(); fast++){
                if( s[slow] != s[fast] ){
                    if(replaceNum < k){
                        replaceNum++;
                        res = max(res, fast-slow+1);
                    }else{
                        break;
                    }
                }
            }
            res = max(res, fast-slow+min(k-replaceNum, slow)) ;
        }
        return res;
    }
};
//Time Complexity: O(N^2)
//Space Complexity: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 1, slow = 0, fast, mostFreq = 0;
        map<char, int> mapCount;

        for(fast = 0; fast < s.length(); fast++){
            mapCount[s[fast]]++;
            mostFreq = max( mostFreq, mapCount[s[fast]]);
            int windowLength = fast-slow+1;
            while( windowLength - mostFreq > k){
                mapCount[s[slow]]--;
                slow++;
                windowLength--;
                // mostFreq = 0;
                // for(auto it = mapCount.begin(); it != mapCount.end(); it++){
                //     mostFreq = max( mostFreq, it->second);
                // }  
            }
            res = max( res, windowLength);
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)
//While迴圈中未必需要更新最正確的mostFreq數值，因為k為定值，只有mostFreq變大時windowLength才有機會增加，才能改變res