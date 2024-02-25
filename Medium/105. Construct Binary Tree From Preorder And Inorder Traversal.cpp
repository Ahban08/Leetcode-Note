class Solution {
public:
    TreeNode* DFS(vector<int>& preorder, vector<int>& inorder, int index, int start, int end) {
        if(start > end){
            return nullptr;
        }
        
        int rootVal = preorder[index];
        int mid;
        TreeNode *res = new TreeNode(rootVal);
        for( mid = start; mid <  inorder.size(); mid++){
            if(inorder[mid] == rootVal){
                // cout<<mid<<"\n";
                break;
            }
        }
        // cout<<"rootVal"<<rootVal<<" index+1:"<<index+1<<" start: "<<start<<" mid-1:"<<mid-1<<"\n";
        res->left = DFS(preorder, inorder, index+1, start, mid-1);
        // cout<<"rootVal"<<rootVal<<" index+(mid-start):"<<index+(mid-start)+1<<" mid+1:"<<mid+1<<" end:"<<end<<"\n";
        res->right = DFS(preorder, inorder, index+(mid-start)+1, mid+1, end);
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *res = DFS(preorder, inorder, 0, 0, inorder.size()-1);
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)