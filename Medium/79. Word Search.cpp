class Solution {
public:
    bool check(vector<vector<char>> board, string word, int i, int j, int index){
        if(index == word.length())
            return true;
        board[i][j] = '\0';
        if(i+1<board.size() && board[i+1][j]==word[index]){
            if(check(board, word, i+1, j, index+1) == true)
                return true;
        }
        if(i>0 && board[i-1][j]==word[index]){
            if(check(board, word, i-1, j, index+1) == true)
                return true;
        }
        if(j+1<board[i].size() && board[i][j+1]==word[index]){
            if(check(board, word, i, j+1, index+1) == true)
                return true;
        }
        if(j>0 && board[i][j-1]==word[index]){
            if(check(board, word, i, j-1, index+1) == true)
                return true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i < board.size(); i++){
            for(int j =0; j < board[i].size(); j++){
                if(board[i][j]==word[0]){
                    if(check(board, word, i, j, 1) == true)
                        return true;
                }
            }
        }
        return false;
    }
};

//Time Limit Exceeded
//Board size: n*m = N, word length: L
//Time Complexity: O(N*L)
//Space Complexity: O(N +L)

class Solution_2 {
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

    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i < board.size(); i++){
            for(int j =0; j < board[i].size(); j++){
                if(dfs(board, word, i, j, 0) == true)
                    return true;
            }
        }
        return false;
    }
};
//Board size: n*m = N, word length: L
//Time Complexity: O(N*L)
//Space Complexity: O(L)