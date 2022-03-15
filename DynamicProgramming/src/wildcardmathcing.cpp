#include<bits/stdc++.h>
using namespace std ;

int f(int i, int j, string &pattern,string &text, vector<vector<int>> &dp){
    //base cases
    if(i<0 && j<0) return true ;
    if(i<0 && j>=0) return true ;
    if(j<0 && i>=0){
        for(int ii=0;ii<=i;i++){
            if(pattern[ii]!='*')return false ;
        }
        return true ;
    }
    if(dp[i][j]!=-1) return dp[i][j] ;

    if(pattern[i]==pattern[j] || pattern[i]=='?'){
        return dp[i][j] = f(i-1,j-1,pattern,text,dp) ;
    }
    if(pattern[i]=='*'){
        return dp[i][j] = f(i-1,j,pattern,text,dp) || f(i,j-1,pattern, text,dp) ;
    }
    return dp[i][j] = false ;
}

bool widlcardMatching(string pattern, string text){
    int n = pattern.size() ;
    int m = text.size() ;
    vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    return f(n-1,m-1,pattern, text,dp) ;
}

//doing string shifting to accomodate base cases
bool widlcardMatchingTab(string pattern, string text){
    int n = pattern.size() ;
    int m = text.size() ;
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false)) ;
    
    //base cases; just copy it from the recursion
    dp[0][0] = true ;
    for(int j=1;j<=m;j++) dp[0][j] = false ;
    for(int i=1;i<=n;i++){
        bool flag = true ;
        for(int ii=1;ii<=i;i++){
            if(pattern[ii-1] != '*') {
                flag =  false ;
                break ;
            }
        }
        dp[i][0] = flag ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[i-1]==pattern[j-1] || pattern[i-1]=='?'){//string shifiting here
                 dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[i-1]=='*'){
                 dp[i][j] = dp[i-1][j]|| dp[i][j-1];
            }
            else  dp[i][j] = false ;
        }
    }
    return dp[n][m] ;
}

//space optimized bottom up
bool widlcardMatchingTabSO(string pattern, string text){
    int n = pattern.size() ;
    int m = text.size() ;
    vector<bool> prev(m+1,false),cur(m+1,false) ;

    
    //base cases; just copy it from the recursion
    prev[0] = true ;
    for(int j=1;j<=m;j++) prev[j] = false ;
    
    for(int i=1;i<=n;i++){
        
    }
    for(int i=1;i<=n;i++){
        //cur is the current row/s column
        //and that cur's 0th has to be assigned every time for third base case.
        bool flag = true ;
        for(int ii=1;ii<=i;i++){
            if(pattern[ii-1] != '*') {
                flag =  false ;
                break ;
            }
        }
        cur[0] = flag ;
        for(int j=1;j<=m;j++){
            if(pattern[i-1]==pattern[j-1] || pattern[i-1]=='?'){//string shifiting here
                 cur[j] = prev[j-1];
            }
            else if(pattern[i-1]=='*'){
                 cur[j] = prev[j]|| cur[j-1];
            }
            else  cur[j] = false ;
        }
        prev = cur ;
    }
    return prev[m] ;
}