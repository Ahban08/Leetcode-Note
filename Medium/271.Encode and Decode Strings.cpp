class Solution {
public:

    string encode(vector<string>& strs) {
        string enRes;
        for(int i = 0; i < strs.size(); i++){
            string word = strs[i];
            size_t found = word.find_first_of(';');
            while (found != string::npos)
            {
                // cout<<"found"<<found;
                word.insert(found, ";");
                found = word.find_first_of(';', found+2);
            }
            enRes += word+";";
        }
        return enRes;
    }

    vector<string> decode(string s) {
        vector<string> deRes;
        size_t found = s.find(';');
        while (found != std::string::npos)
        {
            if( s.substr(found, 2) != ";;"){
                deRes.push_back(s.substr(0, found));
                s.erase(0, found+1);
                found = s.find(';');
            }else{
                s.erase(found, 1);
                found = s.find(';', found + 1);
            }
        }
        return deRes;
    }
};
//N為字串總長度，K為陣列長度(字串個數)
//Time Complexity: O(N)
//Space Complexity: O(K)