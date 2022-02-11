#include<bits/stdc++.h>
using namespace std ;

int f(int ind, int T, vector<int> &nums,vector<vector<int>> &dp){
    if(ind==0){
        if(T%nums[0]==0) return T/ nums[0] ;
        return 1e9 ;
    }
    if(dp[ind][T]!=-1) return dp[ind][T] ;
    int not_take = 0 + f(ind-1,T, nums,dp) ;
    int take = INT_MAX ;
    if(nums[ind] <=T){
        take = 1 + f(ind, T-nums[ind],nums,dp) ; //not decrementing the ind, as we have infinite supply of coins
    }
    return dp[ind][T]  = min(take, not_take) ;
}

//memoization
int minCoins(vector<int> &num, int target){
    int n = num.size() ;
    vector<vector<int>> dp(n, vector<int>(target + 1,-1)) ;
    int ans  = f(n-1,target,num,dp) ;
    if(ans >=1e9) return -1 ;
    else return ans ;
}

//tabulation
int minCoinsTab(vector<int> &nums, int target){
    int n = nums.size() ;
    vector<vector<int>> dp(n, vector<int>(target + 1,0)) ;
    //base case
    for(int T = 0; T<=target;T++){
        if(T% nums[0]==0) dp[0][T] = T/nums[0] ;
        else dp[0][T] = 1e9 ;
    }
    for(int ind = 1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int not_take = 0 + dp[ind-1][T];            
            int take = INT_MAX ;
            if(nums[ind] <=T){
                take = 1 + dp[ind][T-nums[ind]] ; //not decrementing the ind, as we have infinite supply of coins
            }
            dp[ind][T] = min(take, not_take) ;
        }
    }
    int ans  =  dp[n-1][target] ;
    if(ans >=1e9) return -1 ;
    else return ans ;
}

//tabulation space optimized
int minCoinsTabSO(vector<int> &nums, int target){
    int n = nums.size() ;
    vector<int> prev(target+1,0),cur(target+1,0) ;
    //base case
    for(int T = 0; T<=target;T++){
        if(T% nums[0]==0) prev[T] = T/nums[0] ;
        else prev[T] = 1e9 ;
    }
    for(int ind = 1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int not_take = 0 + prev[T];            
            int take = INT_MAX ;
            if(nums[ind] <=T){
                take = 1 + cur[T-nums[ind]] ; //not decrementing the ind, as we have infinite supply of coins
            }
            cur[T] = min(take, not_take) ;
        }
        prev=cur ;
    }
    int ans  =  prev[target] ;
    if(ans >=1e9) return -1 ;
    else return ans ;
}