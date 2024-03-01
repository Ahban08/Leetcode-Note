/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Not Pass
class Codec {
public:
    void levelOrderTraversal(TreeNode* root, vector<string> &BTval,int index){
        if(root== nullptr)
            return;
        if(BTval.size() < index){
            BTval.resize(index+1);
        }
        // cout<<"index"<<index<<"\n";
        // cout<<"BTval size:"<<BTval.size();
        BTval[index-1] = to_string(root->val);
        // cout<<"check";
        levelOrderTraversal(root->left, BTval, index*2);
        levelOrderTraversal(root->right, BTval, index*2+1);
    }
    TreeNode* buildTreeNode(vector<string> &BTval, int index){
        if(index > BTval.size() || BTval[index-1] == ""){
            return nullptr;
        }
        // cout<<"index-1:"<<index-1<<" BTval:"<<BTval[index-1]<<"\n";
        int val =std::stoi(BTval[index-1]);
        TreeNode *root = new TreeNode(val);
        root->left = buildTreeNode(BTval, index*2);
        root->right = buildTreeNode(BTval, index*2+1);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        vector<string> BTval;
        levelOrderTraversal( root, BTval, 1);

        for(int i = 0; i<BTval.size(); i++){
            res += BTval[i];
            res +=",";
        }
        // cout<<res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = data.find_first_of(","), from = 0, length = pos;
        int count = 0;
        vector<string> BTval;
        TreeNode *res;

        while (pos != std::string::npos)
        {
            if( pos != from){
                if(BTval.size() < count+1){
                    BTval.resize(count+1);
                }
                length = pos-from;
                BTval[count]=data.substr(from, length);
                // cout<<"Input BTval "<<count<<":"<<BTval[count]<<" length:"<<length<<"\n";
            }
            from = pos+1;
            pos = data.find_first_of(",",from);
            count++;
        }
        res = buildTreeNode(BTval, 1);
        return res;
    }
};

// Result: Memory Limit Exceeded
// 代表不能選擇建完滿二元樹的node空間數，會超過空間限制

//Not Pass
class Codec_1 {
public:
    string Preorder(TreeNode* root, string res){
        if(root== nullptr)
            return res + "#,";
        res += to_string(root->val);
        res += ",";
        res = Preorder(root->left, res);
        res = Preorder(root->right, res);
        return res;
    }
    string Inorder(TreeNode* root, string res){
        if(root== nullptr)
            return res + "#,";
        res = Inorder(root->left, res);
        res += to_string(root->val);
        res += ",";
        res = Inorder(root->right, res);
        return res;
    }
    TreeNode* DFS(string preorder, string inorder) {
        size_t preorderPos = preorder.find_first_of(",");
        string rootVal = preorder.substr(0, preorderPos);
        if( rootVal == "#"){
            return nullptr;
            //代表是null;
        }
        
        size_t Lastpos = 0;
        string leftInorder;
        string rightInorder;
        // cout<<rootVal<<"\n";
        TreeNode *res = new TreeNode(stoi(rootVal));
        for( size_t pos = inorder.find_first_of(","); pos <  inorder.length(); pos = inorder.find_first_of(",", pos+1)){
            string val = inorder.substr(Lastpos, pos-Lastpos);
            // cout<<"val"<<val<<"\n";
            if(val == rootVal){
                leftInorder = inorder.substr(0, Lastpos);
                rightInorder = inorder.substr(pos+1);
                // cout<<"Lastpos"<<Lastpos<<" pos"<<pos<<"\n";
                break;
            }
            Lastpos =  pos+1;
        }
        string leftPreorder = preorder.substr(preorderPos+1, Lastpos);
        string rightPreorder = preorder.substr(preorderPos+1+Lastpos) ;
        // cout<<"leftPreorder:"<<leftPreorder<<"rightPreorder:"<<rightPreorder<<"\n"<<"leftInorder:"<<leftInorder<<"rightInorder"<<rightInorder<<"\n";
        res->left = DFS(leftPreorder, leftInorder);
        res->right = DFS(rightPreorder, rightInorder);
        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res ="";
        res = Preorder(root, res);
        res += "/";
        res = Inorder(root, res);
        int count = 0;
        // cout<<res<<"\n";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = data.find_first_of("/");
        string preorder = data.substr(0, pos), inorder = data.substr(pos+1, data.length()-pos-1);
        cout<<"preorder"<<preorder<<"\n"<<"inorder"<<inorder<<"\n";
        TreeNode *res = DFS(preorder, inorder);

        
        return res;
    }
};
// Input存在重複val會出錯，e.g.[3,2,4,3]會出錯

class Codec {
public:
    void Preorder(TreeNode* root, string &res){
        if(root== nullptr){
            res += ",";
            return ;
        }
        res += to_string(root->val);
        res += ",";
        Preorder(root->left, res);
        Preorder(root->right, res);
        // return res;
    }
    TreeNode* DFS(string &preorder) {
        size_t preorderPos = preorder.find_first_of(",");
        // string rootVal = preorder.substr(0, preorderPos);
        if( preorder.substr(0, preorderPos) == ""){
            preorder = preorder.substr(preorderPos+1);
            return nullptr;
            //代表是null;
        }
        
        // cout<<rootVal<<"\n";
        TreeNode *res = new TreeNode(stoi(preorder.substr(0, preorderPos)));
        preorder = preorder.substr(preorderPos+1);
        res->left = DFS(preorder);
        res->right = DFS(preorder);
        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res ="";
        Preorder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *res = DFS(data);        
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(h) h為樹高，平均為logN