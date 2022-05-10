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
    int n ; 
    cin>>n ;
    int maxi = INT_MIN ,mini = INT_MAX, maxS  = INT_MIN, minS = INT_MAX ;
    for(int i=1;i<=n;i++){
        int curr ;
        cin>>curr ;
        if(curr>maxS){ //this is very important, this needs to be > not >=,as same height if found at last, can give more number of swaps.
            maxS = curr ;
            maxi = i ;
        }
        if(curr<=minS){
            minS =curr ;
            mini= i ;
        }
    }
    int ans  = abs(maxi-1) + abs(n-mini) ;
    if(maxi > mini) ans-=1 ;
    cout<<ans ;
    return 0 ;
}
