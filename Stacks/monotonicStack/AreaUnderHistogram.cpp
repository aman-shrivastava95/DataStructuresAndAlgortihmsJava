#include<bits/stdc++.h>
using namespace std ;

//very good use of monotonic stack, saving memory also , no need to create sepearate arrays for left and right indices.
//try to visualize this, very good.
int largestRectangleArea(vector<int> & histo){
    stack<int> st ;
    int maxA ;
    int n = histo.size() ;
    //using the logic of monotonic stack.maintaining a monotonically incrasing stack
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || histo[st.top()] >= histo[i])){
            int height = histo[st.top()] ;
            st.pop() ;
            int width ;
            if(st.empty())
                width = i ;
            else
                width = i-st.top()-1 ;
            maxA = max(maxA,height*width) ;
        }
        st.push(i) ;//pushing to maintain the stack in monotonically increasing order.
    }
    return maxA ;
}