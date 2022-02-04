#include<bits/stdc++.h>
using namespace std ;

int f(int i, int j, vector<vector<int>> &triangle, int n,vector<vector<int>> &dp){
    //base case: reached last row
    if(i==n-1)
        return triangle[i][j] ;
    //check in dp array
    if(dp[i][j]!=-1) return dp[i][j] ;

    //explore all options
    int down = triangle[i][j] +  f(i+1,j, triangle,n,dp) ;
    int diag = triangle[i][j] +  f(i+1,j+1, triangle,n,dp) ;

    //memoize results and return
    return dp[i][j] = min(down,diag) ;
}
//memoization
int minimumPathSumTriangle(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,-1)) ;
    return f(0,0,triangle,n,dp) ;
}

//tabulation
int minimumPathSumTriangleTab(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n,0)) ;
    
    //base case ,fill the last row
    for(int j=0 ; j < n-1; j++){
        dp[n-1][0] = triangle[n-1][j] ;
    }
    //fill all other cells bottom to top
    for(int i=n-2; i>=0; i--){
        for(int j=i ; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j] ;
            int diag = triangle[i][j] + dp[i+1][j+1] ;
            dp[i][j] = min(down,diag) ;
        }
    }
    return dp[0][0] ;
}

//space optimized, as we only need 2 rows.
int minimumPathSumTriangleTabSO(vector<vector<int>> &triangle, int n){
    vector<int> front(n,0) ;
    
    //base case ,fill the last row
    for(int j=0 ; j < n-1; j++){
        front[j] = triangle[n-1][j] ;
    }
    //fill all other cells bottom to top
    for(int i=n-2; i>=0; i--){
        vector<int> curr(n,0) ;
        for(int j=i ; j>=0; j--){
            int down = triangle[i][j] + front[j] ;
            int diag = triangle[i][j] + front[j+1] ;
            curr[j] = min(down,diag) ;
        }
        front = curr ;
    }
    return front[0] ;
}