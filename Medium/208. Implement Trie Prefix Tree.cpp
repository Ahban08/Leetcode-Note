class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.length(); i++){
            int ascii = int(word[i]-int('a'));
            if( node->children[ascii] == nullptr){
                node->children[ascii] = new TrieNode();
            }
            node = node->children[ascii];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        bool res = true;
        TrieNode *node = root;
        for(int i = 0; i < word.length(); i++){
            int ascii = int(word[i]-int('a'));
            if( node->children[ascii] == nullptr){
                res =false;
                break;
            }
            node = node->children[ascii];
        }
        if(node->isEnd == false){
            res =false;
        }
        return res;
    }
    
    bool startsWith(string prefix) {
        bool res = true;
        TrieNode *node = root;
        for(int i = 0; i < prefix.length(); i++){
            int ascii = int(prefix[i]-int('a'));
            if( node->children[ascii] == nullptr){
                res =false;
                break;
            }
            node = node->children[ascii];
        }
        return res;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//N為word長度
//insert
//Time Complexity: O(N)
//Space Complexity: O(N) 
//search
//Time Complexity: O(N)
//Space Complexity: O(1) 
//startsWith
//Time Complexity: O(N)
//Space Complexity: O(1) 