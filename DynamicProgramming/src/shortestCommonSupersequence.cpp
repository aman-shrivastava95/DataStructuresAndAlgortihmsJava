#include<bits/stdc++.h>
using namespace std ;
//QUESTION: Find the shortest string that can be formed from string A and B, such that it contains both A 
//and B as its subsequence.

int shortestCommonSupersequence(string s, string t){
    //first of all find the LCS of both the string.
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
     int lcs_s_t = dp[n][m] ;
     //lenght of shortest Common supersequence
     int len_scs = s.length() + t.length() - lcs_s_t ;
     //pring the shortest common supersequence, we will use the dp tabel, the way we did while printing LCS
     int i =n,j = m ;
     string ans = "" ;
     while(i>0 && j>0){
         if(s[i-1]==t[j-1]){
             ans+=s[i-1] ;
         }else if(dp[i-1][j]>dp[i][j-1]){
             ans+=s[i-1] ;
             i-- ;
         }else{
             ans+=t[j-1] ;
             j-- ;
         }
     }
     //if anything is left over appand that
     while(i>0){
         ans+=s[i-1] ;
         i-- ;
     }
    while(j>0){
         ans+=t[j-1] ;
         j-- ;
     }
     reverse(ans.begin(),ans.end()) ;
     cout<<ans<<endl ;
     return len_scs ;
}
