#include<bits/stdc++.h>
using namespace std ;

int f(int ind, int w, vector<int> &wt, vector<int> & val,vector<vector<int>> &dp){

    //base case
    if(ind==0){
        if(wt[0]<=w) return val[0] ;
        else return 0 ;
    }
    if(dp[ind][w]!=-1) return dp[ind][w] ;
    int not_take = f(ind-1,w,wt,val,dp) ;
    int take = INT_MIN ;
    if(wt[ind] <= w)
        take  = val[ind] + f(ind-1,w-wt[ind],wt,val,dp) ;

    return dp[ind][w] = max(not_take, take) ;

}
//normal memoization
int knapsack(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
    return f(n-1,maxWeight,wt, val,dp) ;
}
//tabulation
int knapsackTab(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0)) ;
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) dp[0][W] = val[0] ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = 0;W<=maxWeight;W++){
            int not_take = dp[ind-1][W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + dp[ind-1][W-wt[ind]];

            dp[ind][W] = max(not_take, take) ;
        }
    }
    dp[n-1][maxWeight] ;
}
//tabulation spaceOptimized
int knapsackTabSO(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0) ;
    
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) prev[W] = val[0] ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = 0;W<=maxWeight;W++){
            int not_take = prev[W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + prev[W-wt[ind]];

            cur[W] = max(not_take, take) ;
        }
        prev = cur ;
    }
    return prev[maxWeight] ;
}

//tabulation spaceOptimized to single array.
int knapsackTabSO(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<int> prev(maxWeight+1,0);
    
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) prev[W] = val[0] ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = maxWeight;W>=maxWeight;W--){//going from right to left.
            int not_take = prev[W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + prev[W-wt[ind]];

            prev[W] = max(not_take, take) ;
        }
    }
    return prev[maxWeight] ;
}