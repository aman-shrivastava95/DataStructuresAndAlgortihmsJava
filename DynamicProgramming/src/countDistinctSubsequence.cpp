#include<bits/stdc++.h>
using namespace std ;


int f(int i, int j, string s1, string s2,vector<vector<int>> dp){
    if(j < 0) return 1 ;
    if(i < 0) return 0 ;

    if(dp[i][j]!=-1) return dp[i][j] ;
    if(s1[i]==s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp) ; 
    }
    else{
        return dp[i][j] = f(i-1,j,s1,s2,dp) ;
    }
}
//memoization
int coutntDistinctSubsequnces(string s1, string s2){
    int n = s1.size() ;
    int m  = s2.size() ;
    vector<vector<int>> dp(n,vector<int>(m, -1)) ;
    return f(n-1,m-1,s1, s2,dp) ;
}

//tabulation
int numDistinct(string s, string t) {
    int n = s.size() ;
    int m  = t.size() ;
    vector<vector<double>> dp(n+1,vector<double>(m+1, 0)) ;
        
    //base case
    for(int i=0;i<=n;i++)dp[i][0] = 1 ;
    for(int j=1;j<=m;j++)dp[0][j] = 0 ;
        
    //fill all other states
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){//shifting
                 dp[i][j] = dp[i-1][j-1]+ dp[i-1][j]; 
            }
            else{
                 dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return (int)dp[n][m] ;
}

//space optimized tabulation
    int numDistinctSOtab(string s, string t) {
        int n = s.size() ;
        int m  = t.size() ;
        
        vector<double> curr(m+1,0),prev(m+1,0) ;
        prev[0] = curr[0] = 1 ;
        
        //fill all other states
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){//shifting
                     curr[j] = prev[j-1]+ prev[j]; 
                }
                else{
                     curr[j] = prev[j] ;
                }
            }
            prev = curr ;
        }
        return (int)prev[m] ;
    }

    //single array space optimization.
    int numDistinctOneArray(string s, string t) {
        int n = s.size() ;
        int m  = t.size() ;
        
        vector<double>prev(m+1,0) ;
        prev[0] = 1 ;
        
        //fill all other states
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){//shifting
                     prev[j] = prev[j-1]+ prev[j]; 
                }
                else{
                     prev[j] = prev[j] ;
                }
            }
        }
        return (int)prev[m] ;
    }
