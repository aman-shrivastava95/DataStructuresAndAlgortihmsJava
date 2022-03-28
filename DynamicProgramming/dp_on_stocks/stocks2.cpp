#include<bits/stdc++.h>
using namespace std  ;

//mulitiple transactions can be made here, in this question
//1 means not holding
//0 means holding,better to write this problem in terms of holding and not holding

long f(int ind, int buy,long * values,int n,vector<vector<long>> &dp){
    if(ind==n) return  0 ;
    if(dp[ind][buy]!=-1)return dp[ind][buy] ;
    long profit = 0 ;
    if(buy){
        profit = max(-values[ind] + f(ind+1,0,values,n,dp),
                0+f(ind+1,buy,values,n,dp)) ;
    }else{
        profit = max(values[ind]+f(ind+1,1,values,n,dp),
                    0+f(ind+1,buy,values,n,dp)) ;
    }
    return dp[ind][buy] = profit ;
}
//memoization.
int getMaxProfit(long *values,int n){
    vector<vector<long>> dp(n,vector<long>(2,-1)) ;
    return f(0,1,values,n,dp) ;
}

//tabulation.
int getMaxProfitTab(long *values,int n){
    vector<vector<long>> dp(n+1,vector<long>(2,0)) ;
    //base case ;
    dp[n][0] = dp[n][1] = 0 ;
    //write the recursion sates in opposite manner
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            //copy pasing the recurences
            long profit = 0 ;
            if(buy){
                profit = max(-values[ind] + dp[ind+1][0],
                            0+dp[ind+1][buy]) ;
                }
            else{
                profit = max(values[ind]+dp[ind+1][1],
                            0+dp[ind+1][buy]) ;
                }
                dp[ind][buy] = profit ;
        }
    }
    return dp[0][1] ;
}
//since we konw that the dcurrent column values depend on  column ahead of it, we can further
//space optimize it
//in leetcode discussion forum people are using 4 different variables, which is same as that.
int getMaxProfitSpaceOptimised(long* values, int n){
     vector<long> ahead(2,0),cur(2,0) ;
    //base case ;
    ahead[0] = ahead[1] = 0 ;
    //write the recursion sates in opposite manner
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            //copy pasing the recurences
            long profit = 0 ;
            if(buy){
                profit = max(-values[ind] + ahead[0],
                            0+ahead[buy]) ;
                }
            else{
                profit = max(values[ind]+ahead[1],
                            0+ahead[buy]) ;
                }
                cur[buy] = profit ;
        }
        ahead = cur ;
    }
    return ahead[1] ;
}

//wrtiting with varialbes and not arrays or vectors
long getMaxProfitVar(long *values, int n){
    long aheadNotBuy, aheadBuy, curBuy, curNotbuy ;
    aheadBuy = aheadNotBuy = 0 ;
    for(int ind =n-1;ind>=0;ind--){
        curNotbuy = max(values[ind] + aheadBuy,0+ aheadNotBuy) ;
        curBuy = max(-values[ind] + aheadNotBuy,0+aheadBuy) ;

        aheadBuy = curBuy ;
        aheadNotBuy = curNotbuy ;
    }
    return aheadBuy ;
}