#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int slow, fast;
        multiset<char> tChar, tempChar;
        set<int> exsitIndex;

        for(int i = 0; i < t.length(); i++){
            tChar.insert(t[i]);
        }
        for(int j = 0; j < s.length(); j++){
            if( tChar.find(s[j]) != tChar.end()){
                exsitIndex.insert(j);
                // cout<<"slow:"<<slow<<" fast:"<<fast<<endl;
            }
        }
        res = s;
        bool update = false;
        multiset<int>::iterator it=exsitIndex.begin();
        slow = *it;
        fast = slow;
        while(!exsitIndex.empty() ){
            slow = *exsitIndex.begin();
            // cout<<"First//slow:"<<slow<<" fast:"<<fast<<endl;
            while(!tChar.empty()){
                fast = *it;
                if(it == exsitIndex.end()){
                    break;
                }else{
                    it++;
                }
                multiset<char>::iterator posFast =tChar.find(s[fast]);
                if( posFast != tChar.end()){
                    tChar.erase(posFast);
                }else{
                    tempChar.insert(s[fast]);
                    // cout<<s[slow]<<" put in tempChar"<<"\n";
                }
                
            }
            if(fast-slow+1 <= res.length() && tChar.empty()){
                // cout << "substr: " << s.substr(slow, fast-slow+1) <<"\n";
                res = s.substr(slow, fast-slow+1);
                update = true;
            }
            exsitIndex.erase(slow);
            multiset<char>::iterator posSlow =tempChar.find(s[slow]);
            if( posSlow != tempChar.end()){
                    tempChar.erase(posSlow);
                    // cout<<s[slow]<<" found in tempChar"<<"\n";
            }else{
                tChar.insert(s[slow]);
            }
            

        }
        if(!update){
            res ="";
        }
        return res;
    }
};
//Time Complexity: O(|S|+|T|)
//Space Complexity: O(|S|+|T|)

class Solution_1 {
public:
    string minWindow(string s, string t) {
        string res;
        int slow =0, fast=0, first, length;
        multiset<char> tList, tChar, tempChar;

        for(int i = 0; i < t.length(); i++){
            tChar.insert(t[i]);
        }
        tList = tChar;
        res = s;
        bool update = false;
        
        for(int slow = 0; slow < s.length(); slow++){
            if(tList.find(s[slow]) != tList.end()){
                // cout<<"First//slow:"<<slow<<" fast:"<<fast<<endl;
                while(!tChar.empty() && fast < s.length()){
                    if(tList.find(s[fast]) != tList.end()){
                        multiset<char>::iterator posFast =tChar.find(s[fast]);
                        if( posFast != tChar.end()){
                            tChar.erase(posFast);
                        }else{
                            tempChar.insert(s[fast]);
                            // cout<<s[fast]<<" put in tempChar"<<"\n";
                        }
                        fast++;
                    }else{
                        fast++;
                        continue;
                    }
                    
                }
                // cout<<"Then//slow:"<<slow<<" fast:"<<fast-1<<endl;
                if(fast-slow <= length && tChar.empty()){
                    // cout << "substr: " << s.substr(slow, fast-slow) <<"\n";
                    // res = s.substr(slow, fast-slow);
                    first = slow;
                    length = fast-slow;
                    update = true;
                }
                // exsitIndex.erase(slow);
                multiset<char>::iterator posSlow =tempChar.find(s[slow]);
                if( posSlow != tempChar.end()){
                        tempChar.erase(posSlow);
                        // cout<<s[slow]<<" found in tempChar"<<"\n";
                }else{
                    tChar.insert(s[slow]);
                }    
            }else{
                continue;
            }

        }
        if(!update){
            res ="";
        }else{
            res = s.substr(first, length);
        }
        return res;
    }
};
//Time Complexity: O(|S|+|T|)
//Space Complexity: O(|S|+|T|)

class Solution_2 {
public:
    string minWindow(string s, string t) {
        string res;
        int slow =0, fast=0, have =0, need, first, length;
        map<char, int> window, tChar;

        for(int i = 0; i < t.length(); i++){
            tChar[t[i]]++;
        }
        need = tChar.size();
        res = s;
        bool update = false;
        
        for(int slow = 0; slow < s.length(); slow++){
            if(tChar.find(s[slow]) != tChar.end()){
                while(have != need && fast < s.length()){
                    if(tChar.find(s[fast]) != tChar.end()){
                        window[s[fast]]++;
                        if( window[s[fast]] == tChar[s[fast]]){
                            have++;
                        }
                        fast++;
                    }else{
                        fast++;
                        continue;
                    }
                    
                }
                if(fast-slow <= length && have == need){
                    first = slow;
                    length = fast-slow;
                    update = true;
                }
                window[s[slow]]--;
                if( window[s[slow]] < tChar[s[slow]]){
                        have--;
                }   
            }else{
                continue;
            }

        }
        if(!update){
            res ="";
        }else{
            res = s.substr(first, length);
        }
        return res;
    }
};
//Time Complexity: O(|S|+|T|)
//Space Complexity: O(|S|+|T|)

int main() {
    Solution sol;
    string inputS = "aa", inputT = "aa";
    cout << "Output: " << sol.minWindow(inputS, inputT) << endl;
    return 0;
}