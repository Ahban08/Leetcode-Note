struct Dictionary{
    Dictionary *children[26];
    bool isEnd;
    Dictionary(){
        for(int i=0; i<26; i++){
            children[i] = nullptr;   
        }
        isEnd = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new Dictionary();
    }
    
    void addWord(string word) {
        Dictionary *node = root;
        for(int i =0; i < word.length(); i++){
            int ascii = int(word[i])-int('a');
            if(node->children[ascii] == nullptr){
                node->children[ascii] = new Dictionary();
            }
            node = node->children[ascii];
        }
        node->isEnd = true;
    }

    bool dfs(string word, Dictionary *node){
        for(int i =0; i < word.length(); i++){
            int ascii = int(word[i])-int('a');
            if(word[i] == '.'){
                for(int j=0; j<26; j++){
                    if(node->children[j]!=nullptr){
                        if(dfs(word.substr(i+1), node->children[j]) == true)
                            return true;        
                    }
                }
                // cout<<"here1:"<<word<<"\n";
                return false;
            }else{
                if(node->children[ascii] == nullptr){
                    // cout<<"here2:"<<word<<"\n";
                    return false;
                }
            }
            node = node->children[ascii];
        }
        if(node->isEnd == true)
            return true;
        else
            return false;
    }
    bool search(string word) {
        return dfs(word, root);
    }
private:
    Dictionary *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

//N為word長度，M為'.'出現次數
//addWord
//Time Complexity: O(N)
//Space Complexity: O(N)
//search
//Time Complexity: O(N)~O( N*(26^M) )
//Space Complexity: O(1)~O(M) 