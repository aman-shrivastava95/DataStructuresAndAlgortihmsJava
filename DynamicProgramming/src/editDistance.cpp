#include<bits/stdc++.h>
using namespace std ;


int f(int i, int j, string s1, string s2,vector<vector<int>> &dp){
    if(i<0) return j+1 ;
    if(j<0) return i+1 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s1[i]==s2[j])return dp[i][j] = f(i-1,j-1,s1,s2,dp) ;
    return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp))) ; 
}
//memoization
int editDistance(string str1,string str2){
    int n  = str1.size() ;
    int m  = str2.size() ;
    vector<vector<int>> dp(n,vector<int>(m, -1)) ;
    return f(n-1,m-1,str1,str2,dp) ;
}

//shifing to 1 based indexing for base case of ==0 ;
int f(int i, int j, string s1, string s2,vector<vector<int>> &dp){
    if(i==0) return j ;
    if(j==0) return i ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s1[i-1]==s2[j-1])return dp[i][j] = f(i-1,j-1,s1,s2,dp) ;
    return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp))) ; 
}
//memoization 1 based
int editDistance(string str1,string str2){
    int n  = str1.size() ;
    int m  = str2.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1, -1)) ;
    return f(n,m,str1,str2,dp) ;
}

//tabulation with shifted indexes
int editDistanceTab(string s1, string s2){
    int n  = s1.size() ;
    int m  = s2.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1, 0)) ;
    
    for(int i=0;i<=n;i++) dp[i][0] = i ;
    for(int j=0;j<=m;j++) dp[0][j] = j ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])  dp[i][j] = dp[i-1][j-1] ;
            else dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) ;
        }
    }
    return dp[n][m] ;
}   

 int editDistanceTabSO(string s1, string s2){
    int n  = s1.size() ;
    int m  = s2.size() ;
    vector<int> prev(m+1,0),cur(m+1,0) ;

    for(int j=0;j<=m;j++) prev[j] =  j ;

    for(int i=1;i<=n;i++){
        cur[0] = i ;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])  cur[j] = prev[j-1] ;
            else cur[j] = 1 + min(prev[j],min(cur[j-1],prev[j-1])) ;
        }
        prev = cur ;
    }
    return prev[m] ;
}  