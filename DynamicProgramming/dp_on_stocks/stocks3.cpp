#include<bits/stdc++.h>
using namespace std ;
//atmost 2 transactions.

int f(int ind, int buy, int cap, vector<int> &prices, int n,vector<vector<vector<int>>> &dp){
    if(ind==n || cap==0) return 0 ;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap] ;
    if(buy==1){
        return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp),0+f(ind+1,1,cap,prices,n,dp)) ;
    }
        return dp[ind][buy][cap] = max(prices[ind] +f(ind+1,1,cap-1,prices, n,dp), 0+f(ind+1,0,cap,prices,n,dp)) ;
}
//memoization.
int maxProfit(vector<int> &prices, int n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3,-1))) ;
    return f(0,1,2,prices, n, dp) ;
}

//tabulation 
int maxProfit(vector<int> &prices, int n){
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3,0))) ;
    //since the base cases are already 0 , there is no point writing it explicitly
    for(int ind = n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){//since cap =0 will be 0, from the base case.
                if(buy==1){
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],0+dp[ind+1][1][cap]) ;
                }else
                    dp[ind][buy][cap] = max(prices[ind] +dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]) ;
            }
        }
    }
    return dp[0][1][2] ;
}

//tabulation space optimized
int maxProfitSO(vector<int> &prices, int n){
    //2*3 is a 6 sized constant array
    vector<vector<int>> after(2, vector<int>(3,0)) ;
    vector<vector<int>> cur(2, vector<int>(3,0)) ;

    //since the base cases are already 0 , there is no point writing it explicitly
    for(int ind = n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){//since cap =0 will be 0, from the base case.
                if(buy==1){
                    cur[buy][cap] = max(-prices[ind] + after[0][cap],0+after[1][cap]) ;
                }else
                    cur[buy][cap] = max(prices[ind] +after[1][cap-1], 0+after[0][cap]) ;
            }
        }
        after  = cur ;
    }
    return after[1][2] ;
}

//another recursion n*4 (bsbs will be 4 ) and this can also be memoized and done.
int f(int ind, int transaction,vector<int> &prices, int n){
    if(ind==n || transaction==4) return 0 ;
    if(transaction%2==0){
        //meaning can buy , that is one selling is done
        return max(-prices[ind] + f(ind+1,transaction+1, prices, n),0+f(ind+1,transaction,prices,n)) ;
    }
    return max(prices[ind] + f(ind+1,transaction+1, prices, n),0+f(ind+1,transaction,prices,n)) ;
}