#include<bits/stdc++.h>
using namespace std ;

//bottom up dp appraoch
int countSquareSubmatricesWithAllOnes(int n, int m, vector<vector<int>> &arr){
    //declare the dp array
    vector<vector<int>> dp(n, vector<int>(m,0)) ;
    //base cases
    for(int j=0;j<m;j++)dp[0][j] = arr[0][j] ;
    for(int i=0;i<n;i++)dp[i][0] = arr[i][0] ;
    //fill rest of the cases
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==1){
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) ;
            }else{
                dp[i][j] = 0 ;
            }
        }
    }
    //sum them all up
    int count=0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            count+=dp[i][j] ;
        }
    }
    return count ;
}