#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result ;
        int n =  nums.size() ;
        deque<int> dq  ;
        //process the first k elements
        int i ;
        for(i=0;i<k;i++){
            while(!dq.empty() && nums[dq.front()]<= nums[i])
                dq.pop_front() ;
            dq.push_front(i) ;
        }
        //process rest of the elements 
        for(;i<n;i++){
            result.push_back(nums[dq.back()]);
            //remove all the elements which are not in the current window
            while(!dq.empty() && dq.back() <= abs(i-k))
                dq.pop_back() ;
            while(!dq.empty() && nums[dq.front()]<=nums[i])
                dq.pop_front() ;
            dq.push_front(i) ;
        }
        result.push_back(nums[dq.back()]) ;
        return result ;
    }
};