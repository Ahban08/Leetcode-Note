//Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        int small = min(p->val, q->val);
        int big = max(p->val, q->val);

        if(root != nullptr){
            int value = root->val;
            if( small <= value && big >= value){
                return res;
            }else if(value < small){
                res = lowestCommonAncestor(root->right, p, q);
            }else{
                res = lowestCommonAncestor(root->left, p, q);
            }
        }
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(logN)