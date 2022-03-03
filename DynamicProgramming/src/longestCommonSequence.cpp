#include<bits/stdc++.h>
using namespace std ;


int f(int i, int j, string &s, string &t,vector<vector<int>> &dp){
    if( i<0 || j<0)
        return 0;
    
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i]==t[j]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp) ;
    return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)) ;
}
//memoization
int lcs(string s, string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n, vector<int>(m,-1)) ;
    return f(n-1,m-1,s,t,dp) ;
}

//let's shift the index and write the recursion 
int fShift(int i, int j, string &s, string &t,vector<vector<int>> &dp){
    if( i==0 || j==0)//base case changed due to recursion
        return 0;
    
    if(dp[i][j] != -1) return dp[i][j] ;
    
    if(s[i-1]==t[j-1]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp) ;
    return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)) ;
}
//memoization
int lcsShift(string s, string t){
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1)) ;
    return f(n,m,s,t,dp) ;
}

//tabuliation
int lcsTab(string s, string t){
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
    //printing the LCS
    int len = dp[n][m] ;
    string ans = "" ;
    for(int i=0;i<len;i++){
        ans+='$' ;
    }
    int index = len-1; 
    int i=n,j=m ;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index] = s[i-1] ;
            index-- ;
            i--;
            j-- ;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i-- ;
        }else{
            j-- ;
        }
    }
    cout<<ans<<endl;
    
    return dp[n][m] ;
}

//space optimized
int lcs(string s, string t){
    int n = s.size() ;
    int m  =t.size() ;
    vector<int> prev(m+1,0),cur(m+1,0) ;
    
    for(int j=0;j<m;j++) prev[j] = 0 ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                cur[j] = 1 + prev[j-1] ;
            else
                cur[j] = max(prev[j],cur[j-1]) ;
        }
        prev = cur ;
    }
    return prev[m] ;
}