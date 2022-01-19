// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* inorderSuccessor(TreeNode* root,TreeNode* p){
        TreeNode* successor=nullptr;
        while(root){
            if(root->val <= p->val){
                root=root->right;
            }
            else{
                successor=root;
                root=root->left;
            }
        }
        return successor;
    }
};
// TC-> O(H), SC->O(1)