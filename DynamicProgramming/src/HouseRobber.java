//same as max non adjacent sum , except all the houses are in circle,ie. first and last houses are adjacent
public class HouseRobber {
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
    public int houseRobber (int[] moneyInHouse){
        int n = moneyInHouse.length ;
        int[] temp1 = new int[n-1] ;//exlcluding the last elements
        int[] temp2  = new int[n-1] ;//excluding the first element
        for(int i=0; i<n; i++){
            if(i != n-1) temp1[i] = moneyInHouse[i] ;
            if(i != 0) temp2[i-1] = moneyInHouse[i] ;
        }
        return Math.max(findMaxSumSpaceOptimized(temp1),findMaxSumSpaceOptimized(temp2)) ;
    }
}
