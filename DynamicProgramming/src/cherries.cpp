#include<bits/stdc++.h>
using namespace std ;

//simple recursive implementatoin.
int cherries(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid){
    if(j1 <0 || j2 < 0 || j1 > c-1 || j2 > c-1)
        return -1e9 ;
    if(i == r-1){
        if(j1==j2) return grid[i][j1] ;
        else return grid[i][j1] + grid[i][j2] ;
    }
    //explore all the possiblites
    int maxi = -1e9 ;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value = 0  ;
            if(j1==j2) value = grid[i][j1] ;
            else value = grid[i][j1] + grid[i][j2] ;
            maxi = max(maxi,cherries(i+1,j1+dj1,j2+dj2,r,c,grid)) ;
        }
    }
    return maxi ;
}


int getMaxCherries(int R, int C, vector<vector<int>> &grid){
    return cherries(0,0,C-1,R,C,grid) ;
}
int main(int argc, char const *argv[])
{
    cout<<"hello world" ;
    return 0;
}
