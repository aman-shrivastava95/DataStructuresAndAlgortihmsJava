import java.util.Arrays;

//you are given an array of n elements, find the maximum sum of all subsequence with constraint that no tow elements are adjacent
public class MaxNonAdjacentSum {

    private int maxSum(int index, int[] arr,int[] dp){
        if(index == 0) return arr[0] ;
        if(index < 0) return  0 ;
        if(dp[index]!=-1)return dp[index] ;
        //pick/not pick
        int pick = arr[index] + maxSum(index - 2,arr,dp) ;
        int notPick = maxSum(index - 1, arr,dp);
        return dp[index] = Math.max(pick,notPick) ;
    }
    //using memoization here
    public int findMaxSum(int[] arr){
        int[] dp = new int[arr.length] ;
        Arrays.fill(dp, -1);
        return maxSum(arr.length -1,arr,dp) ;
    }
    //using tabulation method
    public int findMaxSumTab(int[] arr){
        int N  = arr.length ;
        int[] dp =  new int[N] ;
        dp[0] = arr[0] ;//only option is to pick
        for (int i = 1; i < N; i++) {
            int pick = arr[i];
            if(i-2>=0)
                pick += dp[i-2];
            int notPick = 0 + dp[i-1] ;
            dp[i] = Math.max(pick,notPick) ;
        }
        return dp[N-1] ;
    }
    //using space optimized method,, we only need previos two states
    public  int findMaxSumSpaceOptimized(int[] arr){
        int N = arr.length ;
        int prev1 = arr[0];
        int prev2 = 0 ;
        for(int i=1; i<N; i++){
            int take = arr[i] ;
            if(i>=2) take+=prev2 ;
            int notTake = prev1;
            int curi = Math.max(take, notTake) ;
            prev2 = prev1 ;
            prev1 = curi ;
        }
        return prev1 ;
    }
}








