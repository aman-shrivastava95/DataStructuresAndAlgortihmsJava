//you have infinite supply of coins of given denominations, count the total number of ways, to make a given
//target T
#include<bits/stdc++.h>
using namespace std ;


long f(int ind, int T, int* arr,vector<vector<long>> &dp){
    if(ind==0){
        return (T % arr[0] == 0) ;
    }

    if(dp[ind][T] != -1) return dp[ind][T] ;
    int not_take = f(ind-1,T, arr,dp) ;
    int take = 0 ;
    if(arr[ind] <= T) take =  f(ind, T-arr[ind],arr,dp) ;
    return dp[ind][T] = take + not_take ;
}

//memoized
long countWaysToMakeChange(int T, int *denominations,int n){
    vector<vector<long>> dp(n,vector<long>(T+1,-1)) ;
    return f(n-1,T, denominations,dp) ;
}

//tabulated
long countWaysToMakeChangeTab(int T, int *arr,int n){
    vector<vector<long>> dp(n,vector<long>(T+1,0)) ;
    
    //base case ;
    for(int t = 0; t<=T; t++){
        dp[0][t] = (t%arr[0] == 0) ;
    }
    //fill all other cases
    for(int ind=1; ind<n; ind++){
        for(int t=0; t<=T; t++){
            int not_take = dp[ind-1][t] ;
            int take = 0 ;
            if(arr[ind] <= t) take = dp[ind][t-arr[ind]] ;
            dp[ind][t] = take + not_take ;
        }
    }
    return dp[n-1][T] ;
}
//space optimized tabulation
long countWaysToMakeChangeTabSO(int T, int *arr,int n){
    vector<long> prev(T+1,0),curr(T+1,0) ;
    
    //base case ;
    for(int t = 0; t<=T; t++){
        prev[t] = (t%arr[0] == 0) ;
    }
    //fill all other cases
    for(int ind=1; ind<n; ind++){
        for(int t=0; t<=T; t++){
            int not_take = prev[T] ;
            int take = 0 ;
            if(arr[ind] <= t) take = curr[t-arr[ind]] ;
            curr[t] = take + not_take ;
        }
        prev = curr ;
    }
    return prev[T] ;
}