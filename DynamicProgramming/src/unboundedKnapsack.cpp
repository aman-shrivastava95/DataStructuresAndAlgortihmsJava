#include<bits/stdc++.h>
using namespace std ;

int f(int ind, int w, vector<int> &wt, vector<int> & val,vector<vector<int>> &dp){

    //base case
    if(ind==0){
            return ((int)w/wt[0])* (val[0]) ;
    }
    if(dp[ind][w]!=-1) return dp[ind][w] ;
    int not_take = f(ind-1,w,wt,val,dp) ;
    int take = INT_MIN ;
    if(wt[ind] <= w)
        take  = val[ind] + f(ind,w-wt[ind],wt,val,dp) ;

    return dp[ind][w] = max(not_take, take) ;

}
//normal memoization
int unboundedknapsack(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
    return f(n-1,maxWeight,wt, val,dp) ;
}
//tabulation
int unboundedknapsackTab(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0)) ;
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) dp[0][W] = ((int)W/wt[0])* (val[0]) ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = 0;W<=maxWeight;W++){
            int not_take = dp[ind-1][W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + dp[ind][W-wt[ind]];

            dp[ind][W] = max(not_take, take) ;
        }
    }
    dp[n-1][maxWeight] ;
}
//tabulation spaceOptimized
int unboundedknapsackTabSO(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
    vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0) ;
    
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) prev[W] = ((int)W/wt[0])* (val[0]) ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = 0;W<=maxWeight;W++){
            int not_take = prev[W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + cur[W-wt[ind]];

            cur[W] = max(not_take, take) ;
        }
        prev = cur ;
    }
    return prev[maxWeight] ;
}

//tabulation spaceOptimized to single array. draw this to undersatnd this more, draw two rows  and see dependencies.
int unboundedknapsackTabSOMore(vector<int> &wt,vector<int> &val,int n, int maxWeight){
    
 vector<int> prev(maxWeight+1,0);
    
    //base case
    for(int W = wt[0] ; W<=maxWeight;W++) prev[W] = ((int)W/wt[0])* (val[0]) ;

    //fill the other states
    for(int ind=1; ind<n;ind++){
        for(int W = 0;W<=maxWeight;W++){
            int not_take = prev[W];
            int take = INT_MIN ;
            if(wt[ind] <= W)
                take  = val[ind] + prev[W-wt[ind]];

            prev[W] = max(not_take, take) ;
        }
    }
    return prev[maxWeight] ;
}