#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool res =true;
        stack<char> openBrackets;

        for(int i = 0; i < s.length() && res==true; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                openBrackets.push(s[i]);
            }else{
                if(!openBrackets.empty()){
                    char bracket = openBrackets.top();
                    openBrackets.pop();
                    switch(s[i]){
                        case ')':
                            if(bracket != '('){
                                res =false;
                                return res;
                            }
                            break;
                        case '}':
                            if(bracket != '{'){
                                res =false;
                                return res;
                            }
                            break;
                        case ']':
                            if(bracket != '['){
                                res =false;
                                return res;
                            }
                            break;
                        default :
                            res =false;
                            return res;
                            break;
                    }
                }else{
                    res =false;
                    return res;
                    // break;
                }
            }
        }
        if(!openBrackets.empty()){
            res = false;
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

int main() {
    Solution sol;
    string input = "{[]}";
    cout << "Output: " << sol.isValid(input) << endl;
    return 0;
}