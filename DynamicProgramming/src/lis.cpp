#include<bits/stdc++.h>
using namespace std ;

class Solution {
    int f(int idx,int prev,vector<int>& nums, int n,vector<vector<int>> &dp){
        if(idx==n)return 0 ;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1] ;
        int len = 0 + f(idx+1,prev,nums,n,dp) ;
        if(prev==-1 || nums[idx] >nums[prev]){
            len = max(len,1+ f(idx+1,idx,nums, n,dp)) ;
        }
        return dp[idx][prev+1] = len ;
            
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n,vector<int>(n+1,-1)) ;
        return f(0,-1,nums,n,dp) ;
    }
    int lengthOfLISTab(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n,1) ;//intially all wil be of length 1 ;dp[i] means, length of lis ending at i
        int lis =1 ;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],1+dp[j]) ;
                }
            }
            lis = max(lis,dp[i]) ;
        }
        return lis ;
    }
    
};

int printLis(vector<int>& nums){
    int n = nums.size() ;
        vector<int> dp(n,1),parent(n) ;//intially all wil be of length 1 ;
        int maxi=1 , lastIndex= 0; 
        for(int i=1;i<n;i++){
            parent[i] = i ;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] ){
                    if(dp[j]+1 > dp[i]){
                        parent[i] = j ;
                        dp[i] = dp[j]+1 ;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i] ;
                lastIndex  = i ;
            }  
        }
        vector<int> lis ;
        lis.push_back(nums[lastIndex]) ;
        while(parent[lastIndex]!=lastIndex){
            
            lastIndex = parent[lastIndex] ;
            lis.push_back(nums[lastIndex]) ;
        }
        reverse(lis.begin(),lis.end()) ;
        for(auto num: lis){
            cout<<num<<" " ;
        }
        cout<<endl ;
        return maxi ;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,4,11,1,16,8} ;
    printLis(nums) ;
}
