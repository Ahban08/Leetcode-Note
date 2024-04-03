class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index){
        if( i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        
        if( board[i][j] == word[index]){
            board[i][j] = '\0';
            if( index == word.length()-1 ||
                dfs(board, word, i+1, j, index+1) ||
                dfs(board, word, i-1, j, index+1) ||
                dfs(board, word, i, j+1, index+1) ||
                dfs(board, word, i, j-1, index+1) ){
                return true;}
            board[i][j] = word[index];
        }
        
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        bool exist;
        for(int i =0; i < words.size(); i++){
            exist = 0;
            for(int j =0; j < board.size(); j++){
                for(int k =0; k < board[j].size(); k++){
                    vector<vector<char>> board_copy = board;
                    if(dfs(board_copy, words[i], j, k, 0) == true){
                        res.push_back(words[i]);
                        exist = 1;
                        break;
                    }
                }
                if(exist)
                    break;
            }
        }
        return res;
    }
};
//Time Limit Exceeded

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

class Solution {
public:
    Dictionary *root = new Dictionary();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(int index =0; index < words.size(); index++){
            addWord(words[index]);
        }

        for(int i =0; i < board.size(); i++){
            for(int j =0; j < board[i].size(); j++){
                find(board, "", i, j, root, res);
            }
        }
        return res;
    }
    
    void addWord(string word) {
        Dictionary *node = root;
        int ascii;
        for(int i =0; i < word.length(); i++){
            ascii = int(word[i])-int('a');
            if(node->children[ascii] == nullptr){
                node->children[ascii] = new Dictionary();
            }
            node = node->children[ascii];
        }
        node->isEnd = true;
    }

    void find(vector<vector<char>> &board, string word, int i, int j, Dictionary *node, vector<string> &res){
        if( i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '\0')
            return;
        
        char c = board[i][j];
        int ascii = c -int('a');
        node = node->children[ascii];
        if(node){
            word += c;
            if( node->isEnd ){
                res.push_back(word);
                node->isEnd = false;
            }
            board[i][j] = '\0';
            find(board, word, i+1, j, node, res);
            find(board, word, i-1, j, node, res);
            find(board, word, i, j+1, node, res);
            find(board, word, i, j-1, node, res);
            board[i][j] = c;
        }else
            return;
    }
};
//N is the total number of characters in all the words
//M is the number of cells in the board
//L is the length of the longest word in the trie
//Time Complexity:  O(N + M * 4^L), 
//Space Complexity: O(N + L)