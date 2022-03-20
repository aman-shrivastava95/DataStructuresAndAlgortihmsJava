#include<bits/stdc++.h>
using namespace std ;

//code to find the next greater element, a lot of problems are solved from this concetp
//are under histogram is one of the example of this problem.
vector<int> nextGreaterElement(vector<int> &nums){
    int n  = nums.size();
    vector<int> nge(n,0) ;
    stack<int> st ;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] < nums[i]){
            nge[st.top()] = nums[i] ;
            st.pop() ;
        }
        st.push(i) ;
    } 
    return nge ;
}
