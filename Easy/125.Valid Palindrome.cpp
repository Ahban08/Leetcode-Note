#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;
        string str;
        size_t front = 0, back;
        
        for(size_t i = 0;  i < s.length(); i++){
            char c = tolower(s.at(i));
            if(isalnum(c)){
                str.push_back(c);
            }
        }
        if(str.length()>1){
            back = str.length()-1;
        }else{
            return res;
        }

        while( front < back ){
            if( str.at(front) != str.at(back)){
                res = false;
                break;
            }
            if(front == str.length() || back == 0){
                break;
            }
            else{
                front++;
                back--;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

int main() {
    Solution sol;
    string input = " ";
    cout << "Is palindrome: " << sol.isPalindrome(input) << endl;
    return 0;
}