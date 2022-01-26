// Problem Link: https:  leetcode.com/problems/all-elements-in-two-binary-search-trees/

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

// brute force:
// TC->O(NlogN), SC->O(H+H), H=>recursion tree height or height of the BST
class Solution {
public:
    vector<int> res;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);
        sort(res.begin(),res.end());
        return res;
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};

    
//Optimal: TC->O(N), SC->O(N+N) , N=> No. of elements
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        vector<int> res=merge(v1,v2);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> merge(vector<int>& v1, vector<int>& v2){
        int i=0,j=0,n=v1.size(),m=v2.size();
        vector<int> res;
        while(i<n && j<m){
            if(v1[i]<v2[j]) res.push_back(v1[i++]);
            else res.push_back(v2[j++]);
        }
        while(i<n) res.push_back(v1[i++]);
        while(j<m) res.push_back(v2[j++]);
        
        return res;
    }
};    


// Most Optimal: TC-> O(N), SC->O(H+H) , H->height of the BST
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> st1,st2;
        while(root1 or root2 or !st1.empty() or !st2.empty()){
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
            while(root2){
                st2.push(root2);
                root2=root2->left;
            }
            if(st1.empty() or (!st2.empty() && st2.top()->val<st1.top()->val)){
                root2=st2.top();
                st2.pop();
                res.push_back(root2->val);
                root2=root2->right;
            }
            else{
                root1=st1.top();
                st1.pop();
                res.push_back(root1->val);
                root1=root1->right;
            }
        }
        return res;
    }
};
