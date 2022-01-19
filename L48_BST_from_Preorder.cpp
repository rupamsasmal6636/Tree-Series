//Problem link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Solution:
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildTree(preorder,i,INT_MAX);
    }
    TreeNode* buildTree(vector<int>& preorder,int& i,int bound){
        if(i==preorder.size() or preorder[i]>bound) return nullptr;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=buildTree(preorder,i,root->val);
        root->right=buildTree(preorder,i,bound);
        return root;
    }
};