#include<bits/stdc++.h>
using namespace std ;

//tabulation. (this can be space optimized further with prev and cur)
int lcsTab(string s, string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    //copy the base case
    for(int j=0;j<=m;j++) dp[0][j] = 0 ;
    for(int i=0;i<=n;i++) dp[i][0] = 0 ;
    
    int ans = 0 ;
    //write dwon the changing parameters in opposite manner
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            //copy the recurrence
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                    ans =  max(ans,dp[i][j]) ;
                }
                else 
                    dp[i][j] = 0 ;//the change from longest common susequence.
        }
    }
    cout<<ans<<endl;
    return ans ;
}