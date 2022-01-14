//similar to frog jump but instead of two jump,, k jump are allowed
public class FrogJumpKdist {
    int N ;
    //normal recursion
    public  int findMinEnergy(int index, int[] heights, int k){
        if(index==0) return 0 ;

        //try all k steps
        int minEnergy  = Integer.MAX_VALUE ;
        for(int j=1;j<=k;j++){
            int jumpEnergy = findMinEnergy(index - j,heights,k) + Math.abs(heights[index]-heights[index-j]) ;
            minEnergy = Math.min(minEnergy,jumpEnergy) ;
        }
        return minEnergy ;
    }
    //memoized
    int[] dp = new int[N] ;
    public  int findMinEnergyMem(int index, int[] heights, int k){
        if(index==0) return 0 ;
        if(dp[index]!=-1) return dp[index] ;
        //try all k steps
        int minEnergy  = Integer.MAX_VALUE ;
        for(int j=1;j<=k;j++){
            int jumpEnergy = findMinEnergyMem(index - j,heights,k) + Math.abs(heights[index]-heights[index-j]) ;
            minEnergy = Math.min(minEnergy,jumpEnergy) ;
        }
        return dp[index] = minEnergy ;
    }
    //tabulation
    public int findMinEnergyTab(int[] heights, int k){
        dp =  new int[N] ;
        dp[0] =0 ;
        for(int i=1; i<N; i++){
            int minEnergy = Integer.MAX_VALUE ;
            for(int j = 1 ;j<=k ;j++){
                if(i-j>=0)
                    minEnergy = Math.min(minEnergy, dp[i-j] + Math.abs(heights[i]-heights[i-j])) ;
            }
            dp[i] = minEnergy ;
        }
        return dp[N-1] ;
    }
}




