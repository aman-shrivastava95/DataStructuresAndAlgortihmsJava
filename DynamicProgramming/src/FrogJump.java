//There is a frog on step1 of a n stair long staircase. The frog wanst to reach the nth stair. The energy required is caludlated as
//from stair i to j is abs(heights[i]-heights[j]).If frog can jump only i+1 and i+2 stairs, find the minimum energy in with he can reach the n stair

public class FrogJump {
    int N ;
    //recursion
    public int findMinEnergy(int index, int[] heights){
        if(index==0) return 0 ;
        int one_step = 0 ;
        int two_step = 0 ;
         one_step  = findMinEnergy(index-1,heights) + Math.abs(heights[index]-heights[index -1]) ;
        if(index -2 >=0)
             two_step  = findMinEnergy(index-2,heights) + Math.abs(heights[index]-heights[index -2]) ;
        return Math.min(one_step,two_step) ;
    }

    //Memozation
    int[] dp = new int[N] ;
    public int findMinEnergyMem(int index, int[] heights){
        if(index==0) return 0 ;
        if(dp[index]!=-1) return dp[index] ;
        int one_step = 0 ;
        int two_step = 0 ;
        one_step  = findMinEnergyMem(index-1,heights) + Math.abs(heights[index]-heights[index -1]) ;
        if(index -2 >=0)
            two_step  = findMinEnergyMem(index-2,heights) + Math.abs(heights[index]-heights[index -2]) ;
        return dp[index] = Math.min(one_step,two_step) ;
    }

    //tabulation
    public int findMinEnergyTab(int N, int[] heights){
        //handle edge cases lke,,if the size of stair is less than equal to 2.
        dp = new int[N] ;
        dp[0] = 0 ;
        dp[1] = Math.abs(heights[1]-heights[0]) ;
        for(int i=2;i<N;i++){
            int one_step = dp[i-1] + Math.abs(heights[i]-heights[i-1]) ;
            int two_step = dp[i-2] + Math.abs(heights[i]-heights[i-2]) ;
            dp[i] = Math.min(one_step,two_step) ;
        }
        return dp[N-1] ;
    }
}













