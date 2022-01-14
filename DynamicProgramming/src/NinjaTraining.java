import java.util.Arrays;

//ninja required to complete training,
//3 taks
//cannot do mulltiple tasks on same day
//find maximumPointsThatCanBeEarned

public class NinjaTraining {
    //this is the memoized version.
    int[][] dp ;
    private  int maxPoints(int day, int last,int[][] points){
        //base condition
        if(day == 0){
            int maxi=0 ;
            for(int task=0; task< 3;task++){
                if(task != last)
                    maxi = Math.max(maxi,points[0][task]) ;
            }
            return maxi ;
        }
        if(dp[day][last] !=-1) return dp[day][last] ;
        int maxi = 0 ;
        for (int task = 0; task < 3; task++) {
            if(task!=last)
                maxi = Math.max(maxi, points[day][task] + maxPoints(day-1,task,points)) ;
        }
        return dp[day][last] = maxi ;

    }
    public int ninjaTraining(int n, int[][] points){
        dp = new int[n][4] ;
        //fill dp table with -1 ;
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return maxPoints(n-1,3,points) ;
    }
    public int ninjaTrainingBottomUp(int n, int[][] points){
        dp = new int[n][4] ;//dp is of [day][last]
        //base case,fillig the first row of the dp table
        dp[0][0] = Math.max(points[0][1],points[0][2]) ;
        dp[0][1] = Math.max(points[0][0],points[0][2]) ;
        dp[0][2] = Math.max(points[0][0],points[0][1]) ;
        dp[0][3] = Math.max(points[0][0],Math.max(points[0][1],points[0][2])) ;

        for(int day=1 ;day<n; day++){
            for(int last=0;last< 4;last++){
                dp[day][last] =  0 ;
                for(int task=0;task<3;task++){
                    if(task!=last)
                        dp[day][last] =Math.max(dp[day][last],points[day][task] + dp[day-1][task]) ;
                }
            }
        }
        return dp[n-1][3] ;
    }
    //TODO: space optimized version
    public int ninjaTrainingBottomUpSpaceOptimized(int n, int[][] points){
        int[] prev = new int[4] ;//dp is of [day][last]
        //base case,fillig the first row of the dp table
        prev[0] = Math.max(points[0][1],points[0][2]) ;
        prev[1] = Math.max(points[0][0],points[0][2]) ;
        prev[2] = Math.max(points[0][0],points[0][1]) ;
        prev[3] = Math.max(points[0][0],Math.max(points[0][1],points[0][2])) ;

        for(int day=1 ;day<n; day++){
            int[] temp =  new int[4] ;
            for(int last=0;last< 4;last++){
                temp[last] =  0 ;
                for(int task=0;task<3;task++){
                    if(task!=last)
                        temp[last] =Math.max(prev[last],points[day][task] + prev[task]) ;
                }
            }
            prev = temp ;
        }
        return prev[3] ;
    }
}








