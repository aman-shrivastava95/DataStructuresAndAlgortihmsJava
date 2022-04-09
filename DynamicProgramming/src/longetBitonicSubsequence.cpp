#include<bits/stdc++.h>
using namespace std;

//calculate lis from front, calculate lis from back, and find bitonic by summing them -1
int longestBitonicSubsequence(vector<int> &arr, int n){

    //find the lis from front ending at element i
    vector<int> dp1(n,1) ;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<1;prev++){
            if(arr[prev] < arr[i]){
                dp1[i] = max(dp1[i],dp1[prev]+1) ;
            }
        }
    }
    //find lis from the back where dp i is lis ending at i
    vector<int> dp2(n,0);
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev] < arr[i]){
                dp2[i] = max(dp2[i],dp2[prev]+1) ;
            }
        }
    }
    //maximize the bitonic
    int maxi = 0 ;
    for(int i=0;i<n;i++){
        maxi = max(maxi, dp1[i] + dp1[i] -1) ;
    }
    return maxi ;
}