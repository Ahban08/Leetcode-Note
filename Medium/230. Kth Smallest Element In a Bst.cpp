class Solution {
public:
    void LDR(TreeNode* root, vector<int> &vector, int k){
        if(root != nullptr && vector.size() != k){
            LDR( root->left, vector, k);
            vector.push_back(root->val);
            LDR( root->right, vector, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vector;
        LDR( root, vector, k);
        return vector[k-1];
    }
};
//Time Complexity: O(logN+K)
//Space Complexity: O(N)

class Solution_1 {
public:
    void LDR(TreeNode* root, int &k, int &res){
        if(root != nullptr && k != 0){
            LDR( root->left, k, res);
            k--;
            if(k == 0){
                res = root->val;
                return;
            }
            LDR( root->right, k, res);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        LDR( root, k, res);
        return res;
    }
};
//Time Complexity: O(logN+K)
//Space Complexity: O(1)