#include<bits/stdc++.h>
using namespace std ;

int mod = 1e9 + 7 ;

// we can space optimized this with prev and curr.
int countSubsetsWithSumK(vector<int> &nums, int k){
    int n = nums.size() ;
    vector<vector<int>> dp(n, vector<int>(k+1, 0)) ;
    
    //base cases ;
    if(nums[0]==0) dp[0][0] = 2 ;//if element is 0, take or not take , 2 cases
    else dp[0][0] =1 ;
    
    if(nums[0]!=0 && nums[0]<=k)dp[0][nums[0]] = 1 ;

    for(int ind=1;ind<n;ind++){
        for(int sum = 0;sum<=k;sum++){
            int not_take = dp[ind-1][sum];
            int take = 0 ;
            if(nums[ind]<=sum) take = dp[ind-1][sum-nums[ind]] ;
            
            dp[ind][sum] = (take + not_take)%mod ;
        }
    }
    return dp[n-1][k] ;   
}
//memoization
int countSubsetWithDiffK(int n, int d, vector<int> &arr){
    int totalSum = 0 ;
    for(auto &it:arr) totalSum+=it ;
    if(totalSum - d < 0 || (totalSum -d)%2 ) return false ;
    return countSubsetsWithSumK(arr, (totalSum-d)/2);

}