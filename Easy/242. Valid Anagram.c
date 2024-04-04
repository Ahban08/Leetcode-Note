#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int hash[26] ={0};
    int index = 0;
    if(strlen(s)!=strlen(t)) 
        return false;
    while(s[index]){
        hash[s[index]-'a']++;
        hash[t[index]-'a']--;
        index++;
    }
    for(int i = 0; i < 26; i++){
        if(hash[i]!=0){
            // printf("%c count is %d", i+'a', hash[i]);
            return false;
        } 
    }
    return true;
}