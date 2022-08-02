#include<bits/stdc++.h>
using namespace std ;

//direction vectors
int dx[] = {1,-1,0,0} ;
int dy[] = {0,0,-1,1} ;

//dfs code
void dfs(int x, int y, int R, int C, vector<vector<int>> &board){
    if(x < 0 || y < 0 || x >= R || y >= C ||board[x][y]==0 || board[x][y] == 2)
        return ;
    
    board[x][y] = 2 ;
    
    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i],R,C,board) ;
    }
}
//this small code counts the number of islands represented by the 1 and 0 matrix
int findIslands(vector<vector<int>> &board){
    int R = board.size() ;
    int C = board[0].size() ;
    int count = 0 ;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]==1){
                dfs(i,j,R,C,board) ;
                count++ ;
            } 
        }
    }
}
int araeUnderHistogram(vector<int> &hist){
    int n = hist.size();
    int maxA = INT_MIN ;
    stack<int> st ;
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || hist[st.top()] >=hist[i])){
            int curr = st.top() ;
            st.pop() ;
            int height = hist[curr] ;
            int width = 1 ;
            if(!st.empty())
                width = abs(i-st.top()-1) ;
            maxA = max(maxA,height*width) ;
        }
        st.push(i) ;
    }
    return maxA ;
}