//Problem Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

//Solution:---------------------------------------------------------------------------------------

class BSTIterator{
    stack<TreeNode*> st;
    bool isReverse;
    void pushAll(TreeNode* root){
        while(root){
            if(isReverse){
                st.push(root);
                root=root->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
    }
public:
    BSTIterator(TreeNode* root,bool isReverse){
        this->isReverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* tmpNode=st.top();
        st.pop();
        if(isReverse) pushAll(tmpNode->left);
        else pushAll(tmpNode->right);
        return tmpNode->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){ 
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};
//TC-> O(N), SC->O(logN) or O(H) -> H is the maximum height of the tree
//It's a Snapchat Onsite Interview Qs
