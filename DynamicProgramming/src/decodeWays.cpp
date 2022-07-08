#include<bits/stdc++.h>
using namespace std ;

class Solution{
    int f(int i,int n, string s,vector<int> &dp){
        if(i>=n) return 0 ;
        if(s[i]=='0') return 0 ;
        
        if(dp[i]!=-1)return dp[i] ;
        
        int take1 = f(i+1,n,s,dp) ;
        int take2 = 0 ;
        if(i+1<n){
            int num=stoi(s.substr(i,2)) ;
            if(num>=10 && num<=26)
                take2 = f(i+2,n,s,dp) ;
        }
        return dp[i] = take1 + take2 ;
    }
    public :
    int decodeWays(string s){
        int n = s.size() ;
        vector<int> dp(n, -1) ;
        return f(0,n,s,dp) ;
    }
    
    int decodeWaysTab(string s){
        int n = s.size() ;
        vector<int> dp(n+1,0) ;
        dp[n]=1 ;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i] = 0 ;
            else{
                int take1 = dp[i+1];
                int take2 = 0 ;
                if(i+1<n){
                    int num=stoi(s.substr(i,2)) ;
                    if(num>=10 && num<=26)
                        take2 = dp[i+2] ;
                }
             dp[i] = take1 + take2 ;
            }
        }
        return dp[0] ;
    }
    
};