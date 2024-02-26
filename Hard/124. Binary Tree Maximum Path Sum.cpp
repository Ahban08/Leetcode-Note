class Solution {
public:
    int maxPath(TreeNode* root, int &maxSum) {
        int res = 0;

        if(root != nullptr){
            int left = maxPath(root->left, maxSum);
            int right = maxPath(root->right, maxSum);
            maxSum = max(maxSum, (left>0? left:0) + (right>0? right:0) + root->val);
            res = root->val + max((left>0? left:0), (right>0? right:0));
        }
        return res;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        return max(maxSum, maxPath(root, maxSum));
    }
};
//Time Complexity: O(N)
//Space Complexity: O(h) h為樹高，平均為logN