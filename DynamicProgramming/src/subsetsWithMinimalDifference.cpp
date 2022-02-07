#include<bits/stdc++.h>
using namespace std; 
 



 // using the last row of subset sum = k tabulation for this solution
 int minSubsetSumDifferece(vector<int> &nums){
     //maximum possible sum in a subset will be if all the value of subset is there, if negative ,,then that needs to be handled
     int k = 0 ;
     for(int num:nums){
         k+=num ;
     }
     int total_sum = k ;
     int n = nums.size() ;
     vector<vector<bool>>dp(n,vector<bool>(k+1,0)) ;
     //base case  
     for(int i = 0;i<n;i++){
         dp[i][0] = true ;
     }
     if(nums[0]<=k)dp[0][nums[0]] = true ;
     for(int ind=1;ind<n;ind++){
         for(int target = 1;target<=k;target++){
             bool not_take = dp[ind-1][target] ;
             bool take = false ;
             if(nums[ind] <=target)take  = dp[ind-1][target-nums[ind]] ;
             dp[ind][target]  = take || not_take ;
         }
     }
     //now we need to check the last row and find the minimum abs ;
     int mini = 1e9 ;
     for(int s1 = 0;s1<=total_sum/2;s1++){
         if(dp[n-1][s1]==true){
             mini = min(mini,abs((total_sum-s1)-s1)) ;
         }
     }
     return mini ;
 }
 //this is a recursive solution which works,but is expensive,, we are basically checking every possible subset.
void f(int ind,int sum1, int sum2,int n, int &result,vector<int> &nums){
    if(ind==0){
        result = min(result, min(abs(sum1+nums[ind] - sum2),abs(sum2 + nums[ind] -sum1))) ;
        return ;
    }
    //put in first set
    f(ind-1,sum1+nums[ind],sum2,n,result,nums) ;
    //put in second set
    f(ind-1,sum1,sum2+nums[ind],n,result,nums) ;
}

int minimumSubsetSumDifference(vector<int> &nums){
    int result = INT_MAX ;
    int n = nums.size() ;
    int sum1 = 0,sum2 =0 ;
    f(n-1,sum1, sum2, n, result,nums) ;
    return result ;
}
int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4} ;
    cout<<"the answer is: "<<minimumSubsetSumDifference(v) ;
    return 0;
}
