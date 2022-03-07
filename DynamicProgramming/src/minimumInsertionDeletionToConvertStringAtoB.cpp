#include<bits/stdc++.h>
using namespace std ;

//longest common subsequence
int  lcs(string s, string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    //copy the base case
    for(int j=0;j<=m;j++) dp[0][j] = 0 ;
    for(int i=0;i<=n;i++) dp[i][0] = 0 ;
    
    //write dwon the changing parameters in opposite manner
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            //copy the recurrence
                if(s[i-1]==t[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
        }
    }
    return dp[n][m] ;
}
int minimumInsertionDeletionToConvertAtoB(string A, string B){
    return A.length()-lcs(A,B) + B.length()-lcs(A,B) ;
    //can also be written as A.length()+B.length()-2*lcs(A,B) ;
}