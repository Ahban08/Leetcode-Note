class Solution {
public:
    void DFS(vector<vector<char>> &color, stack<pair<int, int>> &grayNode, vector<vector<char>> &grid){
        pair<int, int> curr = grayNode.top();
        int i = curr.first;
        int j = curr.second;
        //go up
        if( i-1 >= 0 && color[i-1][j] == 'w'){
            color[i-1][j] = 'g';
            if(grid[i-1][j] == '1'){
                pair<int, int> node = make_pair(i-1,j);
                grayNode.push(node);
                DFS(color, grayNode, grid);
            }
            // cout << " sub i:" << i << "\n"<< endl;
            // cout << " sub j:" << j << "\n"<< endl;
        } 
        //go left
        if( j-1 >= 0 && color[i][j-1] == 'w'){
            color[i][j-1] = 'g';
            if(grid[i][j-1] == '1'){
                pair<int, int> node = make_pair(i,j-1);
                grayNode.push(node);
                DFS(color, grayNode, grid);
            }
            // cout << " subsub i:" << i << "\n"<< endl;
            // cout << " subsub j:" << j << "\n"<< endl;
        }
        //go down
        if( i+1 < grid.size() && color[i+1][j] == 'w'){
            color[i+1][j] = 'g';
            if(grid[i+1][j] == '1'){
                pair<int, int> node = make_pair(i+1,j);
                grayNode.push(node);
                DFS(color, grayNode, grid);
            }
            // cout << " sub i:" << i << "\n"<< endl;
            // cout << " sub j:" << j << "\n"<< endl;
        }
        //go right 
        if( j+1 < grid[i].size() && color[i][j+1] == 'w'){
            color[i][j+1] = 'g';
            if(grid[i][j+1] == '1'){
                pair<int, int> node = make_pair(i,j+1);
                grayNode.push(node);
                DFS(color, grayNode, grid);
            }
            // cout << " subsub i:" << i << "\n"<< endl;
            // cout << " subsub j:" << j << "\n"<< endl;
        }
        color[i][j] = 'b';
        grayNode.pop();
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<char>> color(grid);
        stack<pair<int, int>> grayNode;

        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[i].size(); j++){
                color[i][j] = 'w'; //white
            }
        }
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[i].size(); j++){
                if(color[i][j] == 'w'){
                    color[i][j] = 'g';
                    if(grid[i][j] == '1'){
                        pair<int, int> node = make_pair(i,j);
                        grayNode.push(node);
                        DFS(color, grayNode, grid);
                        res ++;
                        // cout << "i:" << i << "\n"<< endl;
                        // cout << "j:" << j << "\n"<< endl;
                    }
                }
            }
        }
        return res;
    }
};
//Time Complexity: O(N*M)
//Space Complexity: O(N*M)

class Solution_1 {
public:
    void DFS(vector<vector<char>> &grid, int i, int j){
        if( i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i ,j);
                    res ++;
                    // cout << "i:" << i << "\n"<< endl;
                    // cout << "j:" << j << "\n"<< endl;
                }
            }
        }
        return res;
    }
};
//Time Complexity: O(N*M)
//Space Complexity: O(1)