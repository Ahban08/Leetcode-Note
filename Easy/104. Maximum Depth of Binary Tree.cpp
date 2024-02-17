class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res, leftDepth, rightDepth;

        if(root == nullptr){
            return 0;
        }
        if(root->left!=nullptr){
            leftDepth = maxDepth(root->left);
        }else{
            leftDepth = 0;
        }
        if(root->right!=nullptr){
            rightDepth = maxDepth(root->right);
        }else{
            rightDepth = 0;
        }
        return max(leftDepth, rightDepth)+1;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(logN)

class Solution_1 {
public:
    int maxDepth(TreeNode* root) {
        int res, leftDepth, rightDepth;

        if(root == nullptr)
            return 0;
        
        leftDepth = maxDepth(root->left);
        rightDepth = maxDepth(root->right);
        res = max(leftDepth, rightDepth)+1;
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(logN)