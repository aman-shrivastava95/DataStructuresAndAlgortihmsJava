#include<bits/stdc++.h>
using namespace std ;

//returns the larget divisible subset.
vector<int> printLis(vector<int>& nums){

    //sort the array first
    sort(nums.begin(),nums.end()) ;
    int n = nums.size() ;
        vector<int> dp(n,1),parent(n) ;
        int maxi=1 , lastIndex= 0; 
        for(int i=1;i<n;i++){
            parent[i] = i ;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 ){
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
        vector<int> lds ;
        lds.push_back(nums[lastIndex]) ;
        while(parent[lastIndex]!=lastIndex){
            
            lastIndex = parent[lastIndex] ;
            lds.push_back(nums[lastIndex]) ;
        }
        reverse(lds.begin(),lds.end()) ;
        return lds ;
}
