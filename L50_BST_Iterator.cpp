//Problem Link: https://leetcode.com/problems/binary-search-tree-iterator/

#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//-----------------------------------------------------------------------------------------------------
//TC-> O(1), SC->O(N) Solution using a vector
class BSTIterator {
    TreeNode* root;
    vector<int> v;
    int i=0;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->root=root;
        inorder(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<v.size();
    }
};
//------------------------------------------------------------------------------------------------------
//TC-> O(1), SC->O(H) H is the height of the binary tree
//Using Stack
class BSTIterator {
    stack<TreeNode*> st;
    void insertStack(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        insertStack(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(node->right)
            insertStack(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */