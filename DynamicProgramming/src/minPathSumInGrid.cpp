#include<bits/stdc++.h>
using namespace std ;

//always declare modulo globally
int mod = (int)(1e9 + 7) ;

int f(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
    // base cases
   if(i==0 && j==0) return grid[i][j] ;
   if(i<0 || j<0) return INT_MAX;//since we are trying to minimize

   //check in dp array
   if(dp[i][j]!=-1) return dp[i][j] ;

   int up =  grid[i][j] + f(i-1,j, grid,dp) ;
   int left = grid[i][j] + f(i,j-1,grid,dp) ;
   return dp[i][j]=min(up,left) ;
}
int minPathSum(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> dp(n, vector<int>(m,-1)) ;
    return f(n-1,m-1,grid,dp) ;
}

//tabulation
int minPathSumTab(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> dp(n,vector<int>(m,0)) ;
    for(int i = 0;i < n; i++){
        for (int j = 0; j < m; j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[i][0] ;
            else{
                int up = grid[i][j] ;
                if(i>0) up+=dp[i-1][j];
                else up+=1e9 ;//since we are minimizing
                int left = grid[i][j] ;
                if(j>0) left+=dp[i][j-1] ;
                else left+=1e9;
                dp[i][j] =  min(left, up) ;
            }
        }
    }
    return dp[n-1][m-1] ;
}


//tabulation space optimized
int minPathSumTabSO(int n, int m, vector<vector<int>> &grid){
    vector<int> prev(m,0) ;
    for(int i = 0;i < n; i++){
        vector<int> curr(m,0) ;
        for (int j = 0; j < m; j++)
        {
            if(i==0 && j==0) curr[j]=grid[i][0] ;
            else{
                int up = grid[i][j] ;
                if(i>0) up+=prev[j];
                else up+=1e9 ;//since we are minimizing
                int left = grid[i][j] ;
                if(j>0) left+=curr[j-1] ;
                else left+=1e9;
                curr[j] =  min(left, up) ;
            }
        }
        prev = curr ;
    }
    return prev[m-1] ;
}
