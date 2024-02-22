/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> nodeQueue;
        map<TreeNode*, int> levelMap;


        if(root != nullptr){
            nodeQueue.push(root);
        }
        while( !nodeQueue.empty() ){
            TreeNode *node = nodeQueue.front();
            int depth = levelMap[node];
            cout<<"depth"<<depth<<"\n";
            if(res.size() < depth+1){
                res.resize(depth+1);
            }
            res[depth].push_back(node->val);
            nodeQueue.pop();
            if(node->left != nullptr){
                nodeQueue.push(node->left);
                levelMap[node->left] = depth+1;
            }
            if(node->right != nullptr){
                nodeQueue.push(node->right);
                levelMap[node->right] = depth+1;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)