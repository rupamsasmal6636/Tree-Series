//Problem Link: https://leetcode.com/problems/recover-binary-search-tree/

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

//Solution1:---------------------------------------------------------------------------------------
//Brute force: taking a vector, insert value according inorder, sort, now check the difference. TC-> O(NlogN + 2N), SC-> O(N)
class Solution {
public:
    vector<int> v;
    int i=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void check(TreeNode* root){
        if(!root) return;
        check(root->left);
        if(v[i]!=root->val) swap(v[i],root->val);
        i++;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        check(root);
    }
};

//Solution2:---------------------------------------------------------------------------------------
//Optimal: TC-> O(N), SC->O(1)[for morris traversal] [I'm using DFS]
//Approch: Simple inorder & check the root and prev element. If root<prev it's e violation.
// now check the 2 violation and swap them.
class Solution {
    TreeNode* first, *last, *prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                last=root; 
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};