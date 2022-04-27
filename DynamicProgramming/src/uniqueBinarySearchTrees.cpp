#include<bits/stdc++.h>
using namespace std ;
//find all the structurally unique BSTs
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    vector<TreeNode*> f(int L, int R,vector<vector<vector<TreeNode*>>> &dp){
        vector<TreeNode*> trees ;
        if(L>R){
            trees.push_back(NULL) ;
            return trees ;
        }
        if(L==R){
            trees.push_back(new TreeNode(L)) ;
            return trees ;
        }
        if(dp[L][R].size() > 0) return dp[L][R] ; 
        //fix every index as root and find left trees and right trees.
        for(int ind = L; ind <=R;ind++){
            vector<TreeNode*> leftTrees = f(L, ind-1,dp) ;
            vector<TreeNode*> rightTrees = f(ind+1,R,dp) ;
            
            for(TreeNode* i:leftTrees){
                for(TreeNode* j: rightTrees){
                    TreeNode* root = new TreeNode(ind) ;
                    root->left = i ;
                    root->right = j ;
                    trees.push_back(root) ;  
                }
            }
        }
         return dp[L][R] = trees ;
    
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n+1,vector<vector<TreeNode*>>(n+1)) ;
        return f(1,n,dp) ;
    }
};