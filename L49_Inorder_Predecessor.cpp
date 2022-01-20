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
    TreeNode* inorderPredecessor(TreeNode* root,TreeNode* p){
        TreeNode* predecessor=nullptr;
        while(root){
            if(root->val >= p->val){
                root=root->left;
            }
            else{
                predecessor=root;
                root=root->right;
            }
        }
        return predecessor;
    }
};

// TC-> O(H), SC->O(1)