#include<bits/stdc++.h>
using namespace std; 
//with transaction fee, this can be written in bottom up manner also, copy the recrsion method.
class Solution {
public:
    int f(int i, int hold,vector<int> &prices,int fee,vector<vector<int>> &dp){
        if(i==prices.size()) return 0 ;
        int ans = INT_MIN ;
        if(dp[i][hold]!=-1)return dp[i][hold] ;
        if(hold){
            //skip or sell
             dp[i][hold] =  max(prices[i]-fee + f(i+1,0,prices, fee,dp),f(i+1,hold,prices,fee,dp)) ;
        }else{
            //skip or buy
             dp[i][hold] =  max(-prices[i] + f(i+1,1,prices, fee,dp),f(i+1,hold,prices,fee,dp)) ;
        }
        return dp[i][hold] ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>> dp(n,vector<int>(2,-1)) ;//fill this dp table
        return f(0,0,prices,fee,dp) ;
    }
};