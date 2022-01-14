//count total number of ways to reach from ground to n stairs , if only one or two steps can be taken from any step
public class climbStairs {
    public int findAllWays(int n){
        if(n==0 || n==1 ) return n ;
        int one_step = findAllWays(n-1) ;
        int two_step = findAllWays(n-2) ;
        return one_step + two_step ;
        //this is same as fibonacci, can be memoized like that
    }
    public int findAllWaysTab(int n){
        int[] dp = new int[n+1] ;
        dp[0] = 0 ;
        dp[1] = 1 ;
        for(int i=2 ;i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        return dp[n] ;
    }
}
