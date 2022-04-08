#include<bits/stdc++.h>
using namespace std ;

//this problem is same as LIS, just see what we are comparing.

//to check if the s1  and s1 differ onl by one character.
bool check(string &s1, string &s2){
    if(s1.size()!=s2.size() +1)return false ;
    int first=0 ;
    int second = 0 ;
    while(first < s1.size()){
        if(s1[first]==s2[second]){
            first++ ;
            second++ ;
        }else{
            first++ ;
        }
    }
    if(first ==s1.size() && second == s2.size()) return true ;
    return false ;
}
bool comp(string &s1, string &s2){
    return s1.size() < s2.size() ;
}
int longestIncreasingStringChain(vector<string> &arr){
    //sort the array, starting can be anywhere, sort according to the length
    sort(arr.begin(), arr.end(),comp);
     int n = arr.size() ;
        vector<int> dp(n,1) ;//intially all wil be of length 1 ;dp[i] means, length of lis ending at i
        int lis =1 ;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(arr[i],arr[j])){
                    dp[i] = max(dp[i],1+dp[j]) ;
                }
            }
            lis = max(lis,dp[i]) ;
        }
        return lis ;
}