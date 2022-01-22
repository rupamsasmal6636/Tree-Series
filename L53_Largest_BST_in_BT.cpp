//Problem Link: https://practice.geeksforgeeks.org/problems/largest-bst/1/

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//Solution:---------------------------------------------------------------------------------------

//Approach: buttom up.. you know the leaf nodes are already a bst. now traverse postorder, and check
//IF( left->maxVal < root->val < right->minVal )=> it's true then it's a BST
//Then, 1+ left->count+ right->count

class NodeVal{
public:
    int count,minVal,maxVal;
    NodeVal(int count,int minVal,int maxVal){
        this->count=count, this->minVal=minVal,this->maxVal=maxVal;
    }
};
class Solution{
    NodeVal postOrder(Node* root){
        if(root==NULL){
            return NodeVal(0,INT_MAX,INT_MIN);
        }
        NodeVal l=postOrder(root->left);
        NodeVal r=postOrder(root->right);
        if(l.maxVal < root->data && root->data < r.minVal)
            return NodeVal(1+l.count+r.count,min(l.minVal,root->data),max(r.maxVal,root->data));
        return NodeVal(max(l.count,r.count),INT_MIN,INT_MAX);
    }
public:
    int largestBst(Node *root)
    {
        return postOrder(root).count; 
    }
    
};

//TC->O(N), SC->O(H) or O(1)