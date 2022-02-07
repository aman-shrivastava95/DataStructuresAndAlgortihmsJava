#include<bits/stdc++.h>
using namespace std ;

bool f(int ind, int target, vector<int> &arr,vector<vector<int>> dp){
    //base cases
    if(target == 0) return true ;
    if(ind==0) return arr[ind]==target ;
    
    if(dp[ind][target]!=-1) return dp[ind][target] ;
    //explore all possibilites
    bool not_take = f(ind -1,target,arr,dp) ;
    //we can take only if the current index value is less than the target
    bool take = false ;
    if(arr[ind]<=target) take = f(ind -1,target-arr[ind],arr,dp) ;
    
    //return result of both the possibility
    return dp[ind][target] = take || not_take ;
}

//memoization
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<int>(k+1,-1)) ;
    return f(n-1,k,arr,dp) ;
}

//tabulation
bool subsetSumK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1,0)) ;
    //base case
    for(int i=0;i<n;i++){
        dp[i][0] = true ;
    }
    if(arr[0]<=k) dp[0][arr[0]] = true ;
    
    for(int ind = 1;ind<n;ind++){
        for(int target = 1;target<=k;target++){
            bool not_take  =dp[ind-1][target] ;
            bool take = false ;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]] ;
            dp[ind][target] = take || not_take ;
        }
    }
    return dp[n-1][k] ;
}

//tabulation space optimized
bool subsetSumK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,0),curr(k+1,0) ;
    prev[0] = curr[0] = true  ;
    if(arr[0]<=k)prev[arr[0]] = true ;
    for(int ind = 1;ind<n;ind++){
        for(int target = 1;target<=k;target++){
            bool not_take  =prev[target] ;
            bool take = false ;
            if(arr[ind]<=target) take = prev[target-arr[ind]] ;
            curr[target] = take || not_take ;
        }
        prev = curr ;
    }
    return prev[k] ;
}