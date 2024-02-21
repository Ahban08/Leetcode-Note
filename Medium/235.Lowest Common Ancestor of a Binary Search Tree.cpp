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

class Solution_1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;

        int value = root->val;
        if( p->val < value && q->val < value){
            res = lowestCommonAncestor(root->left, p, q);
        }else if( p->val > value && q->val > value){
            res = lowestCommonAncestor(root->right, p, q);
        }
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(logN)

//Interactive
class Solution_2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        stack<TreeNode*> nodeStack;

        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int value = node->val;
            if( p->val < value && q->val < value){
                nodeStack.push(node->left);
            }else if( p->val > value && q->val > value){
                nodeStack.push(node->right);
            }else{
                res = node;
                break;
            }
        }
        return res;
    }
};
//Time Complexity: O(logN)
//Space Complexity: O(1)