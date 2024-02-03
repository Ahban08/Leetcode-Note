class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = 0;
        map<char, int> charExist;

        int size = s.length();
        for ( int i = 0; i < size; i++){
            if( charExist.find(s[i]) != charExist.end()){
                res = max( res, i-start);
                start = max(start, charExist[s[i]]+1);
            }
            charExist[s[i]] = i;
        }
        res = max( res, size-start);
        return res;
    }
};
//N (the length of the string) and N (the number of character types in the string)
//Time Complexity: O(N)
//Space Complexity: O(min(N,M))