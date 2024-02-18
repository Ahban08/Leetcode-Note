//Recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr){
            TreeNode *temp =invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = temp;
        }
        return root;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(logN)

//Interative
class Solution_2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        
        if(root != nullptr){
            nodeStack.push(root);
        }

        while(!nodeStack.empty()){
            TreeNode *top =nodeStack.top();
            TreeNode *tmp = top->left;
            top->left = top->right;
            top->right = tmp;
            nodeStack.pop();
            if(top->left!=nullptr)
                nodeStack.push(top->left);
            if(top->right!=nullptr)
                nodeStack.push(top->right);
        }
        return root;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(logN)