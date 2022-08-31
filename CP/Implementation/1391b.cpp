#include<bits/stdc++.h>//
#define pb push_back
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
using namespace std ;

int main(int argc, char const *argv[])
{
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    int t ;
    cin>>t ;
    while(t--){ 
        int R, C ,count=0;
        cin>>R>>C ;
        vector<vector<char>> grid(R, vector<char>(C,'C')) ;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                char ch  ;
                cin>>ch ;
                grid[i][j] = ch ;
            }
        }
        //checking the last row
        for(int c = 0;c<C;c++){
            if(grid[R-1][c]=='D')
                count++ ;
        }
        //checking the last column
        for(int r = 0;r<R;r++){
            if(grid[r][C-1]=='R')
                count++ ;
        }
        cout<<count<<'\n' ;
    }
    return 0 ;
}
