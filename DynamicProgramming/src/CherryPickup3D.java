//problem statement
//there is a grid (R * C )where every cell contains some cherries
//Alice is at (0,0), bob is at (0,C-1), they start moving down simultaneously (i+1,j-1),(i+1,j),(i+1,j+1)
//find the maximum number of cherries they can collect together.

import java.util.Arrays;
import java.util.Vector;

//OBSERVATIONS
//they will reach the last row simultaneously
//for every step alice takes, there can be 3 different steps for bob, so in total 9 steps. This is the crux of the problem
public class CherryPickup3D {
    //Memoization
    private int maxCherries(int i, int j1, int j2,int R, int C, int[][] grid,int[][][] dp){
        //out of bounds
        if(j1 < 0 || j2 < 0 || j1 > C-1 || j2 > C-1)
            return (int) -1e8;//large negative number since we are taking max in further steps
        //reached destination
        if(i== R-1){
            if(j1 == j2) return grid[i][j1] ;
            else return grid[i][j1]+ grid[i][j2] ;
        }
        if(dp[i][j1][j1] != -1) return dp[i][j1][j2] ;
        //explore all the paths (dj1->chanege in alice column, dj2->change in bob;s column)
        int maxi = (int) -1e8;
        for(int dj1=-1 ;dj1<=1;dj1++){
            for(int dj2=-1 ;dj2<=1;dj2++){
                int value = 0 ;
                if(j1 == j2) value = grid[i][j1] ;
                else value = grid[i][j1] + grid[i][j2] ;
                value+=maxCherries(i+1,j1+dj1,j2+dj2,R,C,grid,dp) ;
                maxi = Math.max(maxi,value) ;

            }
        }
        return  dp[i][j1][j2] = maxi ;
    }
    public int findMaxCherries(int[][] grid, int R, int C){
        //i->row change will be same for both, as they are both moving down
        //j1->alice's column change (initially 0)
        //j2->bob's column change (intially C-1)
        int[][][] dp =  new int[R][C][C] ;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        return maxCherries(0,0,C-1,R,C,grid,dp) ;
    }

    //tabulation (this can be further sapace optimized to 2d ,, front and curr. with only j1 and j2)
    public int findMaxCherriesTab(int[][] grid, int R, int C){
        int[][][] dp =  new int[R][C][C] ;
        for(int i=0;i<R;i++) {
            for (int j = 0; j < C; j++) {
                Arrays.fill(dp[i][j], 0);
            }
        }
        //base case, i.e  last row,i is same, so there is multiple combination of j1 and j2
        for(int j1=0; j1<C; j1++){
            for(int j2=0; j2<C; j2++){
                if(j1==j2) dp[R-1][j1][j2] = grid[R-1][j1] ;
                else dp[R-1][j1][j2] = grid[R-1][j1] + grid[R-1][j2] ;
            }
        }
        //fill the remaining cells in dp array
        for(int i=R-1; i>=0;i--){
            for(int j1=0; j1<C; j1++){
                for(int j2 = 0; j2<C; j2++){
                    //just change the recuursion bits and you wll get the bottom up tabulation
                    int maxi = (int) -1e8;
                    for(int dj1=-1 ;dj1<=1;dj1++){
                        for(int dj2=-1 ;dj2<=1;dj2++){
                            int value = 0 ;
                            if(j1 == j2) value = grid[i][j1] ;
                            else value = grid[i][j1] + grid[i][j2] ;
                            if(j1+dj1 >=0 && j1+dj1 < C && j2+dj2 >= 0 && j2+dj2 < C)// boundry conditions for index out of bound.
                                value+=dp[i+1][j1+dj1][j2+dj2] ;
                            else
                                value+=(int)-1e8 ;
                            maxi = Math.max(maxi,value) ;

                        }
                    }
                    dp[i][j1][j2] = maxi ;
                }
            }
        }
        return dp[0][0][C-1] ;
    }
}
