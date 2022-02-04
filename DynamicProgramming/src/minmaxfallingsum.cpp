#include<bits/stdc++.h>
using namespace std ;


int f(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j<0 || j>=matrix[0].size()) return -1e8 ;
    if(i==0) return matrix[0][j] ;

    if(dp[i][j]!=-1) return dp[i][j] ;
    int u = matrix[i][j] + f(i-1,j, matrix,dp) ;
    int ld = matrix[i][j] + f(i-1,j-1, matrix,dp) ;
    int rd = matrix[i][j] + f(i-1,j+1, matrix,dp) ;

    return dp[i][j] = max(u, max(ld,rd)) ;
}

//memoization
int getMaxPathSum(vector<vector<int>> &matrix){
    //we have variable starting points this time.
    int n =  matrix.size() ;
    int m = matrix[0].size() ;
    vector<vector<int>> dp(n, vector<int>(m,-1)) ;
    int maxi = -1e8 ;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi,f(n-1,j,matrix,dp)) ;
    }
    return maxi ;
}


//tabulation
int getMaxPathSumTab(vector<vector<int>> &matrix){
    //we have variable starting points this time.
    int n =  matrix.size() ;
    int m = matrix[0].size() ;
    vector<vector<int>> dp(n, vector<int>(m,0)) ;

    //base case
    for(int j=0;j<m;j++) dp[0][j] = matrix[0][j] ;

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u = matrix[i][j] + dp[i-1][j];
            
            int ld = matrix[i][j] ;
            if(j-1>=0) ld+=dp[i-1][j-1];
            else ld +=-1e8 ;

            int rd = matrix[i][j] ;
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd +=-1e8 ;

            dp[i][j] = max(u, max(ld,rd)) ;
        }
    }

    int maxi = -1e8 ;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi,dp[n-1][j]) ;
    }
    return maxi ;
}

//tabulation space optimized
int getMaxPathSumTabSO(vector<vector<int>> &matrix){
    //we have variable starting points this time.
    int n =  matrix.size() ;
    int m = matrix[0].size() ;
    vector<int> prev(m,0) ;

    //base case
    for(int j=0;j<m;j++) prev[j] = matrix[0][j] ;

    for(int i=1;i<n;i++){
        vector<int> curr(m,0) ;
        for(int j=0;j<m;j++){
            int u = matrix[i][j] + prev[j];
            
            int ld = matrix[i][j] ;
            if(j-1>=0) ld+=prev[j-1];
            else ld +=-1e8 ;

            int rd = matrix[i][j] ;
            if(j+1<m) rd+=prev[j+1];
            else rd +=-1e8 ;

            curr[j] = max(u, max(ld,rd)) ;
        }
        prev = curr ;
    }

    int maxi = -1e8 ;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi,prev[j]) ;
    }
    return maxi ;
}