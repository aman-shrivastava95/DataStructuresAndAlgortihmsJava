#include<bits/stdc++.h>
using namespace std ;

class Solution {
    int f(int i, int j ,vector<int> &cuts,vector<vector<int>> &dp){
       if(i > j) return 0 ;
        if(dp[i][j]!=-1)return dp[i][j] ;
        int curLength = cuts[j+1] - cuts[i-1] ;//this works  because we have added 0 and length of the rod at last.
        int mini = INT_MAX ;
        for(int ind=i;ind<=j;ind++){
            int cost = curLength +f(i, ind-1,cuts,dp) + f(ind+1,j,cuts,dp) ;
            mini = min(mini,cost) ;
        }
        return dp[i][j] = mini ;
    }
public:
    //memoization
    int minCost(int n, vector<int>& cuts) {
        int c =cuts.size() ;
        //this needs to be soerted in order to subproblems to be solved indpendently.
        sort(cuts.begin(),cuts.end()) ;
        //this additions help in calcuating the length of the rod easily.
        cuts.insert(cuts.begin(),0) ;//0 at the front
        cuts.push_back(n) ; //length of stick at the back 
        vector<vector<int>> dp(c+1, vector<int>(c+1,-1)) ;

        return f(1,c, cuts,dp) ; //[0,1,2,4,5,7]  //the vector is changed now so sending from 1 to c
    }
    //tabulation
    int minCostTab(int n, vector<int>& cuts) {
            int c =cuts.size() ;
            sort(cuts.begin(),cuts.end()) ;
            cuts.insert(cuts.begin(),0) ;//0 at the front
            cuts.push_back(n) ; //length of stick at the back 
            vector<vector<int>> dp(c+2, vector<int>(c+2,0)) ;//ind going to ind+1

            for(int i=c;i>=1;i--){
                for(int j=1;j<=c;j++){
                    if(i>j) continue ;//no need for this base case, as already every thing is set to 0
                    int curLength = cuts[j+1] - cuts[i-1] ;
                    int mini = INT_MAX ;
                    for(int ind=i;ind<=j;ind++){
                        int cost = curLength + dp[i][ind-1] +dp[ind+1][j];
                        mini = min(mini,cost) ;
                    }
                    dp[i][j] = mini ;
                }
            }
            return dp[1][c] ;
        }
};