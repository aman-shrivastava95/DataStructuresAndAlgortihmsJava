#include<bits/stdc++.h>
using namespace std ;

int f(int i, int j,int m, int n,vector<vector<int>> &dp){
    //base cases
    if(i==0 && j==0)
        return 1 ;
    if(i<0 || j <0)
        return 0 ;
    
    //check if it is present in the dp array
    if(dp[i][j]!=-1)return dp[i][j] ;
    
    //explore the options
    int up = f(i-1,j,m,n,dp) ;
    int left = f(i,j-1,m,n,dp) ;

    //memoize the ansewr and return 
    return dp[i][j] = up+left ;
}
//memoizatoin method
int uniquepaths(int m, int n){
    //f(m-1,n-1) represents ways to reach from (0,0) to (m-1,n-1)
    vector<vector<int>> dp(m, vector<int>(n,-1)) ;
    return f(m-1,n-1,m,n,dp) ;
}

//tabulation
int uniquePathsTab(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n,0)) ;

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
        {
            if(i==0 && j==0){
                dp[i][j]=1 ;
            }
            else{
                int up=0,left = 0 ;
            if(i-1 > 0)
                up = dp[i-1][j];
            if(j-1 > 0)
                left = dp[i][j-1] ;
            dp[i][j] = up+left ;
            } 
        }
    }    
    return dp[m-1][n-1] ;
}
//space optimized tabulation
int uniquePathsSpaceOptimized(int m, int n){
    
    vector<int> prev(n,0) ;

    for(int i = 0; i < m; i++){
        vector<int> curr(n,0) ;
        for (int j = 0; j < n; j++)
        {
            if(i==0 && j==0){
                curr[j]=1 ;
            }
            else{
                int up=0,left = 0 ;
            if(i-1 > 0)
                up = prev[j];
            if(j-1 > 0)
                left = curr[j-1] ;
            curr[j] = up+left ;
            } 
        }
        prev = curr ;
    }    
    return prev[n-1] ;
}