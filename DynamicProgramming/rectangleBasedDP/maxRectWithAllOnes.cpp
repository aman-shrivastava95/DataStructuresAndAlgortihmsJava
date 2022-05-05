#include<bits/stdc++.h>
using namespace std ;

//very good use of monotonic stack, saving memory also , no need to create sepearate arrays for left and right indices.
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

int maxiMalAreaOfSubmatricesOfAllOnes(vector<vector<int>> &mat, int n, int m){
    vector<int> height(m,0) ;
    int maxArea = 0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) height[j]++ ;
            else height[j] = 0 ;
        }
        int area = largestRectangleArea(height) ;
        maxArea = max(maxArea,area) ;
    }
}