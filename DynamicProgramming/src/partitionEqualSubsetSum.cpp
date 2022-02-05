#include<bits/stdc++.h>
using namespace std ;


//this is the space optimized version.
bool subsetSumK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,0),curr(k+1,0) ;
    prev[0] = curr[0] = true  ;
    if(arr[0]<=k)prev[arr[0]] = true ;
    for(int ind = 1;ind<n;ind++){
        for(int target = 1;target<=k;target++){
            bool not_take  =prev[target] ;
            bool take = false ;
            if(arr[ind]<=target) take = prev[target-arr[ind]] ;
            curr[target] = take || not_take ;
        }
        prev = curr ;
    }
    return prev[k] ;
}

//just divide the total sum by 2 ,, and find the subset sum = total_sum/2 
bool canPartition(int n, vector<int> &arr){
    int total_sum = 0 ;
    for(int i:arr)
        total_sum+=i ;

    if(total_sum%2 != 0) return false ;
    int target = total_sum/2 ;
    return subsetSumK(n,target,arr) ;
}