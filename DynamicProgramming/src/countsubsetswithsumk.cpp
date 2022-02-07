#include<bits/stdc++.h>
using namespace std ;

int f(int ind, int sum, vector<int> &nums,vector<vector<int>> &dp){
    if(sum==0) return 1 ;
    if(ind==0) return nums[0] == sum ;

    if(dp[ind][sum]!=-1) return dp[ind][sum] ;
   
    int not_take = f(ind-1,sum,nums,dp) ;
    int take = 0 ;
    if(nums[ind]<=sum) take = f(ind-1, sum-nums[ind],nums,dp) ;
    
    return dp[ind][sum] = take + not_take ;
}
//memoization
int countSubsetWithSumK(vector<int> &nums,int k){
    int n =  nums.size()  ;
    vector<vector<int>> dp(n,vector<int>(k+1,-1)) ;

    f(n-1, k, nums, dp) ;

}

//tabulation
int countSubsetsWithSumKTab(vector<int> &nums, int k){
    int n = nums.size() ;
    vector<vector<int>> dp(n, vector<int>(k+1, 0)) ;
    
    //base cases ;
    for(int i = 0;i< n;i++)
        dp[i][0] = 1 ;
    if(nums[0]<=k)dp[0][nums[0]] = 1 ;

    for(int ind=1;ind<n;ind++){
        for(int sum = 0;sum<=k;sum++){
            int not_take = dp[ind-1][sum];
            int take = 0 ;
            if(nums[ind]<=sum) take = dp[ind-1][sum-nums[ind]] ;
            
            dp[ind][sum] = take + not_take ;
        }
    }
    return dp[n-1][k] ;   
}
//space optimized
int countSubsetsWithSumKTabSO(vector<int> &nums, int k){
    int n = nums.size() ;
    vector<int> prev(k+1, 0),cur(k+1) ;
    
    //base cases ;
    prev[0] = cur[0] = 1 ;
    if(nums[0]<=k)prev[nums[0]] = 1 ;

    for(int ind=1;ind<n;ind++){
        for(int sum = 0;sum<=k;sum++){
            int not_take = prev[sum];
            int take = 0 ;
            if(nums[ind]<=sum) take = prev[sum-nums[ind]] ;
            
            cur[sum] = take + not_take ;
        }
    }
    return prev[k] ;   
}