//Recursive
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        if(res != false){
            if(p == nullptr || q == nullptr){
                if(p != nullptr || q != nullptr){
                    res= false;
                }
                return res;
            }
            if(p->val == q->val){
                if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)){
                    res = false;
                }
            }else{
                res = false;
            }
        }
        return res;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res =false;
        if(subRoot == nullptr){
            res = true;
            return res;
        }
        if(root!=nullptr){
            if(root->val == subRoot->val){
                if(isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right)){
                    res = true;
                    return res;
                }
            }
            res = (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }
        return res;
    }
};
//N 為root node數量，M 為subRoot node數量
//Time Complexity: O(MN)
//Space Complexity: O(N+M)