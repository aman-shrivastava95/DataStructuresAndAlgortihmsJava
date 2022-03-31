#include<bits/stdc++.h>
using namespace std ;
//this is with cooldown
class Solution {
    //recursion with memoization.
    int f(int ind, int buy, vector<int>& prices,vector<vector<int>> &dp){
        
        if(ind>=prices.size()) return 0 ;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy] ;
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+f(ind+1,0,prices,dp),
                      f(ind+1,buy,prices,dp)) ;
        }else{
            return dp[ind][buy] = max(prices[ind]+f(ind+2,1,prices,dp),
                      f(ind+1,buy,prices,dp)) ;
        }
    }
public:
    //tabulation.
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n+2,vector<int>(2,0)) ;//n+2 for handing ind+2 access
        //since base case is 0, won't be writing the base case explicitly
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                //copy the recursion
                if(buy==1){
                     dp[ind][buy] = max(-prices[ind]+dp[ind+1][0], dp[ind+1][buy]) ;
                }else{
                     dp[ind][buy] = max(prices[ind]+dp[ind+2][1], dp[ind+1][buy]) ;
                }   
            }
        }
        return dp[0][1] ;
    }
};