//recoverTree

// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.
// Example1
// Input: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// Output: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2


// Example 2:

// Input: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// Output: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};


class Solution {
public:
    TreeNode* p1;
    TreeNode* p2;
    TreeNode* prev;
    void recoverTree(TreeNode* root) {
        dfs(root);
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left); 
        if(prev != NULL && prev->val > root->val){
            if(p1 == NULL) p1 = prev;
            p2 = root;
        }
        prev = root;
        dfs(root->right);
    }
};