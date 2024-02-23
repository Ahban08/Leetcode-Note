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
    queue<int> LDR(TreeNode* root){
        queue<int> res;
        if( root->left != nullptr ){
            queue<int> leftQueue = LDR( root->left );
            while (!leftQueue.empty()){
                res.push(leftQueue.front());
                leftQueue.pop();
            }
        }
        res.push(root->val);
        cout<<"put:"<<root->val<<"\n";
        if( root->right != nullptr ){
            queue<int> rightQueue = LDR( root->right );
            while (!rightQueue.empty()){
                res.push(rightQueue.front());
                rightQueue.pop();
            }
        }
        return res;
    }
    bool isValidBST(TreeNode* root) {
        bool res = true;

        queue<int>  queue = LDR(root);
        int lastVal = queue.front();
        queue.pop();
        while (!queue.empty()){
            if(queue.front() > lastVal){
                lastVal = queue.front();
            }else{
                res = false;
                break;
            }
            queue.pop();
        }
        return res;
    }
};
//Time Complexity: O(NlogN)
//Space Complexity: O(N)

class Solution_2 {
public:
    void LDR(TreeNode* root, queue<int> &queue){
        if(root != nullptr){
            LDR( root->left, queue);
            queue.push(root->val);
            LDR( root->right, queue );
        }
    }
    bool isValidBST(TreeNode* root) {
        bool res = true;
        queue<int> queue;
        LDR(root, queue);
        int lastVal = queue.front();
        queue.pop();
        while (!queue.empty()){
            if(queue.front() > lastVal){
                lastVal = queue.front();
            }else{
                res = false;
                break;
            }
            queue.pop();
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)