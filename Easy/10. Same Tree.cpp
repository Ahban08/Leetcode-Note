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
};
//Time Complexity: O(N)
//Space Complexity: O(logN)