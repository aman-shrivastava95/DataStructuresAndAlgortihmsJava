#include<bits/stdc++.h>
using namespace std ;

//memoization.
int cherries(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    //out of bounds case
    if(j1 <0 || j2 < 0 || j1 > c-1 || j2 > c-1)
        return -1e9 ;

    //base case, reached last column    
    if(i == r-1){
        if(j1==j2) return grid[i][j1] ;
        else return grid[i][j1] + grid[i][j2] ;
    }

    //check if this is already calulated
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2] ; 
    //explore all the possibilities
    int maxi = -1e9 ;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value = 0  ;
            if(j1==j2) value = grid[i][j1] ;
            else value = grid[i][j1] + grid[i][j2] ;
            maxi = max(maxi,cherries(i+1,j1+dj1,j2+dj2,r,c,grid,dp)) ;
        }
    }
    //store before returning
    return dp[i][j1][j2]  = maxi ;
}


int getMaxCherries(int R, int C, vector<vector<int>> &grid){
    //this is how we initialize 3d vector to a given value in cpp
    vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(C,-1))) ;
    return cherries(0,0,C-1,R,C,grid,dp) ;
}
//tabulation method
int maxCherries(int r, int c, vector<vector<int>> &grid){
    //create table to be filled
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,0))) ;
    
    //fill the base case that is last row for different values of j1 and j2
    for(int j1=0; j1<c; j1++){
        for(int j2=0; j2<c; j2++){
            if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1] ;
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2] ;
        }
    }
    //fill all other rows in bottom up fashion
    for(int i=r-2; i>0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                //just copy the recursion code and modify some of the bits
                int maxi = -1e9 ;
                //this is just 9 combinations here [-1,0,1]*[-1,0,1] 
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int value = 0  ;
                        if(j1==j2) value = grid[i][j1] ;
                        else value = grid[i][j1] + grid[i][j2] ;
                        maxi = max(maxi,dp[i+1][j1+dj1][j2+dj2]); 
                    }
                }
                dp[i][j1][j2]  = maxi ;
            }
        }
    }
    //return the answer in this fashion
    return dp[0][0][c-1] ;
}

int main(int argc, char const *argv[])
{
    cout<<"hello world" ;
    return 0;
}
















