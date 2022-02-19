#include<bits/stdc++.h>
using namespace std ;
//this is same as unbounded knapsack, try to formulate the question as, if I have different length piece
//how can I make rod of length N from those pieces and while doing so maximimze the cost.

int f(int ind,int N, vector<int> &price,vector<vector<int>> &dp){
    if(ind==0) return N*price[0] ;//as first index siginifies rod of length 1
    if(dp[ind][N]!=-1) return dp[ind][N] ;
    int not_take = f(ind-1,N,price,dp) ;
    int rodlength = ind+1 ;
    int take = INT_MIN ;
    if(rodlength <= N)
        take  = price[ind] + f(ind,N-rodlength,price,dp) ;
    
    return dp[ind][N]=max(take, not_take) ;

}

//memoization.
int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1,-1)) ;
    return f(n-1,n,price,dp) ;
}

//tabulation
int cutRodTab(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1,0)) ;
    //base case
    for(int N=0 ;N<n;N++) dp[0][N] = N * price[0] ;

    //fill all other cases.
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int not_take = dp[ind-1][N] ; 
            int rodlength = ind+1 ;
            int take = INT_MIN ;
            if(rodlength <= N)
                take  = price[ind] + dp[ind][N-rodlength] ;  
            
            dp[ind][N]=max(take, not_take) ;
        }
    }
    return dp[n-1][n] ;
}
//this can be further optimized in 2 array(prev, curr) and 1 array respectively. see unbounded knapsack. 