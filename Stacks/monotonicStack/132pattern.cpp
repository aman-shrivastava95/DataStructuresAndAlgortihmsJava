#include<bits/stdc++.h>
using namespace std ;
//if you think about it, this is for every current element, what is the right smaller element which is closest to the current element ;

bool find132Pattern(vector<int> &nums){
    int n = nums.size() ;
    stack<int> st ;
    int potentialThird = INT_MIN ;
    for(int i = n-1;i>=0 ;i--){
        if(!st.empty() && nums[i] < potentialThird) return true ;
        while(!st.empty() && st.top() < nums[i]){
            potentialThird = st.top() ;
            st.pop() ;
        }
        st.push(nums[i]) ;
    }
    return false ;
}
//there is a nlogn appraoch also for this, where we maintain what is the minimum numver till that point, and a ds Treeset which can give me 
// all the lowers on the right. check that also.