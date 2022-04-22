#include<bits/stdc++.h>
using namespace std ;

//the idea is to make the subproblems independent, in order to so, we will fix each balloon to be burst at last
//and then the left of that balloon and right of that balloon will be indpendent subproblems.

class Solution {
    //memoization
    int f(int i, int j, vector<int> &nums,vector<vector<int>> &dp){
        if(i>j) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        int maxi = INT_MIN ;
        for(int ind=i;ind<=j;ind++){
            //let the balloon at ind be the last balloon to be burst
            int coins = nums[i-1] * nums[ind] * nums[j+1] +
                        f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp) ;
            maxi = max(maxi,coins) ;
        }
        return dp[i][j] = maxi ;
    }
public:
    //tabulation
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1) ;
        nums.push_back(1) ;
        int n = nums.size() ;
        vector<vector<int>> dp(n+2,vector<int>(n+2,0)) ;
        for(int i= n;i>=1;i--){
            for(int j=1;j<=n-2;j++){
                if(i>j) continue;
                int maxi = INT_MIN ;
                for(int ind=i;ind<=j;ind++){
                    
                    int coins = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j] ;
                    maxi = max(maxi,coins) ;
                }
                 dp[i][j] = maxi ;
            }
        }
        return dp[1][nums.size()-2] ;
        //return f(1,nums.size()-2,nums) ;
    }
};